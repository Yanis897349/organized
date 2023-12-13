/*
** EPITECH PROJECT, 2023
** organized [WSL: Ubuntu]
** File description:
** compare
*/

#pragma once

#include "include/my_list.h"

int cmp_by_id(linked_list_t *front, linked_list_t *tail, int is_reverse);
int cmp_by_type(linked_list_t *front, linked_list_t *tail, int is_reverse);
int cmp_by_name(linked_list_t *front, linked_list_t *tail, int is_reverse);
