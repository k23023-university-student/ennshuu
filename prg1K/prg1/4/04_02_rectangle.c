//
//  04_02_rectangle.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    double width,height;//幅、高さ
    double area;//面積
    printf("width? ");
    scanf("%lf",&width);
    printf("height? ");
    scanf("%lf",&height);
    area = width * height;
    printf("area = %lf\n",area);
    return 0;
}
