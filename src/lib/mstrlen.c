#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int mstrlen(char str[]){
  int char_count = 0;
  int i = 0;
  while(str[i] != '\0'){
    int len = mblen(&str[i], MB_CUR_MAX);
    char_count++;
    i += len;
  }
  return char_count;
}

void locale_init(){
  setlocale(LC_CTYPE, "");
}
