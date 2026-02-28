#include <string.h>
#include "const.h"
#include "process.h"

// Функция для нахождения разделителей
int check_separator(char s)
{
    char sep[] = " ,;:-.!?";
    for (size_t i = 0; i < 8; i++)
    {
        if (sep[i] == s)
        {
            return 1;
        }
    }
    return 0;
}

// Функция для нахождения повторяющихся слов
int check_repeat(char new_word[], char words[][WORD_LEN], size_t wor)
{
    for (size_t i = 0; i < wor; i++)
    {
        if (strcmp(words[i], new_word) == 0)
        {
            for (size_t j = 0; j < strlen(new_word); j++)
            {
                new_word[j] = '\0';
            }
            return 0;
        }
    }
    return 1;
}

// Функция для разделения строки на слова
size_t my_strtok(char str[], char words[][WORD_LEN], size_t len)
{
    size_t wor = 0;
    size_t symb = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (check_separator(str[i]) && symb != 0)
        {
            words[wor][symb] = '\0';
            if (check_repeat(words[wor], words, wor))
            {
                wor++;
            }
            symb = 0;
        }
        else if (!check_separator(str[i]))
        {
            words[wor][symb] = str[i];
            symb++;
            if (symb > 16)
            {
                return 302;
            }
        }
    }
    if (symb != 0)
    {
        words[wor][symb] = '\0';
        if (check_repeat(words[wor], words, wor))
        {
            wor++;
        }
    }
    return wor;
}

// Функция для упорядочивания строки
void sort(char words[][WORD_LEN], size_t wor)
{
    char change_word[WORD_LEN];
    for (size_t i = 0; i < wor; i++)
    {
        size_t min_word_index = i;
        for (size_t j = i + 1; j < wor; j++)
        {
            if (strcmp(words[min_word_index], words[j]) > 0)
            {
                min_word_index = j;
            }
        }
        if (i != min_word_index)
        {
            strncpy(change_word, words[i], WORD_LEN - 1);
            change_word[WORD_LEN - 1] = '\0';
            strncpy(words[i], words[min_word_index], WORD_LEN - 1);
            words[i][WORD_LEN - 1] = '\0';
            strncpy(words[min_word_index], change_word, WORD_LEN - 1);
            words[min_word_index][WORD_LEN - 1] = '\0';
        }
    }
}
