package jp.ac.ait.oop1.section09;

import java.util.List;

/**
 * 生徒の並び替え動作を定義するインターフェイス<br />
 * (ここで挙げているメソッドの実装が課題の評価対象です。)
 */
public interface IStudentsSorter {

    /**
     * 生徒リストを取得
     * @return 生徒リスト
     */
    List<IStudent> getStudents();

    /**
     * 生徒リストを設定<br />
     * (こちらで課題の評価を行う際に使用します。自分では使わなくてもちゃんと実装しましょう。)
     * @param students 設定済みの生徒リストを渡します
     */
    void setStudents(List<IStudent> students);

    /**
     * 取得単位数の昇順で並び替えた生徒リストの取得
     * @return 取得単位数の昇順で並び替えた生徒リスト
     */
    List<IStudent> sortByTotalCreditsEarnedAsc();

    /**
     * 取得単位数の降順で並び替えた生徒リストの取得
     * @return 取得単位数の降順で並び替えた生徒リスト
     */
    List<IStudent> sortByTotalCreditsEarnedDsc();
}
