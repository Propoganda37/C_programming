#ifndef _PROCESS_H__

#define _PROCESS_H__

void move(char word[], size_t start);
void change_word(char word[]);
size_t get_words(char str[], char words[][WORD_LEN]);
int create_string(char words[][WORD_LEN], size_t words_len, char new_str[]);

#endif
