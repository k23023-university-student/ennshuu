#include <stdio.h>
int main(int argc, const char * argv[]){
    int input;
    int counter=0;
    printf("input? ");
    scanf("%d",&input);
    while(input != 1){
     for(int i=2;i<=input;i++){
        if(input%i == 0){
            input = input/i;
            if(counter != 0 ) printf(", ");
            printf("%d",i);
            break;
        }
     }
     counter++;
    }
    printf("\n");
    return 0;
}