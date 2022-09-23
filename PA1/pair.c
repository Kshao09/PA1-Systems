#include <stdio.h>
#include "balance.h"

void pair(char list[]) {
  for (int i = 0; i < strlen(list); i++) {
    if (i == strlen(list)) {
      opening_symbols[i] = '\0';
      closing_symbols[i] = '\0';
      break;
    }
    else if (list[i] == '(' || list[i] == '{' || list[i] == '[') {
      opening_symbols[i] = list[i];
    }
    else if (list[i] == ')' || list[i] == '}' || list[i] == ']') {
      closing_symbols[i] = list[i];
    }
    else continue;
  }
}
