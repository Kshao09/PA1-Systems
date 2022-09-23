#include <stdio.h>
#include "balance.h"
#define BUFSIZE 1000

char buf[BUFSIZE];//buffer for left parentheses
int bufp;//next free position in buf

int check(char str[]) {
  if (strlen(opening_symbols) == 0 && strlen(closing_symbols) == 0) {
    opening_symbols[0] = '(';
    opening_symbols[1] = '\0';
    closing_symbols[0] = ')';
    closing_symbols[1] = '\0';
  }
  int length = strlen(str);

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < strlen(opening_symbols); j++) {
      if (str[i] == opening_symbols[j]) {
        push(str[i]);
      } else {
        continue;
      }
    }

    if (pop() == EOF) {
      return 1;
    } else {
        char check_opening_symbol = pop();
        char curr_closing_symbol = str[1];

        for (int j = 0; j < strlen(closing_symbols); i++) {
          if (closing_symbols[j] == curr_closing_symbol) {
            if (check_opening_symbol == opening_symbols[j]) {
              break;
            } else {
              return 0;
            }
          }
        }
    }
  }
  
  return bufp;
}

void push(char c){
  if(bufp == BUFSIZE)
    ;
  buf[bufp++] = c;
}

char pop(){
  if(bufp == 0)
    return EOF;
  return buf[--bufp];
}

int is_balanced(char input[]){
  int len = strlen(input);
  for(int i = 0; i < len;i++)
    if(input[i] == '(')
      push('(');
    else if(pop() == EOF)
      return 0;
  return bufp == 0;
}

void print_binary(int n){
  if(n < 0){
    putchar('-');
    print_binary(-n);
  }else if(n < 2){
    putchar('0' + n);
  }else{
    print_binary(n/2);
    putchar('0' + n % 2);
  }
}

int main(void) {
  print_binary(123);
  printf("\nisbalanced(%s)=%d\n", "()(())",
    is_balanced("(())()"));
  return 0;
}
