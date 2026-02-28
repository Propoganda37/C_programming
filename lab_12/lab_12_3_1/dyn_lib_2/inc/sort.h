#ifndef _SORT_H__

#define _SORT_H__

#include <stdlib.h>

int compare_numbers(const void *a, const void *b);
void swap(void *pa, void *pb, size_t size);
void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif

