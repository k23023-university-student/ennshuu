//
//  04_issue1_K20000.c
//  prg1
//
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    double height,weight;
    double standardWeight,bmi;
    printf("height? ");
    scanf("%lf",&height);
    printf("weight? ");
    scanf("%lf",&weight);
    standardWeight = (height-100)*0.9;
    bmi = weight / ((height/100) * (height/100));
    printf("standardWeight = %f\n",standardWeight);
    printf("bmi = %f\n",bmi);
    return 0;
}
