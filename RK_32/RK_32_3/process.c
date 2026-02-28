#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "inout.h"
#include "process.h"

int form(node_t *head, char *group, node_t **head_new)
{
    if (head == NULL)
    {
        return ERR_EMPTY;
    }
    node_t *next = NULL, *cur = NULL;
    student_t *student, *student_new;
    for ( ; head; head = next)
    {
        student = head->data;
        if (strcmp(group, student->group) == 0)
        {
            student_new = malloc(sizeof(student_t));
            if (student_new == NULL)
            {
                free_all(*head_new);
                return ERR_ALLOC;
            }
            *student_new = *student;
            node_t *new_node = create_node(student_new);
            if (new_node == NULL)
            {
                free_all(*head_new);
                return ERR_ALLOC;
            }
            if (*head_new == NULL)
            {
                *head_new = new_node;
            }
            else
            {
                cur->next = new_node;
            }
            cur = new_node;
        }
        next = head->next;
    }
    if (*head_new == NULL)
    {
        return ERR_NO_STUDENTS;
    }
    return 0;
}