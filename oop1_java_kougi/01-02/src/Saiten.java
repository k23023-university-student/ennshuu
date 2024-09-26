import  java.util.Scanner;
public class Saiten {
    public static  void main(String args[]){
        System.out.println("テストの点数を入力してください。");
        Scanner input = new Scanner(System.in);
        String res = input.nextLine();
        int resNum = Integer.parseInt(res);
        if(resNum > 100 || resNum < 0){
            System.out.println("入力された値は点数として正しくありません。");
            return;
        }else{
            if(resNum >= 60) System.out.println("合格です。おめでとう！");
            else if(resNum >= 20) System.out.println("不合格です。再テストを行いましょう！");
            else System.out.println("不合格です。来年もう一年頑張りましょう。");
        }
    }
}
