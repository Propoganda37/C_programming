#ifndef LIBPROCESS_H

#define LIBPROCESS_H

#include <stdlib.h>

#define OK            0
#define ERR_SIZE      1
#define ERR_EMPTY     2
#define ERR_OVERFLOW  3

int is_prime(int num);
int fill_primes(int *array, int size);
int copy_and_insert(int *src, size_t src_size, int *dest, size_t *dest_size, int number_to_insert);


#endif 
