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

void display_added_material(material_t *material)
{
    my_putstr(material->type);
    my_putstr(" n°");
    my_put_nbr(material->id);
    my_putstr(" - \"");
    my_putstr(material->name);
    my_putstr("\" added.\n");
}

void display_deleted_material(material_t *material)
{
    my_putstr(material->type);
    my_putstr(" n°");
    my_put_nbr(material->id);
    my_putstr(" - \"");
    my_putstr(material->name);
    my_putstr("\" deleted.\n");
}

void display_material(material_t *material)
{
    my_putstr(material->type);
    my_putstr(" n°");
    my_put_nbr(material->id);
    my_putstr(" - \"");
    my_putstr(material->name);
    my_putstr("\"\n");
}
