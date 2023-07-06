//
//  03_issue2_K23023.c
//  prg1
//
//  Created by k23023kk on 2023/04/27.
//

#include <stdio.h>
#include <math.h>
int main(int argc, const char * argv[]){
    int x,res;//入力データ用と結果用の変数を宣言
    int r= 2;//指数
    printf("x?");
    scanf("%d",&x);//キーボード入力からの内容を受け取る。
    res = pow(x,r);//r乗する
    printf("%d の%d乗は%dです。\n",x,r,res);//印字
    return 0;
}
