#ifndef _CONST_H__

#define _CONST_H__

#define LEN 52

#define ERR_EMPTY 1
#define ERR_OVERFLOW 2
#define ERR_IO 3
#define ERR_OPEN 4
#define ERR_DATA 5

struct book
{
    char author[LEN];
    int sold;
};

#endif
