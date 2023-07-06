#include <stdio.h>
int main(int argc, const char * argv[]){
    int n;
    printf("n? ");
    scanf("%d",&n);
    int i=0;
    while(i<=n){
        printf("%d\n",n-i);
        i++;
    }
    return 0;
}