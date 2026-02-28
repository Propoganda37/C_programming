#include <stdio.h>
#include <string.h>
#include <math.h>
#include "const2.h"
#include "process.h"

int find_best(FILE *f, struct book info[], char best_author[])
{
    char author[LEN];
    char book[LEN];
    int count, sold, number = 0, flag, max = 0;
    while (fscanf(f, "%s%s%d%d", book, author, &count, &sold) == 4)
    {
        if (count < sold || count < 1 || sold < 0)
        {
            return ERR_DATA;
        }
        flag = 0;
        for (int i = 0; i < number; i++)
        {
            printf("%s %s\n", author, info[i].author);
            if (strcmp(author, info[i].author) == 0)
            {
                info[i].sold += sold;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            strcpy(info[number].author, author);
            info[number++].sold = sold;
        }
    }
    if (!feof(f))
    {
        return ERR_IO;
    }
    if (number == 0)
    {
        return ERR_EMPTY;
    }
    for (int i = 0; i < number; i++)
    {
        if (info[i].sold > max)
        {
            max = info[i].sold;
            strcpy(best_author, info[i].author);
        }
    }
    return 0;
}
