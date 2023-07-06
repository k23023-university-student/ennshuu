#include <stdio.h>
int main(int argc, const char * argv[]){
    char inputText[21] = {'\0'};
    printf("input(20文字以下): ");
    scanf("%s",inputText);
    int count = 0;
    int count_a;
    while (inputText[count] != '\0')
    {
        if(inputText[count] == 'a'){
            count_a++;
        }
        count++;
    }
    printf("aの数: %d\n",count_a);
    return 0;
}
