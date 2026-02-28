#ifndef _CONST_H__

#define _CONST_H__

typedef struct node node_t;
struct node
{
    void *data;
    node_t *next;
};

struct student
{
    char *surname;
    int year;
    char *group;
};
typedef struct student student_t;

#define ERR_DATA 1
#define ERR_ALLOC 2
#define ERR_NO_STUDENTS 3
#define ERR_EMPTY 4
#define ERR_ARGS 5
#define ERR_OPEN 6

#endif