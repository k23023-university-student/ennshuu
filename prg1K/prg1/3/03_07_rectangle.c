//
//  03_07_rectangle.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a,b;

    printf("a b\? ");
    scanf("%d %d",&a,&b);

    printf("perimeter = %d\n",2*a+2*b);
    printf("area = %d\n",a*b);

    return 0;
}
