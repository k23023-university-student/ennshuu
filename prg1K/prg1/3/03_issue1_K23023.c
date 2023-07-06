//
//  03_issue1_K23023.c
//  prg1
//
//  Created by k23023kk on 2023/04/27.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int a = 6;//aの宣言と代入
    int b = 4;//bの宣言と代入
    int c = 2;//cの宣言と代入
    int d = a-(b/c);//dの宣言と計算
    printf("%d - (%d / %d) = %d\n",a,b,c,d);
    return 0;
}
