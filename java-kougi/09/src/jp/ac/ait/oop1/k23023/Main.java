package jp.ac.ait.oop1.k23023;

import jp.ac.ait.oop1.section09.Grade;
import jp.ac.ait.oop1.section09.IStudent;

import java.util.ArrayList;
import java.util.List;

public class Main {


    public static void main(String[] args){

        List<Grade> subList1 = new ArrayList<>();

        subList1.add(new Grade("数学",2,'S'));
        subList1.add(new Grade("プログラミング",3,'Q'));
        subList1.add(new Grade("人工知能",2,'B'));
        subList1.add(new Grade("電子回路",2,'A'));

        Student st1 = new Student("k23001","太郎",subList1);


        List<Grade> subList2 = new ArrayList<>();
        subList2.add(new Grade("数学",2,'S'));
        subList2.add(new Grade("プログラミング",3,'B'));
        subList2.add(new Grade("人工知能",2,'A'));
        subList2.add(new Grade("電子回路",2,'A'));

        Student st2 = new Student("k23002","二郎",subList2);

        List<Grade> subList3 = new ArrayList<>();
        subList3.add(new Grade("科目D", 2, 'Q'));
        subList3.add(new Grade("科目B", 3, 'Q'));
        subList3.add(new Grade("科目A", 2, 'Q'));
        subList3.add(new Grade("科目C", 2, 'Q'));

        Student st3 = new Student("k23003","三郎",subList3);
        System.out.println(st3.getGradesSortByRatingDsc());

        
        List<Grade> subList4 = new ArrayList<>();
        subList4.add(new Grade("科目D", 2, 'S'));
        subList4.add(new Grade("科目C", 3, 'S'));
        subList4.add(new Grade("科目A", 2, 'S'));
        subList4.add(new Grade("科目B", 2, 'S'));


        Student st4 = new Student("k23004","四郎",subList4);
        List<Grade> subList5 = new ArrayList<>();
        subList5.add(new Grade("日本語リテラシ", 1, 'C'));
        subList5.add(new Grade("データサイエンス", 2, 'Q'));
        subList5.add(new Grade("英語A", 1, 'S'));
        subList5.add(new Grade("英語C", 1, 'A'));
        subList5.add(new Grade("英語B", 1, 'B'));
        subList5.add(new Grade("法律文化", 2, 'F'));


        Student st5 = new Student("k23005","五郎",subList5);


        List<IStudent> forDebug = List.of(st1,st2,st3,st4,st5);

        List<IStudent> asc = new StudentsSorter(forDebug).sortByTotalCreditsEarnedAsc();
        List<IStudent> dsc = new StudentsSorter(forDebug).sortByTotalCreditsEarnedDsc();


        for(IStudent iStudent : forDebug){//全ての生徒に対し、studentクラスのメソッド動作確認

            Student student = (Student)iStudent;

            System.out.printf("---%s(%s)---\n",student.getStudentId(),student.getName());
            System.out.println("getGradesSortByRatingDsc:");

            for(Grade grade : student.getGradesSortByRatingDsc()){
                System.out.println(grade);
            }


            System.out.println("getGradesFilterByRating:");
            System.out.print("Sのもの: ");
            System.out.println(student.getGradesFilterByRating('S'));
            System.out.print("Aのもの: ");
            System.out.println(student.getGradesFilterByRating('A'));
            System.out.print("Bのもの: ");
            System.out.println(student.getGradesFilterByRating('B'));
            System.out.print("Cのもの: ");
            System.out.println(student.getGradesFilterByRating('C'));
            System.out.print("Fのもの: ");
            System.out.println(student.getGradesFilterByRating('F'));
            System.out.print("Qのもの: ");
            System.out.println(student.getGradesFilterByRating('Q'));

            System.out.println("getGradesFilterByCreditsEarned:");
            for(Grade grade : student.getGradesFilterByCreditsEarned()){
                System.out.println(grade);
            }

        }

        //所得単位合計での並び替えも確認
        System.out.println("---sortByTotalCreditsEarnedAsc---");
        for(IStudent student : asc){
            System.out.println(((Student)student).getStudentId() + ": 総所得単位数: " + student.getTotalCreditsEarned()  + "," + student.getGrades());
        }

        System.out.println("---sortByTotalCreditsEarnedDsc---");
        for(IStudent student : dsc){
            System.out.println(((Student)student).getStudentId() + ": 総所得単位数: " + student.getTotalCreditsEarned()  + "," +  student.getGrades());
        }

    }
}
