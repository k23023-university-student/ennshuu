#include <stdio.h>
int main(int argc, const char * argv[]){
    int wallet=1000,amount,bank=1000;
    while(wallet > 0 && bank > 0){
        printf("amount? ");
        scanf("%d",&amount);
        if(amount == 0){
            printf("取引終了\n");
            break;
        }
        wallet = wallet+amount;
        bank = bank - amount;
        printf("銀行: %d 財布: %d\n",bank,wallet);
    }
    return 0;
}