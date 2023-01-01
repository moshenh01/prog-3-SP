//
// Created by Moshe Nahshon on 26/12/2022.
//

#ifndef ASSIGNMENT_3_SP_HEADERASSIGN_H
#define ASSIGNMENT_3_SP_HEADERASSIGN_H
#include <stdlib.h>
#define LINE 256
#define WORD 30

int substring( char * str1, char * str2);
int similar(char *s, char *t, int n);
void print_lines(char * str);
int getWord(char w[]);
void print_similar_words(char * str);
int getLine(char s[]);

#endif //ASSIGNMENT_3_SP_HEADERASSIGN_H
