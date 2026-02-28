#ifndef _PROCESS_H__

#define _PROCESS_H__

struct product read_by_pos(FILE *f, size_t pos);
void write_by_pos(FILE *f, size_t pos, struct product p);
int check_size(FILE *f);
void swap(FILE *f, size_t pos1, size_t pos2);
int sort(FILE *f, FILE *f_new);
int check_substr(char str[], size_t len_str, char substr[], size_t len_substr);
int find(FILE *f, char str[]);

#endif
