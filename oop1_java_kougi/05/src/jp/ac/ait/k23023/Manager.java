package jp.ac.ait.k23023;

public class Manager {

    private int count;

    private Answer answer;

    public Manager(){
        this.count = 0;
        answer = new Answer();
    }

    public int getCount(){

        return this.count;
    }

    public Answer getAnswer(){
        return answer;
    }
    private int countOf(char[] arr, char target){//配列内にいくつ要素があるかをカウントする関数
        int count = 0;
        for(char c : arr){

            if(c == target) count++;

        }
        return count;
    }
    public Response solve(String in){

        count++;
        char[] usrAnsArr = in.toCharArray();

        String ans = answer.get();//コンピュータ側の出力をとってきて、文字列として得る
        char [] ansArr = ans.toCharArray();

        int hit = 0;
        int blow = 0;

        for(int i=0;i<usrAnsArr.length;i++){

            if(ansArr[i] == usrAnsArr[i]){ //hitしたとき

                hit++;

            }else{ //blow

                blow += countOf(ansArr,usrAnsArr[i]);
            }

        }

        Response res = new Response();
        res.setHit(hit);
        res.setBlow(blow);
        return res;
    }

}
