import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TextInputSample extends JFrame{
    private JPanel panel1;
    private JTextArea textArea1;
    private JTextField textField1;
    private JButton ボタンButton;

    public TextInputSample() {
        // ウィンドウを閉じたら終了させる
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        // ウィンドウ起動位置とウィンドウサイズの指定
        setBounds(100, 100, 600, 400);

        // コンテンツパネル設定 ※IntelliJIDEAでのGUI作成では以下の設定が必須です。
        setContentPane(panel1);


        ボタンButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // ボタン押下時の処理サンプル

                if (textField1.getText().isEmpty()) {
                    // 入力がない場合はフォーカスセットして処理しない
                    textField1.requestFocus();  // テキストフィールドにフォーカスセット
                    return;
                }

                // テキスト領域にテキストフィールドの文字を追加する
                textArea1.append(textField1.getText());
                textArea1.append(System.lineSeparator()); // 改行

                textField1.setText("");     // テキストフィールドクリア
                textField1.requestFocus();  // テキストフィールドにフォーカスセット
            }
        });
    }





    /**
     * メインメソッド
     * @param args
     */
    public static void main(String[] args) {
        // イベントキューに画面の起動スレッドを追加
        EventQueue.invokeLater(() -> {
            new TextInputSample().setVisible(true);
        });
    }
}
