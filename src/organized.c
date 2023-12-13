/*
** EPITECH PROJECT, 2023
** organized [WSL: Ubuntu]
** File description:
** organized
*/

#include "include/my_list.h"
#include "include/my_strings.h"
#include "include/my_io.h"
#include "include/my_math.h"
#include "include/my_std.h"
#include "organized.h"
#include "compare.h"
#include "display.h"
#include "sort.h"
#include "args.h"
#include "shell.h"
#include <stdlib.h>

static int compare_id(material_t *hardware, int *b)
{
    return hardware->id - *b;
}

static void delete_hardware(material_t *hardware)
{
    display_deleted_hardware(hardware);
    free(hardware->type);
    free(hardware->name);
    free(hardware);
}

int add(void *data, char **args)
{
    static int new_id = 0;
    linked_list_t **list = data;
    material_t *new_hardware = NULL;

    if (check_args_parity(args) == EXIT_FAILURE)
        return EXIT_ERROR;
    for (int i = 0; args[i] != NULL; i += 2) {
        if (!is_type_valid(args[i]))
            continue;
        new_hardware = malloc(sizeof(material_t));
        if (new_hardware == NULL)
            return EXIT_ERROR;
        new_hardware->type = my_strdup(args[i]);
        new_hardware->name = my_strdup(args[i + 1]);
        new_hardware->id = new_id;
        add_to_list(list, new_hardware);
        display_added_hardware(new_hardware);
        new_id++;
    }
    return EXIT_SUCCESS;
}

int del(void *data, char **args)
{
    linked_list_t **list = data;
    int ref = -1;

    for (int i = 0; args[i] != NULL; i++) {
        if (my_str_isnum(args[i]) == 0)
            continue;
        ref = my_getnbr(args[i]);
        delete_from_list(list, &ref, &compare_id, &delete_hardware);
    }
    return 0;
}

int disp(void *data, char **args)
{
    linked_list_t **list = data;
    material_t *hardware = NULL;

    (void) args;
    for (linked_list_t *tmp = *list; tmp != NULL; tmp = tmp->next) {
        hardware = tmp->data;
        display_hardware(hardware);
    }
    return 0;
}

int sort(void *data, char **args)
{
    linked_list_t **list = data;
    int is_reverse = 0;

    for (int i = 0; args[i] != NULL; i++) {
        if (args[i + 1] != NULL)
            is_reverse = (my_strcmp(args[i + 1], "-r") == 0) ? 1 : 0;
        if (my_strcmp(args[i], "TYPE") == 0)
            quick_sort(*list, get_tail(*list), &cmp_by_type, is_reverse);
        if (my_strcmp(args[i], "NAME") == 0)
            quick_sort(*list, get_tail(*list), &cmp_by_name, is_reverse);
        if (my_strcmp(args[i], "ID") == 0)
            quick_sort(*list, get_tail(*list), &cmp_by_id, is_reverse);
    }
    return 0;
}
