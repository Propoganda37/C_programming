#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "inout.h"

node_t *create_node(student_t *student)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) 
    {
        return NULL;
    }
    new_node->data = student;
    new_node->next = NULL;
    return new_node;
}

int read_student(FILE *f, student_t *student)
{
    char tmp[2];
    student->surname = NULL;
    size_t len = 0;
    ssize_t read = 0;
    read = getline(&(student->surname), &len, f);
    if (read == -1)
    {
        free(student->surname);
        return ERR_DATA;
    }
    if (student->surname == NULL)
    {
        return ERR_ALLOC;
    }
    if (student->surname[read - 1] == '\n')
    {
        student->surname[read - 1] = '\0';
        read--;
    }
    if (read <= 0 || read > 30)
    {
        free(student->surname);
        return ERR_DATA;
    }

    if (fscanf(f, "%d", &student->year) != 1)
    {
        free(student->surname);
        return ERR_DATA;
    }
    if (student->year <= 0)
    {
        free(student->surname);
        return ERR_DATA;
    }
    fgets(tmp, sizeof(tmp), f);

    student->group = NULL;
    len = 0;
    read = 0;
    read = getline(&(student->group), &len, f);
    if (read == -1)
    {
        free(student->surname);
        free(student->group);
        return ERR_DATA;
    }
    if (student->group == NULL)
    {
        free(student->surname);
        return ERR_ALLOC;
    }
    if (student->group[read - 1] == '\n')
    {
        student->group[read - 1] = '\0';
        read--;
    }
    if (read <= 0 || read > 10)
    {
        free(student->surname);
        free(student->group);
        return ERR_DATA;
    }
    return 0;
}

int read_file(FILE *f, node_t **head)
{
    student_t tmp, *student;
    node_t *cur = NULL;
    int rc;
    while (!(rc = read_student(f, &tmp)))
    {
        student = malloc(sizeof(student_t));
        if (student == NULL)
        {
            free_all(*head);
            return ERR_ALLOC;
        }
        *student = tmp;
        node_t *new_node = create_node(student);
        if (new_node == NULL)
        {
            free_all(*head);
            return ERR_ALLOC;
        }
        if (*head == NULL)
        {
            *head = new_node;
        }
        else
        {
            cur->next = new_node;
        }
        cur = new_node;
    }
    if (!feof(f))
    {
        return ERR_DATA;
    }
    return 0;
}

void free_student(student_t *student)
{
    free(student->surname);
    free(student->group);
    free(student);
}

void free_all(node_t *head)
{
    if (head == NULL)
    {
        return;
    }
    node_t *next = NULL;
    for ( ; head; head = next)
    {
        free_student(head->data);
        next = head->next;
        free(head);
    }
}

void free_new(node_t *head)
{
    if (head == NULL)
    {
        return;
    }
    node_t *next = NULL;
    for ( ; head; head = next)
    {
        free(head->data);
        next = head->next;
        free(head);
    }
}

void print_student(student_t *student)
{
    printf("%s\n", student->surname);
    printf("%d\n", student->year);
    printf("%s\n", student->group);
}

void print_all(node_t *head)
{
    node_t *next = NULL;
    for ( ; head; head = next)
    {
        print_student(head->data);
        next = head->next;
    }
}