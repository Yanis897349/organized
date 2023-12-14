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
#include <stdio.h>
#include <stdlib.h>

static int compare_id(material_t *material, int *b)
{
    return material->id - *b;
}

static void delete_material(material_t *material)
{
    display_deleted_material(material);
    free(material->type);
    free(material->name);
    free(material);
}

static void execute_sort(sort_operation_t *sort_operations, int sort_index,
    linked_list_t **list)
{
    for (int i = sort_index - 1; i >= 0; i--) {
        if (sort_operations[i].sort_function != NULL)
            merge_sort(list, sort_operations[i].sort_function,
                sort_operations[i].is_reverse);
    }
}

int add(void *data, char **args)
{
    static int new_id = 0;
    linked_list_t **list = data;
    material_t *new_material = NULL;

    if (check_args_parity(args) == EXIT_FAILURE)
        return EXIT_ERROR;
    for (int i = 0; args[i] != NULL; i += 2) {
        if (!is_type_valid(args[i]))
            continue;
        new_material = malloc(sizeof(material_t));
        if (new_material == NULL)
            return EXIT_ERROR;
        new_material->type = my_strdup(args[i]);
        new_material->name = my_strdup(args[i + 1]);
        new_material->id = new_id;
        add_to_list(list, new_material);
        display_added_material(new_material);
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
        delete_from_list(list, &ref, &compare_id, &delete_material);
    }
    return 0;
}

int disp(void *data, char **args)
{
    linked_list_t **list = data;
    material_t *material = NULL;

    (void) args;
    for (linked_list_t *tmp = *list; tmp != NULL; tmp = tmp->next) {
        material = tmp->data;
        display_material(material);
    }
    return 0;
}

int sort(void *data, char **args)
{
    linked_list_t **list = data;
    sort_operation_t sort_operations[3] = {{NULL, 0}, {NULL, 0}, {NULL, 0}};
    int sort_index = 0;

    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], "TYPE") == 0)
            sort_operations[sort_index].sort_function = &cmp_by_type;
        if (my_strcmp(args[i], "NAME") == 0)
            sort_operations[sort_index].sort_function = &cmp_by_name;
        if (my_strcmp(args[i], "ID") == 0)
            sort_operations[sort_index].sort_function = &cmp_by_id;
        if (args[i + 1] != NULL && my_strcmp(args[i + 1], "-r") == 0) {
            sort_operations[sort_index].is_reverse = 1;
        }
        if (my_strcmp(args[i], "-r") == 0)
            continue;
        sort_index++;
    }
    execute_sort(sort_operations, sort_index, list);
    return 0;
}
