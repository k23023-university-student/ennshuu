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
    if(x%2 == 0) printf("xは2の倍数です\n");
    else printf("xは2の倍数ではありません\n");
    if(x%3 == 0) printf("xは3の倍数です\n");
    else printf("xは3の倍数ではありません\n");
    return 0;
}
