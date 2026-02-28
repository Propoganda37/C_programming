#include <string.h>
#include "const.h"
#include "process.h"

// Функция для сдвига символов в слове
void move(char word[], size_t start)
{
    for (size_t i = start; i < strlen(word); i++)
    {
        word[i] = word[i + 1];
    }
}

// Функция для изменения слова
void change_word(char word[])
{
    size_t i = 0;
    while (i < strlen(word))
    {
        size_t j = i + 1;
        while (j < strlen(word))
        {
            if (word[i] == word[j])
            {
                move(word, j);
            }
            else
            {
                j++;
            }
        }
        i++;
    }
}

// Функция для получения массива слов
size_t get_words(char str[], char words[][WORD_LEN])
{
    size_t words_len = 0;
    char *pword = strtok(str, " ,;:-.!?");
    while (pword)
    {
        if (strlen(pword) > 16)
        {
            return 300;
        }
        strcpy(words[words_len], pword);
        words_len++;
        pword = strtok(NULL, " ,;:-.!?");
    }
    return words_len;
}

// Функция для получения итоговой строки
int create_string(char words[][WORD_LEN], size_t words_len, char new_str[])
{
    if (words_len == 1)
    {
        return 0;
    }
    size_t new_len = 0;
    size_t i = words_len - 1;
    do
    {
        i--;
        if (strcmp(words[i], words[words_len - 1]) != 0)
        {
            change_word(words[i]);
            for (size_t j = 0; j < strlen(words[i]); j++)
            {
                new_str[new_len++] = words[i][j];
            }
            if (i != 0)
            {
                new_str[new_len++] = ' ';
            }
        }
    }
    while (i > 0);
    if (new_len == 0)
    {
        return 0;
    }
    new_str[new_len] = '\0';
    return 1;
}
