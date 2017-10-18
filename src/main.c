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
  while(1){
    char buf[1024];
    if(strcmp(buf, "quit\n") == 0) break;
    fgets(buf, sizeof(buf), stdin);
    rbim_create_rchars(buf, &head, &tail);
    rbim_concat_rchars(&root, head, tail);
  }
  current = root;
  while(current != NULL){
    printf("%s", current->rchar);
    current = current->next;
  }

  rbim_output_file(root, "test.c");
}
