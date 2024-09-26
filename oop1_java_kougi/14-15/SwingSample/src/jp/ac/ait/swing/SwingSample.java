package jp.ac.ait.swing;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
/**
 * SwingSample
 */
public class SwingSample extends JFrame {


    private JLabel label;
    private JButton button;
    public SwingSample() {
        // ウィンドウを閉じたら終了させる
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        // ウィンドウ起動位置とウィンドウサイズの指定
        setBounds(100, 100, 300, 200);

        // ラベル設定
        label = new JLabel();
        label.setText("Hello, World!!");
        // ラベルを画面中央に設定
        this.getContentPane().add(label, BorderLayout.CENTER);

        // ボタン設定
        button = new JButton();
        button.setText("Click!!");
        // クリック時のイベント設定
        button.addActionListener((ActionEvent ae) -> {
            label.setText("Hello, Swing!!");
        });
        // 画面下部にボタンを配置
        this.getContentPane().add(button, BorderLayout.SOUTH);
    }

    /**
     * メインメソッド
     * @param args
     */
    public static void main(String[] args) {
        // イベントキューに画面の起動スレッドを追加
        EventQueue.invokeLater(() -> {
            new SwingSample().setVisible(true);
        });
    }
}