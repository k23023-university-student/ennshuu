package jp.ac.ait.k23023;

public class PasswordRulesViolationException  extends Exception{

    public PasswordRulesViolationException(){
        super();
    }
    public PasswordRulesViolationException(String message){
        super(message);
    }
    public PasswordRulesViolationException(String message, Throwable cause){
        super(message,cause);
    }
    public PasswordRulesViolationException(String message, Throwable cause,boolean enableSuppression, boolean writableStackTrace){
        super(message,cause,enableSuppression,writableStackTrace);
    }

}
