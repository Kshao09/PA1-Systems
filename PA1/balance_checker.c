#include <stdio.h>
char get_word(char command[], int max_length) {
    char last_character;
    int i;
    for (i = 0; i < max_length - 1 && (command[i] = getchar()) != ' ' && command[i] != '\n'; i++);
    last_character = command[i];
    command[i] = '\0';
    return last_character;
}

char get_line(char command[], int max_length) {
    char last_character;
    int i;
    for (i = 0; i < max_length - 1 && (command[i] = getchar()) != '\n'; i++);
    last_character = command[i];
    command[i] = '\0';
    return last_character;
}

int equals(char str1[], char str2[]){
  int i = 0;
  while(1){
    if(str1[i] == '\0' && str2[i] == '\0')
      return 1;
    if(str1[i] == '\0' || str2[i] == '\0')
      return 0;
    if(str1[i] != str2[i])
      return 0;
    i++;
  }
}

int main(){
  char command[10];
	char str[400];
  char next_char;
  while(1){
    next_char = get_word(command, 10);
    if(equals(command, "quit")){
			break; 
		}	else if(equals(command, "check")) {
        if(next_char == '\n')
        printf("ERROR! Try again!\n");
        else{
          get_line(str, 400);
          printf("Checking %s...\n", str); 

          if(check(str) == 1) {
            printf("balanced");
          } else {
            printf("unbalanced");
          }
        }
		} else if(equals(command, "pair")){
        if(next_char == '\n')
          printf("ERROR! Try again!\n");
        else {
          get_line(str, 400);
          printf("Pairing %s...\n", str); 
        }
		} else {
			  printf("Invalid command! Try again!\n");
		}
  }
}
