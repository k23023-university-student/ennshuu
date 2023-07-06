#include <stdio.h>
int factOf(int num){
    int kaizyou = 1;
    for(int i=num;i>=1;i--){
       kaizyou = kaizyou * i;
    }
    return kaizyou;
}
int main(int argc, const char * argv[]){
    int n;
    printf("n? ");
    scanf("%d",&n);
    printf("%dの階乗は %d\n",n,factOf(n));
    return 0;
}