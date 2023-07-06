#include <stdio.h>
int main(int argc, const char * argv[]){
    int heights[5];
    double sum=0;
    for(int i=0;i<5;i++){
        double input;
        printf("%d人目の身長? ",i+1);
        scanf("%lf",&input);
        heights[i] = input;
    }
    for(int i=0;i<5;i++){
        sum = sum + heights[i];
    }
    printf("平均身長 = %f\n",sum/5);
    return 0;
}