#include <stdio.h>
int main(int argc, const char * argv[]){
    int n = 0;
    printf("n? ");
    scanf("%d",&n);
    for(int i=n;i<3+n;i++){
        for(int j=1;j<10;j++){
            printf("%d x %d = %d\n",i,j,i*j);
        }
    }
    return 0;
}