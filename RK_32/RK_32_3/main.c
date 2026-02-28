#include <stdio.h>
#include <string.h>
#include "const.h"
#include "inout.h"
#include "process.h"

int main(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
    {
        printf("Ошибка аргументов\n");
        return ERR_ARGS;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        return ERR_OPEN;
    }
    node_t *head = NULL;
    int rc = read_file(f, &head);
    if (rc != 0)
    {
        fclose(f);
        return rc;
    }
    if (argc == 3 && strcmp(argv[2], "list") == 0)
    {
        print_all(head);
    }
    else if (argc == 4 && strcmp(argv[2], "form") == 0)
    {
        node_t *new_head = NULL;
        rc = form(head, argv[3], &new_head);
        if (rc != 0)
        {
            free_all(head);
            return rc;
        }
        print_all(new_head);
        free_new(new_head);
    }
    else
    {
        free_all(head);
        fclose(f);
        printf("Ошибка аргументов\n");
        return ERR_ARGS;
    }
    free_all(head);
    fclose(f);
    return 0;
}