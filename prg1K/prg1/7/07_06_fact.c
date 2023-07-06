#include <stdio.h>
int main(int argc, const char * argv[]){
    int x,n;
    printf("x n? ");
    scanf("%d %d",&x,&n);
    int times_x = 1;
    for(int i=1;i<=n;i++){
        times_x = times_x*2;
    }
    printf("%d^%d = %d\n",x,n,times_x);
    return 0;
}