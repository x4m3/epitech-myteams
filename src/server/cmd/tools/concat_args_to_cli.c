/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include "server.h"

static int get_number_param(
    char *param1, char *param2, char *param3, char *param4)
{
    if (param1 == NULL)
        return 0;
    if (param2 == NULL)
        return 2;
    if (param3 == NULL)
        return 2;
    if (param4 == NULL)
        return 3;
    return 4;
}

static size_t get_size_to_alocate(
    char *param1, char *param2, char *param3, char *param4)
{
    int nb_params = 0;

    nb_params = get_number_param(param1, param2, param3, param4);
    switch (nb_params) {
        case 1: return strlen(param1);
        case 2: return strlen(param1) + strlen(param2);
        case 3: return strlen(param1) + strlen(param2) + strlen(param3);
        case 4:
            return strlen(param1) + strlen(param2) + strlen(param3)
                + strlen(param4);
        default: return 0;
    }
}

static char *alloc_concat_param(
    char *param1, char *param2, char *param3, char *param4)
{
    int nb_params = 0;
    char *concat_param = NULL;

    nb_params = get_number_param(param1, param2, param3, param4);
    if (nb_params == 0)
        return NULL;
    size_t size_to_allocate =
        get_size_to_alocate(param1, param2, param3, param4);
    concat_param = malloc(sizeof(char) * size_to_allocate + nb_params);
    memset(concat_param, 0, size_to_allocate + nb_params);
    return concat_param;
}

char *concat_args_to_cli(
    char *param1, char *param2, char *param3, char *param4)
{
    char *concat_param = NULL;

    concat_param = alloc_concat_param(param1, param2, param3, param4);
    if (concat_param == NULL)
        return NULL;
    strcat(concat_param, param1);
    if (param2 != NULL) {
        strcat(concat_param, ",");
        strcat(concat_param, param2);
    }
    if (param3 != NULL) {
        strcat(concat_param, ",");
        strcat(concat_param, param3);
    }
    return concat_param;
}
