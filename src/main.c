#include <stdio.h>
#include "rbim_char_list.h"

typedef struct rbim_char_list rbim_char_list;

int main(void)
{
  rbim_char_list *root;
  rbim_char_list *head;
  rbim_char_list *tail;
  rbim_char_list *current;
  rbim_char_list_init(&root);
  rbim_create_rchars("こんにちは\n", &head, &tail);
  current = head;
  while(current != NULL){
    printf("%s", current->rchar);
    current = current->next;
  }
  current = tail;
  while(current != NULL){
    printf("%s", current->rchar);
    current = current->prev;
  }
}
