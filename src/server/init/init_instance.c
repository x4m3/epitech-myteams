/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

instance_t *init_instance(void)
{
    instance_t *instance;

    if ((instance = malloc(sizeof(instance_t))) == NULL)
        return NULL;
    memset(instance, 0, sizeof(instance_t));
    return instance;
}
