#include <stdio.h>
int main(int argc, const char * argv[]){
    char inputText[11] ={'\0'};
    int count = 0;
    printf("入力(10文字以内): ");
    scanf("%s",inputText);
    while (inputText[count] != '\0')
    {
       putchar(inputText[count]);
       count ++;
    }
    
    putchar('\n');
    return 0;
}
