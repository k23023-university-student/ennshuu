package jp.ac.ait.k23023;

import javax.swing.*;
import java.awt.*;
import com.google.gson.Gson;
public class AddressBook extends JFrame {
    private JPanel panel1;
    private JButton button1;

    public AddressBook(){
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setBounds(getBounds().x, getBounds().y, 600, 600);
        setContentPane(panel1);
        setTitle("AddressBook - K23023");
    }

    public static void main(String[] args) {
        // イベントキューに画面の起動スレッドを追加
        EventQueue.invokeLater(() -> {
            new AddressBook().setVisible(true);
        });
    }
}
