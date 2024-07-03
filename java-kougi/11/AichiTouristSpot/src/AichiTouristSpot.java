import java.io.BufferedWriter;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.math.BigDecimal;

import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class AichiTouristSpot {
    double AIT_KEIDO = 137.1130419;//型が統一されていないので注意
    double AIT_IDO = 35.1834122;//型が統一されていないので注意
    private enum FilesList {
        c200326("./c200326.csv"),
        c200328("./c200328.csv"),
        c200329("./c200329.csv"),
        c200330("./c200330.csv"),
        c200361("./c200361.csv"),
        c200362("./c200362.csv"),
        c200363("./c200363.csv"),
        c200364("./c200364.csv");

        private String path;
        FilesList(String path) {
            this.path = path;
        }

        public String getPath() {
            return path;
        }
    }
    //出力データの形式
    private record OutDataCols(
            BigDecimal ido,
            BigDecimal keido,
            BigDecimal distance,
            String name
    ){}

    private  record Point(
          BigDecimal ido,
          BigDecimal keido
    ){}

    private Point parsePoint(String pointString){
        //Pointの装飾データを削除するコード

        String keido = pointString.split(" ")[0];
        keido = keido.replace("POINT(","");
        String ido = pointString.split(" ")[1];
        ido = ido.replace(")","");
        BigDecimal bigDecKeido = new BigDecimal(keido);
        BigDecimal bigDecIdo = new BigDecimal(ido);
        return new Point(bigDecIdo,bigDecKeido);
    }

    private double getDistance(Point p){


        double doubleIdo = p.ido().doubleValue();

        double doubleKeido = p.keido().doubleValue();
        double returnValue = Math.sqrt(Math.pow((AIT_IDO-doubleIdo),2) + Math.pow((AIT_KEIDO-doubleKeido),2));
        return returnValue;

    }

    public List<OutDataCols> readFiles(FilesList enumCols){
        List<OutDataCols> result = new ArrayList<OutDataCols>();
        try(Scanner sc =
                    new Scanner(Files.newBufferedReader(Path.of(enumCols.getPath()), Charset.forName("ms932"))
                    )) {

            sc.nextLine();//ヘッダー行はなし

            while (sc.hasNextLine()){

                String lineString = sc.nextLine();

                String[] fields = lineString.split(",");
                String point = fields[1];//座標
                String name = switch (enumCols) {
                    case c200328 -> fields[2];
                    case c200326, c200329, c200330 -> fields[3];
                    case c200361 -> fields[4];
                    case c200362, c200363, c200364 -> fields[5];
                };

                Point pointObj = parsePoint(point);

                BigDecimal distance = new BigDecimal(getDistance(pointObj));
                result.add(new OutDataCols(pointObj.ido(),pointObj.keido(),distance,name));
            }

        }catch (IOException e){

            throw new UncheckedIOException(e);
        }
        return result;
    }




    public static void main(String[] args){

        AichiTouristSpot aichi = new AichiTouristSpot();
        List<OutDataCols> data = new ArrayList<OutDataCols>();
        for(FilesList file : FilesList.values()){

            data.addAll(aichi.readFiles(file));

        }

//        data.sort(new Comparator<OutDataCols>() {
//            @Override
//            public int compare(OutDataCols o1, OutDataCols o2) {
//                return o1.distance().subtract(o2.distance()).doubleValue() < 0 ? -1 : 0;
//            }
//        });
        data.sort(Comparator.comparing(OutDataCols::distance));
        try(BufferedWriter bw = Files.newBufferedWriter(Path.of("./out.csv"))) {


            for(OutDataCols dc : data){
                bw.write(String.format("%s,%s,%s,%s",dc.ido(),dc.keido(),dc.distance(),dc.name()));
                bw.newLine();
            }

        }catch (IOException e){

            throw new UncheckedIOException(e);
        }
    }

}
