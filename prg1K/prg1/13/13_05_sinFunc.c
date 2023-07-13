#include <stdio.h>
#include <math.h>
double deg2Rad(double deg){
    return  (deg/360.0) * 2 * M_PI;
}
int main(int argc, const char * argv[]){
    double theta,rad;
    printf("input: ");
    scanf("%lf",&theta);
    rad = deg2Rad(theta);
    double sinTheta = sin(rad);
    printf("sin (%f) = %f\n",theta,sinTheta);
    return 0;
}
