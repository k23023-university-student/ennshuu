//
//  04_challenge1_K20000.c
//  prg1
//
//  Created by k23023kk on 2023/05/11.
//

#include <stdio.h>
#include <math.h>
int main(int argc, const char * argv[]){
    int num,reversed;
    int left_number;
    printf("三桁の整数を入力> ");
    scanf("%d",&num);
    if(num > 999){
        printf("3桁より多い整数は無効\n");
        return 1;
    }
    left_number = num;
    reversed = 0;
    for(int i=0;i<3;i++){
        //100の位から順に処理する
        int keta = pow(10,2-i);//現在の処理桁10✖️n
        int tmp = left_number/keta;//(一旦整数に型変換しておく)
        left_number = left_number-(tmp*keta);
        reversed += tmp * pow(10,i);
    }
    printf("reversedNum = %d\n",reversed);
    return 0;
}//123
