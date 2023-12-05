/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** my_list
*/

#pragma once

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

void null_function(void *data);
void destroy_list(linked_list_t *list, void (*free_func)());

linked_list_t *create_list(void *data);
linked_list_t *add_to_list(linked_list_t *list, void *data);
linked_list_t *delete_from_list(linked_list_t *list, void *ref, int (*cmp)(),
    void (*free_func)());
