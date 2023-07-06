#include <stdio.h>
int addOf(int x,int y);
int main(int argc, const char * argv[]){
    int a,b;
    printf("a b? ");
    scanf("%d %d",&a,&b);
    printf("和は %d\n",addOf(a,b));
    return 0;
}
int addOf(int x,int y){
    int sum;
    sum = x + y;
    return sum;
}