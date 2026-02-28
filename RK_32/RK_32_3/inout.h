#ifndef _INOUT_H__

#define _INOUT_H__

#include <stdio.h>
#include "const.h"

node_t *create_node(student_t *student);
int read_student(FILE *f, student_t *student);
int read_file(FILE *f, node_t **head);
void free_student(student_t *student);
void free_all(node_t *head);
void free_new(node_t *head);
void print_student(student_t *student);
void print_all(node_t *head);

#endif