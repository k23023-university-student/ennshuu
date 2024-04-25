//
//  03_06_scancalc.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){
   int a,b;//使用する変数の準備

   printf("a b? ");
   scanf("%d %d",&a,&b);

   printf("%d + %d = %d\n",a,b,a+b);
   printf("%d - %d = %d\n",a,b,a-b);
   printf("%d * %d = %d\n",a,b,a*b);
   printf("%d / %d = %d\n",a,b,a/b);
    return 0;
}
