/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"

thread_t *init_thread(void)
{
    thread_t *thread;

    if ((thread = malloc(sizeof(thread_t))) == NULL)
        return NULL;
    memset(thread, 0, sizeof(thread_t));
    return thread;
}
