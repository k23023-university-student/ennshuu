//
//  05_09_calcFor.c
//  prg1
//
//  Created by k23023kk on 2023/05/18.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int sum = 0;
    for(int i=1;i<=10;i++){
        sum = sum + i;
    }
    printf("%d\n",sum);
    return 0;
}
