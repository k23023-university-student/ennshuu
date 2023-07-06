#include <stdio.h>
int main(int argc, const char * argv[]){
    char inputText[21] = {'\0'};
    printf("input(20文字以下): ");
    scanf("%s",inputText);
    int notKaibun = 0;//回文ではないとき、1
    int kosuu;//配列の実際に値が存在する要素の個数
    while(inputText[kosuu] != '\0'){
        kosuu++;
    }
    for(int i=0;i<kosuu;i++){
        if(inputText[i] != inputText[kosuu-1-i]){
            notKaibun = 1;
            break;
        }
    }
    if(notKaibun == 0) printf("回文OK\n");
    else printf("回文NG\n");
    return 0;
}