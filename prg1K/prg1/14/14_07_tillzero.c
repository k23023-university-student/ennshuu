#include <stdio.h>
int main(int argc, const char * argv[]){
    int wallet = 1000;
    int amount = 1;
    while (wallet > 0)
    {
        printf("amount? ");
        scanf("%d",&amount);
        if(amount == 0) break;
        wallet = wallet - amount;
        printf("残高: %d\n",wallet);
    }
    printf("取引終了\n");
    return 0;
}
