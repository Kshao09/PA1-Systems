#include <stdio.h>
#define BUFSIZE 1000

char buf[BUFSIZE];//buffer for left parentheses

int bufp;//next free position in buf
struct sNode {
  char data;
  struct sNode* next;
};

int check(char str[]) {
    int i = 0;
    struct sNode* stack = NULL;

    while (str[i]) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            push(&stack, str[i]);
        if (str[i] == '}' || str[i] == ')'
            || str[i] == ']') {
            if (stack == NULL)
                return 0;
            else if (!is_balanced(str[i]))
                return 0;
        }
        i++;
    }

    if (stack == NULL)
        return 1; // balanced
    else
        return 0; // not balanced
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