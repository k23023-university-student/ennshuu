#include <stdio.h>
int main(int argc, const char * argv[]){
    int x,y,temp;
    printf("x y? ");
    scanf("%d %d",&x,&y);
    if(x > y){
        temp = y;
        y = x;
        x = temp;
    }
    else if(y < x){
        //none
    }
    printf("%d %d\n",x,y);
    return 0;
}
