//ScoresRegistry用のテストコード
import java.util.Scanner;
public class ScoresRegistry
{
    public static void main(String args[]){


        Scanner scn = new Scanner(System.in);

        System.out.println("人数を入力してください");
        int num = Integer.parseInt(scn.nextLine());//ユーザーの人数

        StudentScores[] students = new StudentScores[num];

        for(int i=0;i<num;i++){
            students[i] = new StudentScores();
            System.out.println("出席番号を入力せよ");
            students[i].id = Integer.parseInt(scn.nextLine());

            System.out.println("氏名を入力せよ");
            students[i].name = scn.nextLine();

            System.out.println("国語の点数を入力せよ");
            students[i].setJapaneseScore(Integer.parseInt(scn.nextLine()));

            System.out.println("数学の点数を入力せよ");
            students[i].setMathematicsScore(Integer.parseInt(scn.nextLine()));

            System.out.println("理科の点数を入力せよ");
            students[i].setScienceScore(Integer.parseInt(scn.nextLine()));

            System.out.println("社会の点数を入力せよ");
            students[i].setSocialStudiesScore(Integer.parseInt(scn.nextLine()));

            System.out.println("英語の点数を入力せよ");
            students[i].setEnglishScore(Integer.parseInt(scn.nextLine()));
        }
        for(int i=0;i<num;i++){

            System.out.println(students[i].getInfo());

        }
    }
}
