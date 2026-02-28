#ifndef _PROCESS_H__

#define _PROCESS_H__

int get_number_by_pos(FILE *f, size_t pos);
void put_number_by_pos(FILE *f, size_t pos, int num);
int check_size(FILE *f);
void random_fill(FILE *f, int count);
int print_file(FILE *f);
void swap(FILE *f, size_t pos1, size_t pos2);
int sort(FILE *f);

#endif
