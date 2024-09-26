package jp.ac.ait.k23023;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;

public class HtmlGetter extends JFrame{
    private JPanel panel1;
    private JTextField txtURL;
    private JButton btnGet;
    private JButton btnSave;
    private JTextArea txtHtml;
    public HtmlGetter(){

        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setBounds(getBounds().x, getBounds().y, 640, 480);
        setContentPane(panel1);
        setTitle("HTMLGetter - K23023");

        btnGet.addActionListener((ActionEvent ae)->{
            String data = httpGet(txtURL.getText());
            txtHtml.setText(data);
        });

        btnSave.addActionListener((ActionEvent ae)->{

            JFileChooser jc = new JFileChooser();
            int selected = jc.showSaveDialog(panel1);

            if(selected == JFileChooser.APPROVE_OPTION){

                File selectedFile = jc.getSelectedFile();
                try {
                    FileWriter fw = new FileWriter(selectedFile);
                    fw.write(txtHtml.getText());
                    System.out.println(selectedFile);
                    fw.close();
                }catch (IOException e){
                    e.printStackTrace();
                }

            }

        });
    }

    private String httpGet(String url){

        HttpClient client = HttpClient.newBuilder().followRedirects(HttpClient.Redirect.NORMAL).build();
        HttpRequest req = HttpRequest.newBuilder().uri(URI.create(url)).build();

        try {
            HttpResponse<String> response = client.send(req, HttpResponse.BodyHandlers.ofString());
            return response.body();
        }catch (IOException | InterruptedException e){
            e.printStackTrace();
            return "";
        }

    }
    public static void main(String[] args) {
        // イベントキューに画面の起動スレッドを追加
        EventQueue.invokeLater(() -> {
            new HtmlGetter().setVisible(true);
        });
    }
}
