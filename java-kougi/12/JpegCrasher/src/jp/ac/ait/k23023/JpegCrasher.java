package jp.ac.ait.k23023;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.Random;

public class JpegCrasher {

    /**
     * メインメソッド
     */
    public static void main(String[] args) {

        if(args.length < 2) return;//ファイル名が引数で指定されなければ終了

        crash(args[0], args[1], 15);  //ここのファイル名はコマンドライン引数で可変となるようにする
    }
    /**
     * 入力されたファイルのランダムな1Byteをランダムな1bit加算で置き換えることでファイルをクラッシュさせる
     * @param input_filePath
     * @param output_filePath
     * @param challenge
     */
    public static void crash(
            String input_filePath,
            String output_filePath,
            int challenge) {
        // TODO:
        byte[] a;
        try(
                BufferedInputStream bis = new BufferedInputStream(Files.newInputStream(Path.of(input_filePath)));
        ) {

            a = bis.readAllBytes();

        }catch (IOException e){
            throw new UncheckedIOException(e);
        }

        byte[] bits = {
                (byte)0b00000001,
                (byte)0b00000010,
                (byte)0b00000100,
                (byte)0b00001000,
                (byte)0b00010000,
                (byte)0b00100000,
                (byte)0b01000000,
                (byte)0b10000000
        };
        for(int i=0;i<challenge;i++) {
            byte value = bits[new Random().nextInt(bits.length)];
            // 1bitの値を加算して0xFFでAND演算することで1bitの変化を加える
            int randomIndex = new Random().nextInt(a.length);
            a[randomIndex] = (byte) ((int) a[randomIndex] + (int) value & 0xFF);
        }
        try {
            Files.write(Path.of(output_filePath), a, StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING);
        }catch (IOException e){
            throw new UncheckedIOException(e);
        }
    }

}
