//
//  04_challenge2_K23023.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){

    int totals,legs,crane,tortoise;

    printf("total? ");
    scanf("%d",&totals);

    printf("legs? ");
    scanf("%d",&legs);

    if(legs%2 != 0){//答えの正当性チェック
        printf("cannot be combined\n");
        return 1;
    }

    tortoise = (legs-2*totals)/2;

    crane = totals - tortoise;

    if(tortoise > 0 && crane > 0){
        printf("crane = %d, tortoise = %d\n",crane,tortoise);
    }else{
        printf("演算エラー");
        return 1;
    }

    return 0;
}
