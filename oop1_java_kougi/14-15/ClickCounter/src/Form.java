import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;

public class Form extends JFrame{
    private JPanel panel1;
    private JLabel ICounter;
    private JButton bDecrimentButton;
    private JButton bReset;
    private JButton bIncriment;
    private int count = 0;
    public Form(){
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setBounds(getBounds().x, getBounds().y, 600, 149);
        setResizable(false);
        setContentPane(panel1);
        setTitle("ClickCounter - K23023");
        ICounter.setText(String.valueOf(this.count));

        bDecrimentButton.addActionListener((ActionEvent ae)->{

            ICounter.setText(String.valueOf(--this.count));

        });

        bIncriment.addActionListener((ActionEvent ae)->{

            ICounter.setText(String.valueOf(++this.count));
        });

        bReset.addActionListener((ActionEvent ae)->{
            
            ICounter.setText(String.valueOf(this.count=0));

        });
    }

    public static void main(String[] args) {
        // イベントキューに画面の起動スレッドを追加
        EventQueue.invokeLater(() -> {
            new Form().setVisible(true);
        });
    }
}
