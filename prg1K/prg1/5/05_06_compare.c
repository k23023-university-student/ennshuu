//
//  05_06_compare.c
//  prg1
//
//  Created by k23023kk on 2023/05/18.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a,b;
    printf("a b? ");
    scanf("%d %d",&a,&b);
    if(a > b) printf("a > b\n");
    else if(a == b) printf("a == b\n");
    else printf("a < b\n");
    return 0;
}
