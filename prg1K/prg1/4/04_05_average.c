//
//  04_05_average.c
//  prg1
//
//  Created by k23023kk on 2023/05/11.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int no1,no2,no3;
    printf("No.1? ");
    scanf("%d",&no1);
    printf("No.2? ");
    scanf("%d",&no2);
    printf("No.3? ");
    scanf("%d",&no3);
    double ave = ((double)no1+(double)no2+(double)no3)/3;
    printf("average = %f\n",ave);
    return 0;
}
