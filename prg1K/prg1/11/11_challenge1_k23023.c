#include <stdio.h>
int main(int argc, const char * argv[]){
    char paragraph[] =
    "we hold these truths to be self-evident, that all men are created "
    "equal, that they are endowed by their creator with certain unalienable "
    "rights, that among these are life, liberty and the pursuit of "
    "happiness.";
    char searchTerm[13] = {'\0'};
    int index = -1;//単語の先頭文字のインデックス
    printf("searchTerm: ");
    scanf("%s",searchTerm);
    int searchTermCount = 0;

    for(int i=0;i<sizeof(paragraph)/(int)sizeof(char);i++){

        char currentSearchTermMoji = searchTerm[searchTermCount];
        char currentParagraphMoji = paragraph[i];
        if(currentParagraphMoji == currentSearchTermMoji){
            if(searchTermCount == 0) index = i;
            searchTermCount ++;
        }else if((currentParagraphMoji == ' ' || currentParagraphMoji == '.' || currentParagraphMoji == ',') && currentSearchTermMoji == '\0'){//現在の位置が文章の区切り目かつ現在の文字がヌル文字か確認

            break;
        }else{

            searchTermCount = 0;
            index = -1;
        }

    }
    printf("indexOf: %d\n",index);
    return 0;
}