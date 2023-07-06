#include <stdio.h>
int main(int argc, const char * argv[]){
    int wallet=1000,amount;
    while(wallet >= 0){
        printf("amount? ");
        scanf("%d",&amount);
        wallet = wallet-amount;
        printf("残高: %d\n",wallet);
    }
    return 0;
}