//
//  03_05_scan2.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    double a,b;//使用する変数を宣言

    printf("a b? ");
    scanf("%lf %lf",&a,&b);//キーボード入力から２つ受け取る
    printf("a = %f, b = %f\n",a,b);//表示　
    
    return 0;
}
