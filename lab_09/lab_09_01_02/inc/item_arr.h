#ifndef _ITEM_ARR__

#define _ITEM_ARR__

#include <stdio.h>

#include "const.h"

int itemar_read(FILE *f, item_t **pitem, size_t *n);
void itemar_print(FILE *f, item_t *pitems, size_t n);
void itemar_sort(item_t *pitem, size_t n);
int find(item_t *pitems, size_t n, char *start, item_t **found_items, size_t *new_n);
void free_items(item_t *items, size_t n);
void print_error(int rc);

#endif
