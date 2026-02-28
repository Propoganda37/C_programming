#ifndef _ITEM_ARR__

#define _ITEM_ARR__

#include "error.h"

int itemar_read(FILE *f, item_t *pitem, int *n);
void itemar_print(FILE *f, item_t *pitems, int n);
void itemar_sort(item_t *pitem, int n);
int find(item_t *pitems, int n, char start[NAME_LEN + 2]);
void print_error(int rc);

#endif
