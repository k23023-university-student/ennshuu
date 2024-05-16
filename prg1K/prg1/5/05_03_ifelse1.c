//
//  05_03_ifelse1.c
//  prg1
//
//  Created by k23023kk on 2023/05/18.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a;
    printf("a? ");
    scanf("%d",&a);
    if(a >= 0) printf("aは正の値もしくは0です\n");
    else printf("aは負の値です\n");
    printf("計算終了\n");
    return 0;
}
