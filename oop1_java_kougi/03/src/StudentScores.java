public class StudentScores {
    int id = 0;
    String name = "";
    int[] scores = new int[5];
    String[] subjects = {"国語","数学","理科","社会","英語"};
    public int getJapaneseScore() {
        return scores[0];
    }
    public int getMathematicsScore() {
        return scores[1];
    }
    public int getScienceScore() {
        return scores[2];
    }
    public int getSocialStudiesScore() {
        return scores[3];
    }
    public int getEnglishScore() {
        return scores[4];
    }
    public void setJapaneseScore(int value){
        scores[0] = value;
    }
    public void setMathematicsScore(int value){
        scores[1] = value;
    }
    public void setScienceScore(int value){
        scores[2] = value;
    }
    public void setSocialStudiesScore(int value){
        scores[3] = value;
    }
    public void setEnglishScore(int value){
        scores[4] = value;
    }
    public int getTotal(){
        int sum = 0;
        for (int score : scores) {
            sum += score;
        }
        return sum;
    }

    public double getAverage(){
        return (double)getTotal() / scores.length;
    }

    public int getHighScore(){
        int max = 0;

        for(int score : scores){
            if(max < score) max = score;
        }

        return max;
    }


    public String getHighScoreSubject(){

        int max = getHighScore();

        String returnValue = "";

        for(int i=0;i<scores.length;i++){

            if(scores[i] == max){

                if(!returnValue.isEmpty()) returnValue +=  ",";//すでにハイスコアが出ていたらコンマ追加

                returnValue += subjects[i];

            }
        }
        return returnValue;
    }

    public int getLowScore(){
        int min = getHighScore();//最小値に最大値を代入
        for(int score : scores){
            if(min > score) min = score;
        }
        return min;
    }


    public String getLowScoreSubject(){

        int min = getLowScore();
        String returnValue = "";

        for(int i=0;i<scores.length;i++){

            if(scores[i] == min){

                if(!returnValue.isEmpty()) returnValue +=  ",";//すでに最低スコアが出ていたらコンマ追加
                returnValue += subjects[i];

            }

        }
        return returnValue;
    }
    public String getInfo(){

        String returnValue = String.format("%d %s 国語:%d点 数学:%d点" +
                " 理科:%d点 社会:%d点 英語:%d点" +
                " 合計:%d点 平均:%f点" +
                " 得意科目:%s(%d点)" +
                " 苦手科目:%s(%d点)",this.id,this.name,getJapaneseScore(), getMathematicsScore()
                                                    , getScienceScore(), getSocialStudiesScore(), getEnglishScore()
                                                    , getTotal(), getAverage(), getHighScoreSubject(), getHighScore()
                                                    , getLowScoreSubject(), getLowScore());
        return returnValue;
    }
}
