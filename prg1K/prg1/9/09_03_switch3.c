#include <stdio.h>
#include <math.h>
int main(int argc, const char * argv[]){
    double x;
    int m;
    int selected;
    printf("x? ");
    scanf("%lf",&x);
    printf("--- menu ---\n");
    printf("1: 絶対値, 2: 二乗, 3: 三乗\n");
    printf("menu no? ");
    scanf("%d",&m);
    switch (m)
    {
    case 1:
        printf("|%f| = %f\n",x,fabs(x));
        break;
    case 2:
        printf("%f ^ 2 = %f\n",x,pow(x,2));
        break;
    case 3:
        printf("%f ^ 3 = %f\n",x,pow(x,3));
        break;
    default:
        break;
    }
    return 0;
}
