package jp.ac.ait.k23023;

import java.util.Scanner;
import java.util.*;
public class Kadai2 {
    public static void main(String[] args){
        System.out.print("パスワードの入力: ");

        Scanner scn = new Scanner(System.in);
        String in = scn.nextLine();
        try {
            PasswordManager.validate(in);
        } catch (PasswordRulesViolationException e) {
            System.out.printf("パスワードのルール基準を満たしていません。%s \n", e.getMessage());
        }

        List<String> passwords = Arrays.asList(
                "a",
                "+dR-fb5MT97xA0cJ2RYq!eRam8L12zXp/O7+mあ+Ik0AE3.DIJiE+E2",
                "FGHVFGJBGTYJGYUJGJHGYUJHGFTYUJHGYUJNHGYUJH",
                "dodhdfohfoehfoeihfoewhfioewfhewoifhewiofhoiew",
                "58326547236532653275693256236598325628356326858923",
                "********************************@@@@@@@@@@@",
                "fefhjewhfoewfheoheowhewo6487325837258732@@@",
                "FJEHFOEWHFOEWHFGOEWHGOEWHGOEWH5732563275***@@",
                "wqheowqhiqwhoiwqhriowqHDjoiq@@@",
                "fnakneoafebiabeiFYUFUFUFU343264823764238768237",
                "1@48k.TBCpassword",
                "1@48k.TBCpaSSwoRd",
                "xj.ArG*GKzT@bkq?1!p@ssw0rDll+7q/ rIBgB+s",
                "jsTUGUwagPp0r?vg2yMS2q+fFX",
                "e9-Mbhhtz9CqwertyH3/FekMCz=dwzo5FC",
                "QbZ.isbA8!asdFghKU=k#a+Jd3+n/K5XqXf5sFx",
                ".Cm@nKHtTW1*3bL8e4Sbgs0ooE4+e!Q@=BZdqcfElWsEGcGFm!j-VYAjUiT*X@Y6PGko?.@d_tT5@dNtQ/Q!h*bAKhR..#xqS",
                "j#5zA+@*JNh+-7ZXCVBNvfqi_jOBVKmMw?fL*-dbXVk",
                "/8.zeKCg*.myaAbcDefabcdef1Bp0UVwWSuJdp0Gw6lGZZe+3JrlD7@OhdQ9We!",
                "osPEirT_JEq.!GANHmIi5123456_pJ=bf_CY++a=ScLNZsMz1KVikse2*34nwEVtVgW_xj?nr"
        );

        passwords.stream().forEach(o ->{
            System.out.printf("// %s -> ",o);
            try {
                PasswordManager.validate(o);
            } catch (PasswordRulesViolationException e) {
                System.out.printf("パスワードのルール基準を満たしていません。%s \n", e.getMessage());
            }
        });



        // --- Comment: 16文字以下のパスワードはアウト
        // a
        // --- Comment: 使用不可の文字が含まれるとアウト
        // +dR-fb5MT97xA0cJ2RYq!eRam8L12zXp/O7+mあ+Ik0AE3.DIJiE+E2
        // --- Comment: 大文字のみであるとアウト
        // FGHVFGJBGTYJGYUJGJHGYUJHGFTYUJHGYUJNHGYUJH
        // --- Comment: 小文字のみであるとアウト
        // dodhdfohfoehfoeihfoewhfioewfhewoifhewiofhoiew
        // -- Comment: 数字のみであるとアウト
        // 58326547236532653275693256236598325628356326858923
        // --- Comment: 記号のみであるとアウト
        // ********************************@@@@@@@@@@@
        // --- Comment: 一つでも必須文字がなければアウト(大文字が含まれていない)
        // fefhjewhfoewfheoheowhewo6487325837258732@@@
        // --- Comment: 一つでも必須文字がなければアウト(小文字が含まれていない)
        // FJEHFOEWHFOEWHFGOEWHGOEWHGOEWH5732563275***@@
        // --- Comment: 一つでも必須文字がなければアウト(数字が含まれていない)
        // wqheowqhiqwhoiwqhriowqHDjoiq@@@
        // --- Comment: 一つでも必須文字がなければアウト(記号が含まれていない)
        // fnakneoafebiabeiFYUFUFUFU343264823764238768237
        // --- Comment: password(大文字小文字不問)が含まれるとアウト
        // 1@48k.TBCpassword
        // --- Comment: paSSwoRd(大文字小文字不問)が含まれるとアウト
        // 1@48k.TBCpaSSwoRd
        // --- Comment: p@ssw0rd(大文字小文字不問)が含まれるとアウト
        // xj.ArG*GKzT@bkq?1!p@ssw0rDll+7q/ rIBgB+s
        // --- Comment: p@55w0rd(大文字小文字不問)が含まれるとアウト
        // jsTUGUwagPp0r?vg2yMS2q+fFX
        // -- Comment: qwerty(大文字小文字不問)が含まれるとアウト
        // e9-Mbhhtz9CqwertyH3/FekMCz=dwzo5FC
        // -- Comment: asdfgh(大文字小文字不問)が含まれるとアウト
        // QbZ.isbA8!asdFghKU=k#a+Jd3+n/K5XqXf5sFx
        // -- Comment: (大文字小文字不問)が含まれるとアウト
        // .Cm@nKHtTW1*3bL8e4Sbgs0ooE4+e!Q@=BZdqcfElWsEGcGFm!j-VYAjUiT*X@Y6PGko?.@d_tT5@dNtQ/Q!h*bAKhR..#xqS
        // -- Comment: zxcvbn(大文字小文字不問)が含まれるとアウト
        // j#5zA+@*JNh+-7ZXCVBNvfqi_jOBVKmMw?fL*-dbXVk
        // -- Comment: abcdef(大文字小文字不問)が含まれるとアウト
        // /8.zeKCg*.myaAbcDefabcdef1Bp0UVwWSuJdp0Gw6lGZZe+3JrlD7@OhdQ9We!
        // -- Comment: 123456が含まれるとアウト
        // osPEirT_JEq.!GANHmIi5123456_pJ=bf_CY++a=ScLNZsMz1KVikse2*34nwEVtVgW_xj?nr

    }
}
