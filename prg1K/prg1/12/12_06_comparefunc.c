#include <stdio.h>
int maxOf(int x, int y){
    int returnValue;
    if(x>y) returnValue = x;
    else returnValue = y;
    return returnValue;
}
int main(int argc, const char * argv[]){
    int a,b;
    printf("a b? ");
    scanf("%d %d",&a,&b);
    printf("大きい方の値は %d\n",maxOf(a,b));
    return 0;
}