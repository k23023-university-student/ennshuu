#include <stdio.h>
void fileLoader(char[],char* []);//第一引数はパス、第二引数は読み取ったファイルの値
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
    }
    return 0;
}

void fileLoader(char path[] ,char* result[]){

    // FILE *fp;
    // fp = fopen("text.txt","r");
    // fgets(*result,10000,fp);
    // fclose(fp);
}