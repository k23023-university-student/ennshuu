import java.util.Scanner;
public class Multiplication100 {
    public  static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.println("整数値を入力してください");
        //Returnキーが押されるまでまつ
        String inputLine = in.nextLine();
        //Stringからintへ変換、100をかける
        int num = Integer.parseInt(inputLine)*100;
        System.out.println("計算結果:" + num);
        in.close();
    }
}
