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
#include <stdlib.h>

int main(void)
{
    linked_list_t *list = create_list("Hello");

    list = add_to_list(list, "World");
    list = add_to_list(list, "!");
    list = delete_from_list(list, "Hello", &my_strcmp, &null_function);
    for (linked_list_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        my_putstr(tmp->data);
        my_putchar('\n');
    }
    destroy_list(list, &null_function);
    return 84;
}
