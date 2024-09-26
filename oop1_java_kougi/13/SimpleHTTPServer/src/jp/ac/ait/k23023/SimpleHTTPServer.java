package jp.ac.ait.k23023;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;


public class SimpleHTTPServer {


    static String REPL_CSS = """
            HTTP/1.0 200 OK
            Content-Type: text/css
                        
            * {
              margin: 0;
              padding: 0;
              box-sizing: border-box;
            }
            body {
              height: 100vh;
              display: flex;
              justify-content: center;
              align-items: center;
            }
            main {
              height: 450px;
              max-height: 90vh;
              width: 800px;
              max-width: 90vw;
              border-radius: 10px;
              box-shadow: rgba(0, 0, 0, 0.1) 0px 20px 60px -10px;
              display: flex;
              justify-content: center;
              align-items: center;
              flex-direction: column;
            }
            h1 {
              padding: 0 3em;
              margin-bottom: 2em;
              text-align: center;
            }
            button {
              font-size: 1.25em;
              padding: 0.5em 1em;
            }
            .copyright {
              margin-top: 20px;
              text-decoration: underline;
              font-style: italic;
            }
            """;
    static String REPL_JS = """
            HTTP/1.0 200 OK
            Content-Type: text/javascript
                        
            var btn = document.querySelector('button.fire');
            btn.addEventListener('click', function() {
              alert('Hello, SimpleHTTPServer!!');
            });
            """;
    static String REPL_HTML = """
            HTTP/1.0 200 OK
            Content-Type: text/html
                        
            <!DOCTYPE html>
            <html lang="ja">
            <head>
              <meta name="viewport" content="width=device-width, initial-scale=1">
              <meta charset="UTF-8">
              <title>SimpleHTTPServer</title>
              <link rel="stylesheet" href="style.css">
            </head>
            <body>
              <main>
                <h1>このページはSimpleHTTPServerより生成されて返されています。</h1>
                <p><button class="fire">Push!!</button></p>
                <p class="copyright">K23023 - 岡田隆之介</p>
              </main>
              <script src="script.js"></script>
            </body>
            </html>
            """;


    public static void main(String[] args) throws Exception {

        String replyData = REPL_HTML;
        while (true) {
            try (
                    ServerSocket ss = new ServerSocket(8088);  // サーバー立ち上げ port:12345
                    Socket socket = ss.accept(); // クライアントからの接続待ち受け
                    BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    PrintWriter out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()), true);
            ) {
                String message = "SOMETHING";
                // 通信処理自体を無限ループ化
                while (!message.isEmpty()) {
                    // クライアントからのデータ受信 待ち受け
                    message = in.readLine();

                    if (message.startsWith("GET") || message.startsWith("POST")) {

                        String[] token = message.split(" ");


                        if (token[1].endsWith(".css")) {//リクエストパスの拡張子

                            replyData = REPL_CSS;
                        } else if (token[1].endsWith(".js")) {

                            replyData = REPL_JS;
                        } else {

                            replyData = REPL_HTML;
                        }
                    }
                }
                out.println(replyData);
            }
        }
    }
}