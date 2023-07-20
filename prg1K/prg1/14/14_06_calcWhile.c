#include <stdio.h>
int main(int argc, const char * argv[]){
    int count = 1;
    int n,sum = 0;
    printf("n? ");
    scanf("%d",&n);
    while (count <= n)
    {
        sum = sum + count;
        count++;
    }
    printf("1から%dまでの和は %d\n",n,sum);
    return 0;
}
