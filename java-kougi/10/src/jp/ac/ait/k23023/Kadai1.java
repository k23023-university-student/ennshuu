package jp.ac.ait.k23023;

import java.util.Random;
import java.util.Scanner;

public class Kadai1 {

    // Kadai1 の共通スキャナ
    private static final Scanner sc = new Scanner(System.in);

    /**
     * main
     *
     * @param args
     */
    public static void main(String[] args) {

        /*
         * 配列の生成
         */
        String input = "";
        // TODO: 【エラー処理】int型の整数値に変換可能な文字列が入力されるまで繰り返したい
        while (true) {
            System.out.print("生成する配列の大きさを入力してください > ");
            input = sc.nextLine();
            if (input.matches("-?[0-9]+")) break;//正しい整数か？
        }
        // ここは例外処理しない(整数値に変換できる文字列しか来ないはず)
        int size = Integer.parseInt(input);
        int[] arr = createRandomIntArray(size);

        // 生成された配列を画面表示
        System.out.print("生成された配列: ");
        for (int a : arr) {
            System.out.print(a + " ");
        }
        System.out.println();

        /*
         * 配列の要素を取り出し
         */

        // TODO: 【エラー処理】int型の整数値に変換可能な文字列が入力されるまで繰り返したい
        while (true) {
            System.out.print("取り出す配列のインデックスを指定してください > ");
            input = sc.nextLine();
            if (input.matches("-?[0-9]+")) break;//正しい整数か？
        }

        // ここは例外処理しない(整数値に変換できる文字列しか来ないはず)
        int index = Integer.parseInt(input);
        System.out.println("値: " + getValueByIndex(arr, index));
    }

    /**
     * 指定された要素数で各要素がランダムな値を持つ配列を生成して返す
     *
     * @param size 要素数
     * @return 生成されたランダムな値を持つ配列オブジェクト
     */
    public static int[] createRandomIntArray(int size) {
        int[] arr;
        // TODO: 【例外処理】配列の要素数として正しくない値が渡された場合の例外を捕捉し、その場合は要素数0の配列を生成する
        try {
            arr = new int[size];
        } catch (NegativeArraySizeException e) {
            arr = new int[0];
        }

        Random random = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = random.nextInt(1000);   // 0〜999まででランダム
        }

        return arr;
    }

    /**
     * 配列とインデックスを渡し、その要素を取り出して返す
     *
     * @param arr   配列のオブジェクト
     * @param index インデックス
     * @return 取り出した要素
     */
    public static int getValueByIndex(int[] arr, int index) {
        // TODO: 【エラー処理】引数arrがnullだった場合、-1を返す
        // TODO: 【例外処理】配列のインデックスとして正しくない値が渡された場合の例外を捕捉し、その場合は-1を返す
        if (arr == null) return -1;
        int returnNum;
        try {
            returnNum = arr[index];
        }catch (ArrayIndexOutOfBoundsException e){
            returnNum = -1;
        }
        return returnNum;
    }
}