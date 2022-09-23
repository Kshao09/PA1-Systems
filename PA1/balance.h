#include <stdio.h>
#include <string.h>
#include <ctype.h>

extern char opening_symbols[51];
extern char closing_symbols[51];
int check(char str[]);
void pair(char list[]);
int equals(char str1[], char str2[]);
char get_word(char command[], int max_length);
char get_line(char command[], int max_length);
