#include <stdio.h>
#include <math.h>
int main(int argc, const char * argv[]){
    double theta,rad;
    printf("input: ");
    scanf("%lf",&theta);
    rad = (theta/360.0) * 2 * M_PI;
    double sinTheta = sin(rad);
    printf("sin (%f) = %f\n",theta,sinTheta);
    return 0;
}
