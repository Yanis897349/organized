/*
** EPITECH PROJECT, 2023
** organized [WSL: Ubuntu]
** File description:
** compare
*/

#include "include/my_list.h"
#include "include/my_strings.h"
#include "organized.h"

int cmp_by_id(linked_list_t *front, linked_list_t *tail, int is_reverse)
{
    if (is_reverse)
        return ((material_t *) front->data)->id >
        ((material_t *)tail->data)->id;
    return ((material_t *) front->data)->id < ((material_t *)tail->data)->id;
}

int cmp_by_type(linked_list_t *front, linked_list_t *tail, int is_reverse)
{
    if (is_reverse)
        return my_strcmp(((material_t *) front->data)->type,
            ((material_t *)tail->data)->type) > 0;
    return my_strcmp(((material_t *) front->data)->type,
        ((material_t *)tail->data)->type) < 0;
}

int cmp_by_name(linked_list_t *front, linked_list_t *tail, int is_reverse)
{
    if (is_reverse)
        return my_strcmp(((material_t *) front->data)->name,
            ((material_t *)tail->data)->name) > 0;
    return my_strcmp(((material_t *) front->data)->name,
        ((material_t *)tail->data)->name) < 0;
}
