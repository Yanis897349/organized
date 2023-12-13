/*
** EPITECH PROJECT, 2023
** organized [WSL: Ubuntu]
** File description:
** sort
*/

#pragma once

#include "include/my_list.h"

linked_list_t *get_tail(linked_list_t *head);
void quick_sort(linked_list_t *head, linked_list_t *tail, int (*cmp)(), int
    is_reverse);
