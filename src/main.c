/*
** EPITECH PROJECT, 2023
** organized [WSL: Ubuntu]
** File description:
** main
*/

#include "include/my_list.h"
#include "include/my_strings.h"
#include "include/my_io.h"
#include "include/my_std.h"
#include "include/my_math.h"
#include "organized.h"
#include "shell.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int compare_int(material_t *hardware, int *b)
{
    return hardware->id - *b;
}

static void delete_hardware(material_t *hardware)
{
    my_putstr(hardware->type);
    my_putstr(" n°");
    my_put_nbr(hardware->id);
    my_putstr(" - '");
    my_putstr(hardware->name);
    my_putstr("' deleted.\n");
    free(hardware->type);
    free(hardware->name);
    free(hardware);
}

int add(void *data, char **args)
{
    linked_list_t **list = data;
    material_t *new_hardware = NULL;
    static int new_id = 0;

    for (int i = 0; args[i] != NULL; i += 2) {
        new_hardware = malloc(sizeof(material_t));
        if (new_hardware == NULL)
            return 84;
        new_hardware->type = my_strdup(args[i]);
        new_hardware->name = my_strdup(args[i + 1]);
        new_hardware->id = new_id;
        add_to_list(list, new_hardware);
        my_putstr(new_hardware->type);
        my_putstr(" n°");
        my_put_nbr(new_hardware->id);
        my_putstr(" added - '");
        my_putstr(new_hardware->name);
        my_putstr("' added.\n");
        new_id++;
    }
    return 0;
}

int del(void *data, char **args)
{
    linked_list_t **list = data;
    int ref = -1;

    for (int i = 0; args[i] != NULL; i++) {
        ref = my_getnbr(args[i]);
        delete_from_list(list, &ref, &compare_int, &delete_hardware);
    }
    return 0;
}

int sort(void *data, char **args)
{
    return 0;
}

int disp(void *data, char **args)
{
    linked_list_t **list = data;
    material_t *hardware = NULL;

    for (linked_list_t *tmp = *list; tmp != NULL; tmp = tmp->next) {
        hardware = tmp->data;
        my_putstr(hardware->type);
        my_putstr(" n°");
        my_put_nbr(hardware->id);
        my_putstr(" - '");
        my_putstr(hardware->name);
        my_putstr("'\n");
    }
    return 0;
}

int main(void)
{
    linked_list_t *list = NULL;

    return workshop_shell(&list);
}
