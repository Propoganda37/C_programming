#ifndef _ERROR_H__

#define _ERROR_H__

#define ERR_OK 0
#define ERR_EMPTY_FILE 1
#define ERR_DATA 2
#define ERR_OVERFLOW 3
#define ERR_FILE 4
#define ERR_NOT_FOUND 5
#define ERR_ARGS 6

#define NAME_LEN 25
#define N_MAX 15

struct item
{
    char name[NAME_LEN + 1];
    double m;
    double v;
};
typedef struct item item_t;

#endif
