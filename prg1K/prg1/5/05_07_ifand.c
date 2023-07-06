//
//  05_07_ifand.c
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
    if(a > 0 && b > 0){
        printf("aとbは正です\n");
    }else{
        printf("aとbのどちらかは負もしくは0です\n");
    }
    return 0;
}
