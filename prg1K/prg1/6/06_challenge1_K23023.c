#include <stdio.h>
int main(int argc, const char * argv[]){
    int isPrimeNumber = 0;//0は素数であることを示す
    int n;//自然数n
    printf("n? ");
    scanf("%d",&n);
    for(int i=2;i<n;i++){
        if(n%i == 0){//1とその数以外の約数が存在したとき
            isPrimeNumber = 1;
            break;
        }
    }
    if(isPrimeNumber == 0) printf("素数です\n"); else printf("素数ではありません\n");
    return 0;
}