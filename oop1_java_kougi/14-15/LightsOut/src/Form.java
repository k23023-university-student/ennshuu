import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.List;

public class Form extends JFrame{
    private JPanel panel1;
    private JLabel ITopLeft;
    private JLabel ITopCenter;
    private JLabel ITopRight;
    private JLabel ICenterLeft;
    private JLabel ICenterCenter;
    private JLabel ICenterRight;
    private JLabel IBottomLeft;
    private JLabel IBottomCenter;
    private JLabel IBottomRight;
    List<JLabel> labels;
    public Form(){


        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setBounds(getBounds().x, getBounds().y, 600, 600);
        setContentPane(panel1);
        setTitle("LightsOut - K23023");

        labels = new ArrayList<JLabel>();

        labels.add(ITopLeft);
        labels.add(ITopCenter);
        labels.add(ITopRight);
        labels.add(ICenterLeft);
        labels.add(ICenterCenter);
        labels.add(ICenterRight);
        labels.add(IBottomLeft);
        labels.add(IBottomCenter);
        labels.add(IBottomRight);

        init();

        ITopLeft.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Hanten(ITopLeft);
                Hanten(ITopCenter);
                Hanten(ICenterLeft);
                judge();
            }
        });

        ITopCenter.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Hanten(ITopCenter);
                Hanten(ITopLeft);
                Hanten(ITopRight);
                Hanten(ICenterCenter);
                judge();
            }
        });

        ITopRight.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Hanten(ITopRight);
                Hanten(ITopCenter);
                Hanten(ICenterRight);
                judge();

            }
        });
        ICenterLeft.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Hanten(ICenterLeft);
                Hanten(ITopLeft);
                Hanten(IBottomLeft);
                Hanten(ICenterCenter);
                judge();
            }
        });

        ICenterCenter.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Hanten(ICenterCenter);
                Hanten(ITopCenter);
                Hanten(ICenterLeft);
                Hanten(ICenterRight);
                Hanten(IBottomCenter);
                judge();
            }
        });

        ICenterRight.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Hanten(ICenterRight);
                Hanten(ITopRight);
                Hanten(IBottomRight);
                Hanten(ICenterCenter);
                judge();
            }
        });

        IBottomLeft.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Hanten(IBottomLeft);
                Hanten(ICenterLeft);
                Hanten(IBottomCenter);
                judge();
            }
        });

        IBottomCenter.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Hanten(IBottomCenter);
                Hanten(IBottomLeft);
                Hanten(IBottomRight);
                Hanten(ICenterCenter);
                judge();
            }
        });

        IBottomRight.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Hanten(IBottomRight);
                Hanten(ICenterRight);
                Hanten(IBottomCenter);
                judge();
            }
        });

    }

    private void Hanten(JLabel label){

        String text;
        if(label.getText().equals("0")){
            text = "1";
        }else{
            text = "0";
        }
        label.setText(text);
    }
    private void judge(){
        String num = "1";//これが常に1なるのならばクリア
        for(JLabel label : labels){
            num = label.getText();
            if(num.equals("0")) return;
        }
        javax.swing.JOptionPane.showMessageDialog(
                panel1,                                         // コンテンツを配置しているペインコントロール
                "GameClear!!",                                  // メッセージ
                "3x3 LightsOut",                                // タイトル
                javax.swing.JOptionPane.INFORMATION_MESSAGE);

        init();
    }
    private void init(){

        //ランダムに設定
        for(JLabel label : labels){
            String r = String.valueOf(new java.util.Random().nextInt(2));
            label.setText(r);
        }

    }

    public static void main(String[] args) {
        // イベントキューに画面の起動スレッドを追加
        EventQueue.invokeLater(() -> {
            new Form().setVisible(true);
        });
    }
}
