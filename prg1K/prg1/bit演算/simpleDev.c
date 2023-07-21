#include <stdio.h>
void devB(int a,int b,int c){
    if(a || c) printf("GO\n"); else printf("NO\n");
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
