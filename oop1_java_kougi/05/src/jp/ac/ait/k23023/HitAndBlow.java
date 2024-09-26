package jp.ac.ait.k23023;
import java.util.Scanner;

public class HitAndBlow {
    public static void main(String[] args){

        Manager app = new Manager();

        Scanner in = new Scanner(System.in);

        while (true) {
            System.out.println("input " + Answer.DIGITS + " numbers :");
            String userInput = in.nextLine();
            //整数でないか、長さが一致しない場合、プログラムを終了
            if (!StringUtilities.isUnsignedInteger(userInput) ||
                    userInput.length() != Answer.DIGITS) {
                System.out.println("Error");
                return;
            }

            Response res = app.solve(userInput);

            if (res.getHit() == Answer.DIGITS) {
                System.out.printf("正解です。試行回数は%d回でした。", app.getCount());
                return;
            }

            System.out.printf("%d Hit, %d Blow\n",res.getHit(),res.getBlow());

        }
    }
}
