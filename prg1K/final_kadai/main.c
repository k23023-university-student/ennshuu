#include <stdio.h>
#include <string.h>
int fileLoader(char[],char* []);//第一引数はパス、第二引数は読み取ったファイルの値
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
        char saa[212];
        char* uu[21];
        strcpy(saa,"test.txt");
        fileLoader(saa,uu);
        switch (whatToDo)//作業内容で分岐する
        {
        case 1:
            break;
        case 2:
            break; 
        case 3:
            break;
        
        default:
            break;
        }
    }
    return 0;
}

int fileLoader(char path[] ,char* result[]){//体重データファイル読み込み関数 読み込み成功時 返り値0
    FILE *fp;
    fp = fopen(path,"r");
    if(fp == NULL){//ファイル読み込みエラー発生時
        printf("file load error");
        return 1;
    }
    char data[256];
     while(fgets(data,sizeof(data),fp)){

         printf("%s",data);


     }
    fclose(fp);
    return 0;
}