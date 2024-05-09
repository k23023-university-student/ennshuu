//
//  04_03_roundoff.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    double dx;
    printf("dx? ");
    scanf("%lf",&dx);
    printf("dx/2 = %f\n",dx/2);
    int nx = (int)dx;
    printf("nx = %d\n",nx);
    printf("nx/2 = %d\n",nx/2);
    return 0;
}
