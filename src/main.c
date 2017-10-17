#include <stdio.h>
#include "mstrlen.h"

int main(void)
{
  char c[] = "日本語asdfで\\あそぼ\n";
  locale_init();
  printf("%d\n", mstrlen(c));
}
