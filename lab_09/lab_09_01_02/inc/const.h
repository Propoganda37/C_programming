#ifndef _CONST_H__

#define _CONST_H__

#define ERR_OK 0
#define ERR_EMPTY_FILE 1
#define ERR_DATA 2
#define ERR_ALLOC 3
#define ERR_FILE 4
#define ERR_NOT_FOUND 5
#define ERR_ARGS 6

typedef struct item
{
    char *name;
    double m;
    double v;
} item_t;

#endif
