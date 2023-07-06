#include <stdio.h>
int main(int argc, const char * argv[]){
    int primeNumbers[100] = {0};//最大のメモリ数100とする
    int isPrime=0;//0=素数である
    int count=0;
    for(int i=2;i<100;i++){
        isPrime = 0;
        for(int j=2;j<i;j++){
            if(i%j == 0){
                isPrime = 1;
                break;
            }
        }
        if(isPrime == 0){
            primeNumbers[count] = i;
            count++;
        }
    }
    for(int i=0;i<count;i++){
        printf("%d, ",primeNumbers[i]);
    }
    printf("\n");
    return 0;
}