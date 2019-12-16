#include "universal.h"
#include <stdio.h>
#define LINE 256
#define WORD 30
int main(){
    int flag=0;
    int i=250;
    size_t k=0;
    char option[2];
    char first_line[LINE];
    char word[WORD];
    printf("insert the .txt file : ");
    gets(first_line);
    for (int i = 0;first_line[i]!='\0'; i++) {
        if(first_line[i]!=' ')
        word[k++]=first_line[i];
        //suppose after this iteration the sample becomes such as : catb || cata
        //TODO init char[2] to give it the option (a||b) then word[--k]='\0' (all outside of for loop)
        
    }
    option[0]=word[--k];//1)
    word[k]='\0';//2)
    if(option[0]=='a'){
        printf("printing the lines the include---> %s",word);
         printf("\n ");
      while(1){
          if(word[i]==EOF){
            break;
        }
          print_lines(word);
          
          i--;
      }
    }
    else{
        printf("looking for words similar to---> %s\n",word);
    while(1){
        if(word[i]==EOF){ ///EOF= End Of File
            break;
        }
      print_similar_words(word);
        
        i--;
    }
    }
    return 0;
 //apparently the solution is simple afff we just have to stop once we have EOF=-1 (means end of file)    
}