#ifndef _ITEM_H__

#define _ITEM_H__

#include "const.h"

int item_read(FILE *f, item_t *pitem);
void item_print(FILE* out_file, item_t *item);
int item_cmp_by_thickness(const void *item1, const void *item2);
int find_item(const void *item, char *start);

#endif
