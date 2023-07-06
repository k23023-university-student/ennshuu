#include <stdio.h>
int main(int argc, const char * argv[]){
    for(int j=1;j<=9;j++){
        for(int i=1;i<=9;i++){
            printf("%3d",i*j);
        }
        printf("\n");
    }
    return 0;
}