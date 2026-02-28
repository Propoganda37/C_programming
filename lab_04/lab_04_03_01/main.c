/*
Программа составляет новую строку из слов первой.
Слова идут в обратном порядке, отличные от последнего слова.
Во всех словах программа оставляет только первое вхождение каждой буквы
*/
#include <stdio.h>
#include <string.h>
#include "const.h"
#include "inout.h"
#include "process.h"

int main(void)
{
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
    char words[WORDS_COUNT][WORD_LEN];
    size_t words_len = get_words(str, words);
    if (words_len == 0)
    {
        printf("Вы ввели строку без слов\n");
        return ERR_NO_WORDS;
    }
    if (words_len == 300)
    {
        printf("Вы ввели слово длиннее 16 символов\n");
        return ERR_LONG_WORD;
    }
    char new_str[LEN];
    if (create_string(words, words_len, new_str) == 0)
    {
        printf("Все слова в строке такие же, как и последнее\n");
        return ERR_SAME_WORDS;
    }
    printf("Result: %s\n", new_str);
}
