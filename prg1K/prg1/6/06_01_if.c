//
//  06_01_if.c
//  prg1
//
//  Created by k23023kk on 2023/05/25.
//


#include <stdio.h>
int main(int argc, const char * argv[]){
    int a;
    printf("a? ");
    scanf("%d",&a);
    if(a > 0) printf("aは正の値です\n");
    else if(a < 0) printf("aは負の値です\n");
    else printf("aは0です\n");
    return 0;
}