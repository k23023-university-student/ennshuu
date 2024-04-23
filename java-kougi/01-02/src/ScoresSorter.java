public class ScoresSorter {
    public  static  void main(String args[]){
        String[] names = {"佐藤一郎", "鈴木次郎", "高橋三郎", "田中四郎", "伊藤五郎", "渡辺六郎", "山本七子", "中村八郎", "小林九", "加藤十子"};
        int[][] scores = {
                {100,30,50,40,50,60,70,80,95,10},
                {30,55,45,60,65,50,80,25,100,35},
                {90,75,35,90,65,60,80,25,0,20},
                {10,85,25,70,90,80,60,50,40,30},
                {60,40,30,50,70,70,70,70,15,55},
        };
        int [] sumScores = new int[names.length];
        for(int i=0;i<names.length;i++){//各個人の合計点を求める
            for(int j=0;j<5;j++){//科目ごとのループ
                sumScores[i] += scores[j][i];
            }
        }
        // 並び替え処理
        for (int s = 0; s < sumScores.length - 1; s++) { // 0〜3までのループ(比較元 s;source)
            for (int t = s + 1; t < sumScores.length; t++) { // (s + 1)〜4までのループ(比較先 t;target)
                if (sumScores[s] < sumScores[t]) {
                    //降順で並び替えるため、比較元より比較先が大きければ以下の入れ替え処理を行う
                    int tmp = sumScores[t];  // 比較先(t)の示す要素を一時保存(tmp)
                    String tmpName = names[t];//名前も同様に入れ替え
                    sumScores[t] = sumScores[s];  // 比較先(t)の示す要素へ、比較元(s)の示す要素を上書き
                    names[t] = names[s];
                    sumScores[s] = tmp;      // 比較元(s)の示す要素へ、tmpへ一時保存されていた比較先(t)を上書きして、比較元と比較先を入れ替えた
                    names[s] = tmpName;
                }
            }
        }
        for(int i=0;i<names.length;i++){
            System.out.println(names[i] + ":" + sumScores[i]);
        }
    }
}
