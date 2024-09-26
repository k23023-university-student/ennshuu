package jp.ac.ait.k23023;

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
    double AIT_KEIDO = 137.1130419;
    double AIT_IDO = 35.1834122;

    private static final String[] FILES_LIST = {
            "./files/c200326.csv",
            "./files/c200328.csv",
            "./files/c200329.csv",
            "./files/c200330.csv",
            "./files/c200361.csv",
            "./files/c200362.csv",
            "./files/c200363.csv",
            "./files/c200364.csv"
    };

    //出力データの形式
    private record OutDataCols(
            BigDecimal ido,
            BigDecimal keido,
            BigDecimal distance,
            String name
    ){}

    private record Point(
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
        return Math.sqrt(Math.pow((AIT_IDO - doubleIdo), 2) + Math.pow((AIT_KEIDO - doubleKeido), 2));
    }

    public List<OutDataCols> readFiles(String filePath){
        List<OutDataCols> result = new ArrayList<>();
        try(Scanner sc = new Scanner(Files.newBufferedReader(Path.of(filePath), Charset.forName("ms932")))) {
            sc.nextLine(); //ヘッダー行はなし

            while (sc.hasNextLine()){
                String lineString = sc.nextLine();
                String[] fields = lineString.split(",");
                String point = fields[1]; //座標

                String name;
                if (filePath.contains("c200328")) {
                    name = fields[2];
                } else if (filePath.contains("c200326") || filePath.contains("c200329") || filePath.contains("c200330")) {
                    name = fields[3];
                } else if (filePath.contains("c200361")) {
                    name = fields[4];
                } else {
                    name = fields[5];
                }

                Point pointObj = parsePoint(point);
                BigDecimal distance = new BigDecimal(getDistance(pointObj));
                result.add(new OutDataCols(pointObj.ido(), pointObj.keido(), distance, name));
            }

        } catch (IOException e){
            throw new UncheckedIOException(e);
        }
        return result;
    }

    public static void main(String[] args){
        AichiTouristSpot aichi = new AichiTouristSpot();
        List<OutDataCols> data = new ArrayList<>();

        for(String file : FILES_LIST){
            data.addAll(aichi.readFiles(file));
        }

        data.sort(Comparator.comparing(OutDataCols::distance));

        try(BufferedWriter bw = Files.newBufferedWriter(Path.of("./out.csv"))) {
            for(OutDataCols dc : data){
                bw.write(String.format("%s,%s,%s,%s", dc.ido(), dc.keido(), dc.distance(), dc.name()));
                bw.newLine();
            }
        } catch (IOException e){
            throw new UncheckedIOException(e);
        }
    }
}
