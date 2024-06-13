#include <stdio.h>
int main(int argc, const char * argv[]){
    int ch,answer=0;
    int isMinus=0;//0はマイナスではない
    int sujiCh;
    int currentNum = 0;
    printf("equation? ");
    while((ch = getchar()) != '='){
        switch (ch)
        {//文字にスペースが来たときに計算を行う
        //スペースを全く入力しなかった場合不具合を発生する
        case ' ':

            break;
        case '+':
            isMinus = 0;
            continue;
            break;
        case '-':
            isMinus = 1;
            continue;
            break;
        default:
            sujiCh = ch - 48;//文字から数字へ
            currentNum = currentNum * 10 + sujiCh;
            continue;
            break;
        }
        if(isMinus == 0){
            answer = answer +  currentNum;
        }else{
            answer = answer -  currentNum;
        }
        currentNum = 0;
    }
    printf("answer: %d\n",answer);
    return 0;
}
