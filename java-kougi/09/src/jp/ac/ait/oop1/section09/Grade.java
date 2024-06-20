package jp.ac.ait.oop1.section09;

/**
 * 教科ごとの成績クラス
 */
public class Grade {

    /**
     * すべてのパラメータを指定して初期化します。
     * @param subject 科目名
     * @param credit その科目の単位数
     * @param myRating 評定結果
     */
    public Grade(String subject, int credit, char myRating) {
        this.subject = subject;
        this.credit = credit;
        this.myRating = myRating;
    }

    /**
     * 科目名
     */
    String subject;

    /**
     * 取得可能単位数
     */
    int credit;

    /**
     * 評価(S,A,B,C,F,Qのいずれか)
     */
    char myRating;

    /**
     * 科目名のアクセサ
     * @return 科目名
     */
    public String getSubject() {
        return subject;
    }

    /**
     * 科目名のアクセサ
     * @param subject 科目名
     */
    public void setSubject(String subject) {
        this.subject = subject;
    }

    /**
     * 取得可能単位数のアクセサ
     * @return 取得可能単位数
     */
    public int getCredit() {
        return credit;
    }

    /**
     * 取得可能単位数のアクセサ
     * @param credit 取得可能単位数
     */
    public void setCredit(int credit) {
        this.credit = credit;
    }

    /**
     * 評価のアクセサ(取得のみ)
     * @return 評価(S,A,B,C,F,Qのいずれか)
     */
    public char getMyRating() {
        return myRating;
    }

    /**
     * 評価の設定<br />
     * (S,A,B,C,F,Qのいずれかの文字を設定します。不正な文字が渡された場合にRuntimeExceptionを発生させます。)
     * @param myRating 評価(S,A,B,C,F,Qのいずれか)
     */
    public void setMyRating(char myRating) {
        switch (myRating) {
            case 'S':
            case 'A':
            case 'B':
            case 'C':
            case 'F':
            case 'Q':
                break;
            default:
                throw new RuntimeException("評価にS,A,B,C,F,Q以外の文字を設定することはできません。");
        }
        this.myRating = myRating;
    }

    /**
     * 評価の内容により取得できた単位数を返します。
     * @return 取得単位
     */
    public int getMyCredit() {
        switch (this.getMyRating()) {
            case 'Q':
            case 'F':
                return 0;
            default:
                return this.getCredit();
        }
    }

    @Override
    public String toString() {
        return String.format("%s : %d / %d (%s)",
                this.getSubject(),
                this.getMyCredit(),
                this.getCredit(),
                this.getMyRating());
    }
}
