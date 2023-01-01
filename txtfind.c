//
// Created by Moshe Nahshon on 26/12/2022.
//
#include <stdio.h>
#include <string.h>
#include "header.h"




int getLine(char s[]){
    char ch;
    int count = 0;
    for (int i = 0; ( i  < LINE ) && (( ch = getchar()) != EOF) && ( ch !='\n' ); ++i ){
        s[i] = ch;
        count++;
        //printf(" %c",ch);
    }
    s[count] = '\0';
    //printf("count is: %d\n",count);
    return count;
}
int getWord(char w[]){
    char ch;
    int count = 0;
    for (int i = 0; ( i  < WORD ) && (( ch = getchar()) != EOF) && ( ch !='\n') && ( ch !='\t') && (ch != ' ') ; ++i ){
        w[i] = ch;
        count++;
        //printf(" %c",ch);
    }
    w[count] = '\0';
    return count;
}
int substring( char * str1, char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len2 > len1){return 0;}
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str1[i + j] != str2[j])
                break;
        }

        if (j == len2)
            return 1;
    }
    return 0;
}

int similar(char *s, char *t, int n){
    int lenS = strlen(s),lesT =strlen(t);
    int diff = abs(lenS - lesT);
    if(diff > n){return 0;}
    int i = 0 , j = 0;

    while( ( i < lenS) && (j < lesT) ) {
        if (s[i] != t[j]) {
            i++;
            n--;
        } else {
            i++;
            j++;
        }
    }
    if ((n < 0) || ( (lenS - i) > n))
        return 0;
    return 1;
}
void print_lines(char * str){
    char arrline [LINE];
    while(getLine(arrline)){
        if(substring(arrline,str)){
            puts(arrline);
        }
    }
}
void print_similar_words(char * str){
    char word[WORD];

    while(getWord(word)) {
        //printf("##%s\n",word);
        if(similar(word,str,1))
                printf("%s\n",word);
    }
}
int main(){

    char word[WORD];
    char selctopt;
    getWord(word);
    
    selctopt = getchar();
    getchar();
    getchar(); 
   // int x = similar("cat","crat",1);
    //printf("%d",x);
    
    
    //printf("char: %c word: %s\n",selctopt,word);
    if(selctopt != 'a' && selctopt != 'b'){
        printf("Bad selection.\n");

    }
    if(selctopt == 'a') {
       // printf("Printing lines that contain the word '%s':\n\n",word);
        print_lines(word);
    }
    if(selctopt == 'b') {
       // printf("Printing the similar words for '%s' up to 1 degree of similarity:\n", word);
        print_similar_words(word);
        
    }

    return 0;
}







