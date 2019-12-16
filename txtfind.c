/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#define LINE 256
#define WORD 30
#include <stdio.h>
int is_word(char *s){
size_t i;
int flag=0;
for (i=0; s[i+1]!='\0'; i++)
{
    if((s[i]==' ')||(s[i]=='\t')){
        flag=1;
        break;
    }  
}
if(flag){
    return 0;
}
return 1;
}
int Getline(char s[]){
    int i,counter=0;
    int flag=0;
    printf("insert the desired line: ");
    gets(s);
    for (i = 0; (*(s+i)!=0); i++) {
    //if(*(s+i)!=' '){
        counter++;
   // }
    }
    if(counter>=LINE){
        printf("you have exceeded the limits of 255 chars !!\n");
    }
    return counter;
}
int Getword(char s[]){
int i, counter=0;
int flag=0;
printf("insert the desired word: ");
gets(s);
for (i = 0; s[i]!=0; i++)
{
    counter++;
}
if(counter>=WORD){
    printf("you have exceeded the limits of 29 chars !!\n");
}
else if(!(is_word(s))){
printf("you didn't enter a word !\n");
}
return counter;
}
int size(char *str){
    int counter=0;
    for (size_t i = 0; str[i]!='\0'; i++)
    {
        counter++;
    }
    return counter;
    
}
int substring( char * str1, char * str2){
    if(size(str2)>size(str1)){
        return 0; // like errror 404
    }
    size_t i;
    int flag=0;
    int counter=0;
    for ( i = 0; *(str1+i)!='\0'; i++)
    {
        //printf("\n%d",counter);
        if(str1[i]==str2[counter]){
            counter++;
            if(counter==size(str2)){
            flag= 1;
        }
        }
        else{
            counter=0;
        }
    }
    //TODO calculate the size of str2
    if(flag){
        return 1;
    }
    return 0;
    
}
int similar (char *s, char *t, int n){
    if(size(t)>size(s)){
        return 0; //like error 404
    }
    size_t i;
    int j=0;
    int error=0;
    for (i = 0; s[i]!='\0'; i++)
    {
        if(s[i]==t[j]){
            j++;
        }
        else{
            error++;
        }
    }
    if(error==n){
        return 1;
    }
    return 0;
    
}
void print_lines(char * str){
    char str_1[LINE];
    gets(str_1);
    if(substring(str_1,str)){
        printf("%s\n",str_1);
    }
}

void clean(char *str){
for (int i = 0; str[i]!='\0'; i++) {
    str[i]='\0';
}
}
void print_similar_words(char * str){
    int index=0;
    size_t i;
    char str_new[LINE];
   // printf("\nenter the desired line : \n");
    gets(str_new);
    
    //instead of ------>  apparently scanf("%s",str_new); doesn't respect " "(space)
    //gets works perfectly (tested in 14/12/2019)    
    char word[WORD];  
    for (i=0; str_new[i]!='\0'; i++)
    {
        if(str_new[i]!=' '){
         word[index]=str_new[i];
         index++;   
        }
        else{ ///if == " "
     // it appears there is a problem that the old string is overwritten but still has some letters from the old one!
    //so we try this technique (before we zero the index we put "\0")
        word[index]='\0';
        index=0;
            if((similar(word,str,1))||(similar(word,str,0))){
                
                puts(word);
                printf("\n");
                
            }
           // clean(word);
        }
    }
    if(str_new[size(str_new)-1]!=' '){
        //then last word wasn't recorded 
        //we check it too
        word[index]='\0';
        if((similar(word,str,1))||(similar(word,str,0))){
                
                puts(word);
                printf("\n");
            }
           // clean(word);
        
    }
    
}
// int main(){
//     char str1[WORD];
//     char str2[WORD];
//     gets(str1);
//     printf("\n");
//     gets(str2);
//     printf("%d",substring(str1,str2));
    
    
//     return 0;
// }
// void run_txtfind(){
//     int flag=0;
//     int i=250;
//     size_t k=0;
//     char option[2];
//     char first_line[LINE];
//     char word[WORD];
//     printf("insert the .txt file : ");
//     gets(first_line);
//     for (int i = 0;first_line[i]!='\0'; i++) {
//         if(first_line[i]!=' ')
//         word[k++]=first_line[i];
//         //suppose after this iteration the sample becomes such as : catb || cata
//         //TODO init char[2] to give it the option (a||b) then word[--k]='\0' (all outside of for loop)
        
//     }
//     option[0]=word[--k];//1)
//     word[k]='\0';//2)
//     if(option[0]=='a'){
//         printf("printing the lines the include---> %s",word);
//          printf("\n ");
//       while(1){
//           if(word[i]==EOF){
//             break;
//         }
//           print_lines(word);
          
//           i--;
//       }
//     }
//     else{
//         printf("looking for words similar to---> %s\n",word);
//     while(1){
//         if(word[i]==EOF){ ///EOF= End Of File
//             break;
//         }
//       print_similar_words(word);
        
//         i--;
//     }
//     }
//   // return 0;
//  //apparently the solution is simple afff we just have to stop once we have EOF=-1 (means end of file)    
// }


