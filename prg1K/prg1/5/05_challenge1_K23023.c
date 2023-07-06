//
//  05_challenge1_K23023.c
//  prg1
//
//  Created by k23023kk on 2023/05/18.
//

#include <stdio.h>
int main(int argc, const char * argv[]){
    int dayOfWeek,time,isOpen;
    printf("曜日? ");
    scanf("%d",&dayOfWeek);
    printf("時間帯? ");
    scanf("%d", &time);
    if(dayOfWeek == 0){//日曜
        isOpen = 0;
    }else if(dayOfWeek == 1){//月曜
        isOpen = 1;
    }else if(dayOfWeek == 2){//火曜
        isOpen = 1;
    }else if(dayOfWeek == 3){//水曜
        if(time)  isOpen = 1;
        else isOpen = 0;
    }else if(dayOfWeek == 4){//木曜
        isOpen = 1;
    }else if(dayOfWeek == 5){//金曜
        isOpen = 1;
    }else{//土曜
        if(!dayOfWeek) isOpen = 1;
        else isOpen = 0;
    }
    if(isOpen) printf("診察を行っています\n");
    else printf("診察は行っていません\n");
    return 0;
}
