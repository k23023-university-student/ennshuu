#include <stdio.h>
int main(int argc, const char * argv[]){
    int a,b,max;
    printf("a b? ");
    scanf("%d %d",&a,&b);
    if(a>b) max = a;
    else max = b;
    printf("大きい方の値は %d\n",max);
    return 0;
}