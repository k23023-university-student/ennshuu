//
//  04_challenge1_K20000.c
//  prg1
//
//

#include <stdio.h>
#include <math.h>
int main(int argc, const char * argv[]){
    int num;
    int left_number;
    int h,t,z;
    printf("三桁の整数を入力> ");
    scanf("%d",&num);
    if(num > 999){
        printf("3桁より多い整数は無効\n");
        return 1;
    }
    h = num/100;
    left_number = num-(h*100);
    t = left_number/ 10;
    left_number = left_number - (t*10);
    z = left_number;
    printf("reverse x = %d%d%d\n",z,t,h);

    return 0;
}//123
