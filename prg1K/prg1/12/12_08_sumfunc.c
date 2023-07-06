#include <stdio.h>
int sumOf(int num){
    int sum = 0;
    for(int i=1;i<=num;i++){
        sum = sum + i;
    }
    return sum;
}
int main(int argc, const char * argv[]){
    int n;
    printf("n? ");
    scanf("%d",&n);
    printf("1から%dまでの和は %d\n",n,sumOf(n));
    return 0;
}