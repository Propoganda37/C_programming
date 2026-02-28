#ifndef _MY_SNPRINTF_H_

#define _MY_SNPRINTF_H_

#include <stdlib.h>

void int_to_string(long int num, char *str, char *digits, size_t *len, size_t size);
int my_snprintf(char *str, size_t size, const char *format, ...);

#endif