
#include <stdio.h>
#include <math.h>
double calcArea(double r){//面積を求める関数
    return M_PI * r * r;
}
double calcCircumference (double r){//円周を求める関数
    return 2 * M_PI * r;
}
int main(int argc, const char * argv[]){
    double r;
    printf("input r: ");
    scanf("%lf",&r);
    printf("%f %f\n",calcArea(r),calcCircumference(r));
    return 0;
}
