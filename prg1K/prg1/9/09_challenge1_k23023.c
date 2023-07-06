#include <stdio.h>
int main(int argc, const char * argv[]){
    int ch,answer=0;
    int isMinus=0;//0はマイナスではない
    int sujiCh;
    printf("equation? ");
    while((ch = getchar()) != '='){
        switch (ch)
        {
        case ' ':
            continue;
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
            break;
        }
        sujiCh = ch - 48;//文字から数字へ
        if(isMinus == 0){
            answer = answer +  sujiCh;
        }else{
            answer = answer -  sujiCh;
        }
    }
    printf("answer: %d\n",answer);
    return 0;
}
