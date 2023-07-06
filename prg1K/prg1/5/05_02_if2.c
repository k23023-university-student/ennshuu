//
//  05_02_if2.c
//  prg1
//
//  Created by k23023kk on 2023/05/18.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a,b;
    printf("a? ");
    scanf("%d",&a);
    printf("b? ");
    scanf("%d",&b);
    if(a == b) printf("aとbは等しいです\n");
    printf("計算終了\n");
    return 0;
}
