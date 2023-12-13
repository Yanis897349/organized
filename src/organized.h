/*
** EPITECH PROJECT, 2023
** organized
** File description:
** organized
*/

#pragma once

#include "include/my_list.h"

typedef struct material_s {
    char *type;
    char *name;
    unsigned int id;
} material_t;

typedef struct {
    int (*sort_function)(linked_list_t *, linked_list_t *, int);
    int is_reverse;
} sort_operation_t;
