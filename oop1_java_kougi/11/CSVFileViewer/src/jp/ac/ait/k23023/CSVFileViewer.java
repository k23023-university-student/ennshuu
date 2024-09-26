package jp.ac.ait.k23023;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
import java.util.Scanner;
import java.io.IOException;
public class CSVFileViewer {

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("ファイルパスの入力> ");
        String path = in.nextLine();
        if(!Files.exists(Path.of(path))){
            System.out.println("ファイルが見つかりません");
            return;
        }
        try(Scanner fileIn = new Scanner(Files.newBufferedReader(Path.of(path)))) {
            int count = 1;
            while (fileIn.hasNextLine()) {


                String line = fileIn.nextLine();
                String[] record = line.split(",");
                System.out.printf("%d:",count);

                for(int i=0;i<record.length;i++){

                    System.out.printf("\t%d:\t%s",i+1,record[i]);

                }
                System.out.println();
                count++;
            }
        }catch (IOException e){
            throw new UncheckedIOException(e);
        }
    }
}
