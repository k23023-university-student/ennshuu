//
//  03_06_scancalc.c
//  prg1
//
//  Created by k23023kk on 2023/04/27.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
   int a,b;//使用する変数の準備
   printf("a b?");
   scanf("%d %d",&a,&b);
   printf("%d + %d = %d\n",a,b,a+b);
   printf("%d - %d = %d\n",a,b,a-b);
   printf("%d * %d = %d\n",a,b,a*b);
   printf("%d / %d = %d\n",a,b,a/b);
    return 0;
}
