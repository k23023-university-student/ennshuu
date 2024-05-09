//
//  04_issue2_K23023.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int x;
    printf("x? ");
    scanf("%d",&x);
    if( x%2 == 0){
        printf("even\n");
    }else{
        printf("odd\n");
    }
    return 0;
}
