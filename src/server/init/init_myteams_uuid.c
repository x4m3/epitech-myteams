/*
** EPITECH PROJECT, 2019
** name of the project
** File description:
** foo
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"

myteams_uuid_t *init_myteams_uuid(void)
{
    myteams_uuid_t *myteams_uuid;

    if ((myteams_uuid = malloc(sizeof(myteams_uuid_t))) == NULL)
        return NULL;
    memset(myteams_uuid, 0, sizeof(myteams_uuid_t));
    return myteams_uuid;
}
