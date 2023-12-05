/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** list_add
*/

#include "my_list.h"
#include <stdlib.h>

linked_list_t *add_to_list(linked_list_t *list, void *data)
{
    linked_list_t *new = create_list(data);

    if (new == NULL)
        return NULL;
    new->next = list;
    return new;
}
