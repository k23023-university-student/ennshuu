//
//  04_04_convert.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int nx,ny;
    double dx,dy;
    printf("nx ny? ");
    scanf("%d %d",&nx,&ny);
    dx = nx;
    dy = ny;
    printf("nx/ny = %d\n",nx/ny);
    printf("dx/ny = %f\n",dx/ny);
    printf("nx/dy = %f\n",nx/dy);
    return 0;
}
