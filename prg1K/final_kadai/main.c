#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define LINE_LENGTH 128
#define MAX_DAY 3650 //記録できる最大の日数(10年)
#define WEIGHT_COLUMN 3 //体重を表すのはCSVの何列目か
#define MAX_PATH 256 //パスの最大長
#define FILE_NAME "data.csv"
int fileLoader(char*,char(*)[]);
void fileSaver(char*,char*);
double getAverage(double (*) ,int);
double getBmi(double, double);

void showStatistic(void);
void addData(void);
int main(int argc, const char * argv[]){
    //キーボードからの入力 すべき処理を格納する変数
    /*
    0-> 終了
    1-> 体重新規入力
    2-> 編集モード（編集＆削除）
    3-> 平均値等表示
    4-> グラフ表示(gnuplot)


    */
    int whatToDo = -1;//行う処理の種類
    while(whatToDo != 0){//プログラムのメインループ
        printf("\x1b[33m"); //黄色文字ここから
        printf("<<<メインメニュー>>>\n"
        "[0]: プログラムの終了\n"
        "[1]: 体重の新規入力\n"
        "[2]: 入力値の編集\n"
        "[3]: 平均値統計データ表示\n"
        "[4]: グラフ表示");
        printf("\n\n\x1b[0m"); //黄色文字ここまで
        printf("上記より行う処理を入力せよ> ");
        scanf("%d",&whatToDo);
        switch (whatToDo)//作業内容で分岐する
        {
        case 0:
            break;
        case 1:
            addData();
            break;
        case 2:
            break; 
        case 3:
            showStatistic();
            break;
        
        default:
            printf("無効な処理: %d\n",whatToDo);
            break;
        }
    }
    return 0;
}

int fileLoader(char* path ,char (*result)[LINE_LENGTH]){//体重データファイル読み込み関数 行数を返す
    char lineData[LINE_LENGTH];
    int count = 0;

    FILE *fp;

    fp = fopen(path,"r");//読み取り専用モードでファイルを開く

    if(fp == NULL){//ファイル読み込みエラー発生時
        printf("file load error");//エラーの出力
        return 0;//読み込みエラー時は行数0
    }

     while(fgets(lineData,sizeof(lineData),fp)){//一行ごとにファイルを読む
        char *kaigyouPointer;//改行文字のある位置へのポインタを格納する変数
        kaigyouPointer =  strchr(lineData, '\n');//改行文字の位置を検索
        if (kaigyouPointer != NULL) *kaigyouPointer = '\0';//改行文字をヌル文字へ置き換え
        strcpy(result[count],lineData);//結果の文字列をコピー
        count ++;
     }

    fclose(fp);

    return count;//行数を返す
}
void fileSaver(char *path,char *content){
    FILE *fp;
    fp = fopen(path,"w");
    if(fp == NULL){
        printf("ファイル書き込みエラー: 書き込み対象のファイルを開けません。処理を中止します\n");
        return;
    }
    fprintf(fp,"%s",content);
    fclose(fp);
}
double getAverage(double *array, int size){//平均を求める関数
    double sum=0;//合計値
    for(int i=0;i<size;i++){
    sum = sum + array[i];
    }
    return sum/size;
}
double getBmi(double weight,double height){//BMIを求める関数 身長はcmで渡す
    return weight/((height/100)*(height/100));
}
void showStatistic(void){//統計を表示する関数

    char path[MAX_PATH] = FILE_NAME;
    char loadedData[MAX_DAY][LINE_LENGTH];
    int line = fileLoader(path,loadedData);
    double tall;//身長を格納する変数

    printf("平均値からBMIを求めます。身長(cm)を入力してください> ");
    scanf("%lf",&tall);
    double weightList[MAX_DAY];


    for (int i = 0; i < line; i++) {//ファイルの行数だけ繰り返す

        int commmaCount=0;//月日体重の区切りコンマのカウント用変数
        char devChar[] = ",";//分離する文字
        char* token = strtok(loadedData[i], devChar);//先頭からコンマで分離する

        while (token != NULL) {//コンマの数だけ分離する
            if(WEIGHT_COLUMN == commmaCount){
                weightList[i] = strtod(token,NULL);//char[]型からdouble型へ
                printf("%f\n",weightList[i]);
            }
            token = strtok(NULL, devChar);//分離
            commmaCount++;
        }

    }


    double weightAverage = getAverage(weightList,line);
    printf("------------\n"
            "あなたの平均体重は %f\n"
            "あなたの平均BMIは %fです。\n"
            "------------\n"
            ,weightAverage
            ,getBmi(weightAverage,tall));
}

void addData(void){
    printf("ファイルの読み込み中\n");

    //一旦現在のファイルの内容をプログラム中に読み出す
    char path[MAX_PATH] = FILE_NAME;
    char loadedData[MAX_DAY][LINE_LENGTH];//ファイルから読み取ったコンマを含む値
    int line = fileLoader(path,loadedData);
    double dataArray[MAX_DAY][4];//月日体重を格納する二次元配列

    for(int i=0;i<line;i++){
        char devChar[] = ",";//分離する文字
        char* token = strtok(loadedData[i], devChar);//先頭からコンマで分離する
        int commmaCount = 0;
        while (token != NULL) {//コンマの数だけ分離する
            dataArray[i][commmaCount] = strtod(token,NULL);
            token = strtok(NULL, devChar);//分離
            commmaCount++;
        }
    }


    char answer;
    printf("今日の日付を記録として使用しますか？(y/n)> ");
    scanf("%c",&answer);
    double year,month,day,weight;//全てdouble型

    if(answer == 'y'){

        time_t timeObj = time(NULL);
        struct tm *localTime = localtime(&timeObj);
        year = localTime->tm_year + 1900;
        month = localTime->tm_mon + 1;
        day = localTime->tm_mday;

    }else{

        printf("年を入力してください> ");
        scanf("%lf",&year);
        printf("月を入力してください> ");
        scanf("%lf",&month);
        printf("日を入力してください> ");
        scanf("%lf",&day);
        
    }

    printf("体重を入力してください> ");
    scanf("%lf",&weight);
    
    dataArray[line][0] = year;
    dataArray[line][1] = month;
    dataArray[line][2] = day;
    dataArray[line][3] = weight;

}