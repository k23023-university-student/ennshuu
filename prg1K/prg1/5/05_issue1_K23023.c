//
//  05_issue1_K23023.c
//  prg1
//
//  Created by k23023kk on 2023/05/18.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int x;
    printf("x? ");
    scanf("%d",&x);

    if(x%2 == 0 && x > 0) printf("2の倍数です\n");
    else printf("2の倍数ではありません\n");
    if(x%3 == 0 && x > 0) printf("3の倍数です\n");
    else printf("3の倍数ではありません\n");
    return 0;
}
