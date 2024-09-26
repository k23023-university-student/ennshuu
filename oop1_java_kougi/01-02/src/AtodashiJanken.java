import java.util.Scanner;
public class AtodashiJanken {
    public  static  void main(String args[]){
            int randomNumber = new java.util.Random().nextInt(3);
            String disp = "";
            switch (randomNumber){
                case 0:
                    disp = "グー";
                    break;
                case 1:
                    disp = "チョキ";
                    break;
                case 2:
                    disp = "パー";
                    break;
                default:
                    break;
            }
            System.out.println(randomNumber + ":" + disp);
            System.out.println("何を出しますか？ (0:グー,1:チョキ,2:パー)");
            Scanner in = new Scanner(System.in);
            String str = in.nextLine();
            int convertedStr = Integer.parseInt(str);
            if(convertedStr > 2){
                //0,1,2のいずれでもない
                System.out.println("あなたの出した手が判断できません。勝負はしません。");
                return;
            }
            String result;
            if(randomNumber == convertedStr) {
                //あいこ
                result = "あいこ";
            }else if((randomNumber == 0 && convertedStr == 1) ||
                    (randomNumber == 1 && convertedStr == 2)
                    || (randomNumber == 2 && convertedStr == 0)) {
                //ユーザーが負ける
                result = "負け";
            }else{
                //ユーザが勝つ
                result = "勝ち";
            }
            System.out.println(result);
    }
}
