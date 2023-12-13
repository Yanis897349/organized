/*
** EPITECH PROJECT, 2023
** organized [WSL: Ubuntu]
** File description:
** sort
*/

#pragma once

#include "include/my_list.h"

linked_list_t *get_tail(linked_list_t *head);
void merge_sort(linked_list_t **head_ref, int (*cmp)(), int is_reverse);
