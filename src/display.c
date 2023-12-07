/*
** EPITECH PROJECT, 2023
** organized [WSL: Ubuntu]
** File description:
** display
*/

#include "include/my_list.h"
#include "include/my_io.h"
#include "organized.h"
#include <stddef.h>

void display_added_hardware(material_t *hardware)
{
    my_putstr(hardware->type);
    my_putstr(" n°");
    my_put_nbr(hardware->id);
    my_putstr(" - \"");
    my_putstr(hardware->name);
    my_putstr("\" added.\n");
}

void display_deleted_hardware(material_t *hardware)
{
    my_putstr(hardware->type);
    my_putstr(" n°");
    my_put_nbr(hardware->id);
    my_putstr(" - \"");
    my_putstr(hardware->name);
    my_putstr("\" deleted.\n");
}

void display_hardware(material_t *hardware)
{
    my_putstr(hardware->type);
    my_putstr(" n°");
    my_put_nbr(hardware->id);
    my_putstr(" - \"");
    my_putstr(hardware->name);
    my_putstr("\"\n");
}
