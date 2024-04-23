import  java.util.Scanner;
public class MessageInput {
    public static  void main(String[] args){
        //標準出力の取得
        Scanner in = new Scanner(System.in);
        System.out.println("こんにちは、メッセージをどうぞ");

        //Returnキーが押されるまでまつ
        String inputLine = in.nextLine();
        System.out.println("メッセージを受信しました");
        System.out.println("---");
        System.out.println(inputLine);
        System.out.println("---");
        in.close();
    }
}
