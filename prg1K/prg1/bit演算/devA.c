#include <stdio.h>
void devB(int a,int b,int c){
    int isGo=1;//1のときNO
    if(a == 1){
        isGo = 0;
    }else if(a == 0 && (b == 1 && c == 1)){
        isGo = 0;
    }else if(b == 0 && c == 1){
        isGo = 0;
    }else{
        isGo = 1;
    }


    if(isGo == 0) printf("GO\n");
    else printf("NO\n");
}
int main(int argc, const char * argv[]){
    devB(0, 0, 0);
    devB(0, 0, 1);
    devB(0, 1, 0);
    devB(0, 1, 1);
    devB(1, 0, 0);
    devB(1, 0, 1);
    devB(1, 1, 0);
    devB(1, 1, 1);
    printf("\n");   
    return 0;
}
