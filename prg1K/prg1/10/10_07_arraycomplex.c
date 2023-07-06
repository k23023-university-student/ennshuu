#include <stdio.h>
int main(int argc, const char * argv[]){
    int heights[5] = {0};//cm
    int weights[5] = {0};//kg
    int THRESHOLD = 23;
    for(int i=0;i<5;i++){
        printf("%d人目の身長と体重? ",i+1);
        scanf("%d %d",&heights[i],&weights[i]);
    }
    printf("--- しきい値を超えた人 ---\n");
    for(int i=0;i<5;i++){
        double height_meter = heights[i]/100.0 ;
        double bmi = weights[i]/(height_meter * height_meter);
        double standardWeight = (heights[i] - 100.0)*0.9;
        if(bmi > THRESHOLD){
            printf("%d人目のBMI: %f, 標準体重との差: %f\n",i+1,bmi,weights[i]-standardWeight);
        }
    }
    return 0;
}