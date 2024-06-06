#include <stdio.h>
int main(int argc, const char * argv[]){
    int x,sum=0;
    while(x != 0){
        printf("x? ");
        scanf("%d",&x);
        sum = sum + x;
        printf("sum: %d\n",sum);
    }
    printf("end\n");
    return 0;
}
