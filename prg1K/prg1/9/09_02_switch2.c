#include <stdio.h>
int main(int argc, const char * argv[]){
    int ch;
    while((ch = getchar()) != '\n'){
        if(ch != ' '){
            printf("%c",ch);
        }else{
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
