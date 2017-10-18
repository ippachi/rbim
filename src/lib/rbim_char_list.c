#include <stdio.h>
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
  struct rbim_char_list *current = NULL;
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

void rbim_delete_rchar(struct rbim_char_list *delete_ptr){
  if(delete_ptr == NULL) return;
  delete_ptr->prev->next = delete_ptr->next;
  delete_ptr->next->prev = delete_ptr->prev;
  free(delete_ptr);
}

void rbim_concat_rchars(struct rbim_char_list **root, struct rbim_char_list *head, struct rbim_char_list *tail){
  struct rbim_char_list *current = *root;
  if(head == NULL) return;
  if(current == NULL){
    *root = head;
    return;
  }
  for(; current->next != NULL; current = current->next);
  current->next = head;
}

void rbim_buf(struct rbim_char_list **ref, char *buf){
  int str_len = 0;
  while(*ref != NULL && str_len < BUF_SIZE){
    sprintf(buf, "%s%s", buf, (*ref)->rchar);
    str_len += strlen((*ref)->rchar);
    if(str_len >= BUF_SIZE){
      return;
    }
    *ref = (*ref)->next;
  }
}

void rbim_output_file(struct rbim_char_list *root, char *filename){
  FILE *fp = fopen(filename, "w+");
  char buf[BUF_SIZE];
  struct rbim_char_list *current;
  current = root;
  while(current != NULL){
    memset(buf, '\0', sizeof(buf));
    rbim_buf(&current, buf);
    fputs(buf, fp);
  }
}
