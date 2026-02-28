#ifndef _CONST_H__

#define _CONST_H__

#define LEN 51

#define ERR_NO_NAME 1
#define ERR_EMPTY 2
#define ERR_IO 3
#define ERR_OPEN 4
#define ERR_DATA 5

struct book
{
    char author[LEN];
    int sold;
};

#endif
