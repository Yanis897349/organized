/*
** EPITECH PROJECT, 2023
** organized [WSL: Ubuntu]
** File description:
** compare
*/

#include "include/my_list.h"
#include "include/my_strings.h"
#include "organized.h"

int cmp_by_id(linked_list_t *a, linked_list_t *b, int is_reverse)
{
    if (is_reverse)
        return ((material_t *) a->data)->id >
        ((material_t *)b->data)->id;
    return ((material_t *) a->data)->id < ((material_t *)b->data)->id;
}

int cmp_by_type(linked_list_t *a, linked_list_t *b, int is_reverse)
{
    if (is_reverse)
        return my_strcmp(((material_t *) a->data)->type,
            ((material_t *)b->data)->type) > 0;
    return my_strcmp(((material_t *) a->data)->type,
        ((material_t *)b->data)->type) < 0;
}

int cmp_by_name(linked_list_t *a, linked_list_t *b, int is_reverse)
{
    if (is_reverse)
        return my_strcmp(((material_t *) a->data)->name,
            ((material_t *)b->data)->name) > 0;
    return my_strcmp(((material_t *) a->data)->name,
        ((material_t *)b->data)->name) < 0;
}
