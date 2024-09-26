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



        List<String> passwordsForTest = Arrays.asList(
                ".Cm@nKHtTW1*3bL8e4Sbgs0ooE4+e!Q@=BZdqcfElWsEGcGFm!j-VYAjUiT*X@Y6PGko?.@d_tT5@dNtQ/Q!h*bAKhR..#xqSdfwqfhwoqhfowqhfowqhowqifhiowqhs", // パスワードのルール基準を満たしていません。パスワードの長さが不正です
                ".Cm@nKHtTW1*3bL8e4Sbgs0ooE4+e!Q@=BZdqcfElWsEGcGFm!j-VYAjUiT*X@Y6PGko?.@d_tT5@dNtQ/Q!h*bAKhR..#xqSdfwqfhwoqhfowqhfowqhowqifhiowqh", // ok
                "a", // パスワードのルール基準を満たしていません。パスワードの長さが不正です
                ".Cm@nKHtTW1*3bL", // パスワードのルール基準を満たしていません。パスワードの長さが不正です
                ".Cm@nKHtTW1*3bLe", // ok
                ".Cm@nKHtTW1*3bL8e4Sbgs0ooE4+e!Q@=BZdqcfElWsEGcGFm!j-VYAjUiT*X@Y6PGko?.@d_tT5@dNtQ/Q!h*bAKhR..#xqS", // ok
                "+dR-fb5MT97xA0cJ2RYq!eRam8L12zXp/O7+mあ+Ik0AE3.DIJiE+E2", // パスワードのルール基準を満たしていません。使用不可能な文字を検知しました:あ
                "FGHVFGJBGTYJGYUJGJHGYUJHGFTYUJHGYUJNHGYUJH", // パスワードのルール基準を満たしていません。小文字アルファベット、大文字アルファベット、数字、使用可能な記号を少なくとも一つずつ含む必要があります
                "dodhdfohfoehfoeihfoewhfioewfhewoifhewiofhoiew", // パスワードのルール基準を満たしていません。小文字アルファベット、大文字アルファベット、数字、使用可能な記号を少なくとも一つずつ含む必要があります
                "58326547236532653275693256236598325628356326858923", // パスワードのルール基準を満たしていません。小文字アルファベット、大文字アルファベット、数字、使用可能な記号を少なくとも一つずつ含む必要があります
                "********************************@@@@@@@@@@@", // パスワードのルール基準を満たしていません。小文字アルファベット、大文字アルファベット、数字、使用可能な記号を少なくとも一つずつ含む必要があります
                "fefhjewhfoewfheoheowhewo6487325837258732@@@", // パスワードのルール基準を満たしていません。小文字アルファベット、大文字アルファベット、数字、使用可能な記号を少なくとも一つずつ含む必要があります
                "FJEHFOEWHFOEWHFGOEWHGOEWHGOEWH5732563275***@@", // パスワードのルール基準を満たしていません。小文字アルファベット、大文字アルファベット、数字、使用可能な記号を少なくとも一つずつ含む必要があります
                "wqheowqhiqwhoiwqhriowqHDjoiq@@@", // パスワードのルール基準を満たしていません。小文字アルファベット、大文字アルファベット、数字、使用可能な記号を少なくとも一つずつ含む必要があります
                "fnakneoafebiabeiFYUFUFUFU343264823764238768237", // パスワードのルール基準を満たしていません。小文字アルファベット、大文字アルファベット、数字、使用可能な記号を少なくとも一つずつ含む必要があります
                "1@48k.TBCpassword", // パスワードのルール基準を満たしていません。パスワード中に使用不可能な文字列を検出しました
                "1@48k.TBCpaSSwoRd", // パスワードのルール基準を満たしていません。パスワード中に使用不可能な文字列を検出しました
                "xj.ArG*GKzT@bkq?1!p@ssw0rDll+7q/ rIBgB+s", // パスワードのルール基準を満たしていません。パスワード中に使用不可能な文字列を検出しました
                "e9-Mbhhtz9CqwertyH3/FekMCz=dwzo5FC", // パスワードのルール基準を満たしていません。パスワード中に使用不可能な文字列を検出しました
                "QbZ.isbA8!asdFghKU=k#a+Jd3+n/K5XqXf5sFx", // パスワードのルール基準を満たしていません。パスワード中に使用不可能な文字列を検出しました
                "j#5zA+@*JNh+-7ZXCVBNvfqi_jOBVKmMw?fL*-dbXVk", // パスワードのルール基準を満たしていません。パスワード中に使用不可能な文字列を検出しました
                "/8.zeKCg*.myaAbcDefabcdef1Bp0UVwWSuJdp0Gw6lGZZe+3JrlD7@OhdQ9We!", // パスワードのルール基準を満たしていません。パスワード中に使用不可能な文字列を検出しました
                "osPEirT_JEq.!GANHmIi5123456_pJ=bf_CY++a=ScLNZsMz1KVikse2*34nwEVtVgW_xj?nr" // パスワードのルール基準を満たしていません。パスワード中に使用不可能な文字列を検出しました
        );
//        以下はテストコード
//        passwordsForTest.stream().forEach(o ->{
//            try {
//                if(PasswordManager.validate(o)) System.out.printf("%s -> ok\n",o);
//            } catch (PasswordRulesViolationException e) {
//                System.out.printf("%s -> ",o);
//                System.out.printf("パスワードのルール基準を満たしていません。%s \n", e.getMessage());
//            }
//        });
    }
}
