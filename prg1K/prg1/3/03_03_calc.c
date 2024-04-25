//
//  03_03_calc.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a = 3;//aを宣言して3を代入
    int b = 4;//bを宣言して4を代入
    int c = 2;//cを宣言して2を代入
    int d = 8;//dを宣言して8を代入
    int e = a+b*c/d;
    
    printf("%d + %d * %d / %d = %d\n",a,b,c,d,e);
    return 0;
}
