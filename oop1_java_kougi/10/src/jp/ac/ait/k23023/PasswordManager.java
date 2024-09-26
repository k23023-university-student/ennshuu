package jp.ac.ait.k23023;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.List;
public class PasswordManager{
    public static boolean validate(String password) throws PasswordRulesViolationException{

        List<Character> symbolList = Arrays.asList(',', '.', '+', '-', '*', '/', '=', '_', '#', '!', '?', '@', ' ');
        if(password.length() < 16 || password.length() > 128) throw new PasswordRulesViolationException("パスワードの長さが不正です");
        int lowerCaseCount = 0,upperCaseCount = 0, numCount = 0, symbolCount = 0;

        for(int i=0;i<password.length();i++){

            char c = password.charAt(i);
            //使用可能な文字である場合カウントアップ
            if('a' <= c && c <= 'z') lowerCaseCount++;
            else if ('A' <= c && c <= 'Z') upperCaseCount++;
            else if('0' <= c && c <= '9') numCount++;
            else if(symbolList.contains(c)) symbolCount ++;
            else throw new PasswordRulesViolationException("使用不可能な文字を検知しました:" + c);

        }
            if((lowerCaseCount == 0) ||
                (upperCaseCount == 0) ||
                    (numCount == 0) ||
                    (symbolCount == 0))
                throw new PasswordRulesViolationException("小文字アルファベット、大文字アルファベット、数字、使用可能な記号を少なくとも一つずつ含む必要があります");


        Set<String> unusableStringSet = new HashSet<>(Arrays.asList(
                "password", "p@ssw0rd", "p@55w0rd", "qwerty", "asdfgh", "zxcvbn", "abcdef", "123456"));

        for(String i : unusableStringSet){
            if(password.toLowerCase().contains(i)) throw new PasswordRulesViolationException("パスワード中に使用不可能な文字列を検出しました");
        }
        return true;
    }
}
