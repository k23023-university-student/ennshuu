package jp.ac.ait.k23023;

import com.google.gson.Gson;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;

public class AddressBook extends JFrame {
    private JPanel panel1;
    private JButton saveButton;
    private JTextField textField1;
    private JTextField textField2;
    private JButton addButton;
    private JList list1;

    private DefaultListModel model;
    private record Prop(String name, String phoneNumber){ }//ユーザ情報の保管用
    List<Prop> userList;
    public AddressBook(){

        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setBounds(getBounds().x, getBounds().y, 600, 300);
        setContentPane(panel1);
        setTitle("AddressBook - K23023");

        userList =  new ArrayList<Prop>();

        model = new DefaultListModel();
        list1.setModel(model);

        addButton.addActionListener((ActionEvent ae)->{


            if(!textField1.getText().isEmpty() && !textField2.getText().isEmpty()) {

                Prop user = new Prop(textField1.getText(), textField2.getText());
                userList.add(user);
                //DefaultListModel model = new DefaultListModel();
                model.addElement(String.format("%s:%s",textField1.getText(), textField2.getText()));


                textField1.setText("");
                textField2.setText("");
            }
        });

        saveButton.addActionListener((ActionEvent ae)->{


                JFileChooser jc = new JFileChooser();
                int selected = jc.showSaveDialog(panel1);

                if(selected == JFileChooser.APPROVE_OPTION){

                    String outputJson = new Gson().toJson(userList);

                    try {
                        Files.writeString(jc.getSelectedFile().toPath(), outputJson);
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }

            });
        }


    public static void main(String[] args) {
        // イベントキューに画面の起動スレッドを追加
        EventQueue.invokeLater(() -> {
            new AddressBook().setVisible(true);
        });
    }
}
