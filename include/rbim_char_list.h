#ifndef RBIM_CHAR_LIST_H
#define RBIM_CHAR_LIST_H

#define MAX_CHAR_SIZE 3
#define BUF_SIZE 2048

struct rbim_char_list{
  char rchar[MAX_CHAR_SIZE];
  int row;
  int col;
  struct rbim_char_list *next;
  struct rbim_char_list *prev;
};

static int rbim_current_row;
static int rbim_current_col;
static char *rbim_add_chars_ptr;
static struct rbim_char_list *rbim_last_ref;

void rbim_char_list_init(struct rbim_char_list **root);
void rbim_create_rchars(char *c, struct rbim_char_list **head, struct rbim_char_list **tail);
void rbim_delete_rchar(struct rbim_char_list *delete_ptr);
void rbim_concat_rchars(struct rbim_char_list **root, struct rbim_char_list *head, struct rbim_char_list *tail);
struct rbim_char_list *rbim_buf(struct rbim_char_list *ref, char *buf);
void rbim_output_file(struct rbim_char_list *root, char *filename);
struct rbim_char_list *rbim_malloc();

#endif
