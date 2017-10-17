#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "rbim_char_list.h"

void rbim_char_list_init(struct rbim_char_list **root){
  *root = NULL;
  rbim_last_ref = NULL;
  rbim_add_chars_ptr = NULL;
  setlocale( LC_CTYPE, "" );
}

struct rbim_char_list *rbim_malloc(){
  struct rbim_char_list* new_char = malloc(sizeof(struct rbim_char_list));
  new_char->row = 0;
  new_char->col = 0;
  new_char->next = NULL;
  new_char->prev = NULL;
  return new_char;
}

void rbim_create_rchars(char *c, struct rbim_char_list **head, struct rbim_char_list **tail){
  struct rbim_char_list *current;
  int i = 0;
  while( c[i] != '\0' ){
    int len = mblen( &c[i], MB_CUR_MAX );
    if(i == 0){
      *head = rbim_malloc();
      strncpy((*head)->rchar, &c[i], len);
      current = *head;
    }else{
      struct rbim_char_list *new_char = rbim_malloc();
      strncpy(new_char->rchar, &c[i], len);
      current->next = new_char;
      new_char->prev = current;
      current = new_char;
    }
    i += len;
  }
  *tail = current;
}

