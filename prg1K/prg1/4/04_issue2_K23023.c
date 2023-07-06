//
//  04_issue2_K23023.c
//  prg1
//
//  Created by k23023kk on 2023/05/11.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int x;
    printf("x? ");
    scanf("%d",&x);
    if( x%2 == 0){
        printf("偶数だ。\n");
    }else if(x%2 == 1){
        printf("奇数だ。\n");
    }else{
        printf("どうしてこうなった\n");
    }
    return 0;
}
