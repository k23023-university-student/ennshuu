//
//  05_04_ifelse2.c
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
    if(a < b) printf("aはb未満です\n");
    else printf("aはb以上です\n");
    return 0;
}
