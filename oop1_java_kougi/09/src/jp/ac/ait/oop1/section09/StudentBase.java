package jp.ac.ait.oop1.section09;

import java.util.List;

/**
 * 生徒クラスの抽象クラス<br />
 * (Studentクラスにフィールドを持たせたかったので抽象クラス化していますが<br />
 *  これを参考にStudentSorterでもデータをフィールドに保持できるように実装できると良いです)
 */
public abstract class StudentBase {
    /**
     * 学籍番号
     */
    String studentId;
    /**
     * 氏名
     */
    String name;
    /**
     * 教科ごとの成績リスト
     */
    List<Grade> grades;

    /**
     * 学籍番号
     * @return 学籍番号
     */
    public String getStudentId() {
        return studentId;
    }

    /**
     * 学籍番号
     * @param studentId 学籍番号
     */
    public void setStudentId(String studentId) {
        this.studentId = studentId;
    }

    /**
     * 氏名
     * @return 氏名
     */
    public String getName() {
        return name;
    }

    /**
     * 氏名
     * @param name 氏名
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * 成績リスト
     * @return 成績リスト
     */
    public List<Grade> getGrades() {
        return grades;
    }

    /**
     * 成績リスト
     * @param grades 成績リスト
     */
    public void setGrades(List<Grade> grades) {
        this.grades = grades;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(String.format("%s : %s", this.getStudentId(), this.getName()));
        this.grades.stream().forEach((grade -> {
            sb.append(", ");
            sb.append(String.format(grade.toString()));
        }));
        return sb.toString();
    }
}
