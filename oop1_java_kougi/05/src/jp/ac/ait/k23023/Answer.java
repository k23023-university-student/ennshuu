package jp.ac.ait.k23023;

import java.util.Random;

public class Answer {

    /**
     * 数値の桁数（final修飾子を使い、再代入を禁止させています。定数のようなものです）
     */
    public static final int DIGITS = 3;

    /**
     * 答え（文字列で管理しています）
     */
    private String numbers;

    /**
     * コンストラクタで答えの初期化
     */
    public Answer() {
        // 答えの生成を行う
        randomize();
    }

    /**
     * 答えを取得する
     *
     * @return
     */
    public String get() {
        return numbers;
    }

    /**
     * 答えをランダム並び替える
     */
    public void randomize() {
        numbers = ""; // 初期化
        for (int i = 1; i <= DIGITS; i++) {
            numbers += getUniqueNumber();
        }
    }

    /**
     * 答えの数値から、被っていない数値を取得する
     * （内部的な利用のみを想定しているためprivateにしてあります。）
     *
     * @return
     */
    private int getUniqueNumber() {
        Random r = new Random();
        boolean isUnique = true;
        int a = r.nextInt(10); // 0〜9のランダムな数値を取得
        do {
            isUnique = true;
            for (char c : numbers.toCharArray()) {
                if (Character.getNumericValue(c) == a) {
                    isUnique = false;
                    a = r.nextInt(10); // 0〜9のランダムな数値を取得
                    break;  // 直近のforを抜ける
                }
            }
        } while (!isUnique);
        return a;
    }
}