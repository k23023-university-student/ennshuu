//
//  04_challenge2_K23023.c
//  prg1
//
//  Created by k23023kk on 2023/05/11.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int total,legs,turu,kame;
    printf("total? ");
    scanf("%d",&total);
    printf("legs? ");
    scanf("%d",&legs);
    if(legs%2 != 0){//答えの正当性チェック
        printf("演算エラー\n");
        return 1;
    }
    kame = (legs-2*total)/2;
    turu = total - kame;
    if(kame > 0 && turu > 0){
        printf("turu = %d \nkame = %d\n",turu,kame);
    }else{
        printf("演算エラー");
        return 1;
    }
    return 0;
}
