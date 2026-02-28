#ifndef _CONST_H__

#define _CONST_H__

#include <stdint.h>

#define ERR_ARG 53
#define ERR_EMPTY_STR 2
#define ERR_OVERFLOW 3
#define ERR_DATA 4
#define ERR_OPEN 5
#define ERR_SIZE 6
#define ERR_EMPTY 7
#define ERR_DIGIT 8
#define ERR_NOT_FOUND 9

#define LEN_NAME 31
#define LEN_MANUFACTER 16

struct product
{
    char name[LEN_NAME];
    char manufacter[LEN_MANUFACTER];
    uint32_t price;
    uint32_t quantity;
};

#endif
