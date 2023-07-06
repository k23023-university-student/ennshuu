#include <stdio.h>
int main(int argc, const char * argv[]){
    int n,sum=0,height;
    double average;
    printf("人数? ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("%d人目の身長は? ",i+1);
        scanf("%d",&height);
        sum += height;
    }
    average = sum/(double)n;
    printf("平均身長: %f\n",average);
    return 0;
}