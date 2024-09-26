import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.util.Random;

public class NumberQuiz extends JFrame{
    private JPanel panel1;
    private JTextField tNumberInput;
    private JButton bCheck;
    private JLabel IMessage;

    private int answerNum;
    private int tried;//試行回数
    public NumberQuiz(){

        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setBounds(getBounds().x, getBounds().y, 400, 150);
        setResizable(false);
        setContentPane(panel1);
        setTitle("NumberQuiz - K23023");

        init();



        bCheck.addActionListener((ActionEvent ae)->{

            if(bCheck.getText().equals("リセット")){
                init();
            }else{

                judge();

            }

        });


    }

    private void judge(){//合っているか確認する関数、正解したらtrue
        int inputNum;
        tried++;
        try {

            inputNum = Integer.parseInt(tNumberInput.getText());

        }catch(NumberFormatException e){

            IMessage.setText("数字が正しくない形式で入力されました。もう一度入力しましょう。");
            return;

        }


        if(inputNum > answerNum){
            IMessage.setText("それより小さい");

        }else if(inputNum < answerNum){

            IMessage.setText("それより大きい");

        }else{

            IMessage.setText("正解");
            bCheck.setText("リセット");

        }

        //試行回数を追記
        IMessage.setText(IMessage.getText() + String.format("（試行回数:%d回）",tried));

        tNumberInput.requestFocus();

    }

    private void init(){
        tried = 0;
        IMessage.setText("ランダムに決定した3桁の整数値を当てましょう。");
        bCheck.setText("チェック");
        tNumberInput.setText("");
        answerNum = new Random().nextInt(999);


    }
    public static void main(String[] args){
        // イベントキューに画面の起動スレッドを追加
        EventQueue.invokeLater(() -> {
            new NumberQuiz().setVisible(true);
        });
    }
}
