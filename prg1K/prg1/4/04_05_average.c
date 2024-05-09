//
//  04_05_average.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int h1,h2,h3;
    printf("No.1? ");
    scanf("%d",&h1);
    printf("No.2? ");
    scanf("%d",&h2);
    printf("No.3? ");
    scanf("%d",&h3);
    double ave = ((double)h1+(double)h2+(double)h3)/3;
    printf("average = %f\n",ave);
    return 0;
}
