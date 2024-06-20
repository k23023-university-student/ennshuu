package jp.ac.ait.oop1.section09;

import java.util.List;

/**
 * 生徒の振る舞い定義インターフェイス<br />
 * (ここで挙げているメソッドの実装が課題の評価対象です。)
 */
public interface IStudent {

    /**
     * 成績リスト取得
     * @return 登録された成績リスト
     */
    List<Grade> getGrades();

    /**
     * 成績リスト登録(こちらで評価を行う際に使用します。)
     * @param grades 成績リストを渡します
     */
    void setGrades(List<Grade> grades);

    /**
     * 成績を評価の降順で並び替えして取得<br />
     * (S&gt;A&gt;B&gt;C&gt;F&gt;Q の順で並び替わるようにし、同じ評価の場合は科目名をUnicode順の昇順で並び替えを行う)
     * @return 並び替え後の成績リスト
     */
    List<Grade> getGradesSortByRatingDsc();

    /**
     * 指定された評価の成績リストを取得する
     * @param rating 評価
     * @return 指定された評価の成績リスト
     */
    List<Grade> getGradesFilterByRating(char rating);

    /**
     * 単位取得できた成績リストを取得する
     * @return 単位取得済み成績リスト
     */
    List<Grade> getGradesFilterByCreditsEarned();

    /**
     * 単位の総取得数
     * @return 単位の総取得数
     */
    int getTotalCreditsEarned();
}
