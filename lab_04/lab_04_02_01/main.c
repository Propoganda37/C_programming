/*
Программа разбивает строку на неповторяющиеся слова и упорядочивает их
в лексикографическом порядке
*/
#include <stdio.h>
#include <string.h>
#include "const.h"
#include "inout.h"
#include "process.h"

int main(void)
{
    // Ввод
    char str[LEN];
    printf("Введите строку на английском:\n");
    int rc = get_string(str);
    if (rc == ERR_EMPTY)
    {
        printf("Вы ввели пустую строку\n");
        return ERR_EMPTY;
    }
    if (rc == ERR_OVERFLOW)
    {
        printf("Вы ввели больше двухсот пятидесяти шести символов\n");
        return ERR_OVERFLOW;
    }
    size_t len = strlen(str);
    // Разбиение строки на слова
    char words[WORDS_COUNT][WORD_LEN];
    size_t words_len = my_strtok(str, words, len);
    if (words_len == 0)
    {
        printf("Вы ввели строку без слов\n");
        return ERR_NO_WORDS;
    }
    if (words_len == 302)
    {
        printf("Вы ввели слово длиннее 16 символов\n");
        return ERR_LONG_WORD;
    }
    // Упорядочивание слов
    sort(words, words_len);
    // Вывод слов
    printf("Result: ");
    print_words(words, words_len);
}
