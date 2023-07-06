#include <stdio.h>
int main(int argc, const char * argv[]){
    int a[5] = {1,2,3,4,5};
    int in_x,in_y;
    int x,y;
    int temp;
    printf("何番目を入れ替えますか? ");
    scanf("%d %d",&in_x,&in_y);
    x = in_x - 1;
    y = in_y - 1;
    temp = a[y];
    a[y] = a[x];
    a[x] = temp;
    for(int i=0;i<5;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
    return 0;
}