#ifndef _PROCESS_H__

#define _PROCESS_H__

int check_separator(char s);
int check_repeat(char new_word[], char words[][WORD_LEN], size_t wor);
size_t my_strtok(char str[], char words[][WORD_LEN], size_t len);
void sort(char words[][WORD_LEN], size_t wor);

#endif
