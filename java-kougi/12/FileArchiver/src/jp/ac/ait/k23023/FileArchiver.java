package jp.ac.ait.k23023;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.zip.*;
public class FileArchiver {

    public boolean compressZip(String fileName){
        Path zipPath = Path.of(fileName + ".zip");

        Path filePath = Path.of(fileName);
        if(!Files.exists(filePath)) return false;
        try(
                ZipOutputStream zos = new ZipOutputStream(Files.newOutputStream(zipPath))
                ){

            zos.putNextEntry(new ZipEntry(fileName));
            zos.write(Files.readAllBytes(filePath));
            return true;
        }catch (IOException e){
            return false;
        }
    }

    public static void main(String[] args){
        if(args.length < 1) return;
        if(new FileArchiver().compressZip(args[0])){
            System.out.println(args[0] + "のzipファイルの作成ができました");
        }else{
            System.out.println(args[0] + "のzipファイルの作成ができませんでした");
        }
//        System.out.println(new FileArchiver().compressZip("dummy.dat"));
//        System.out.println(new FileArchiver().compressZip("not_found"));
    }
}
