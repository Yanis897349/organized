/*
** EPITECH PROJECT, 2023
** organized [WSL: Ubuntu]
** File description:
** args
*/

#include "include/my_std.h"
#include "include/my_strings.h"
#include <stddef.h>
#include <stdlib.h>

int is_type_valid(char *type)
{
    const char *types[] = {"ACTUATOR", "DEVICE", "PROCESSOR",
        "SENSOR", "WIRE", NULL};

    for (int i = 0; types[i] != NULL; i++) {
        if (my_strcmp(type, types[i]) == 0)
            return 1;
    }
    return 0;
}

int check_args_parity(char **args)
{
    int i = 0;

    for (; args[i] != NULL; i++);
    if (i % 2 != 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
