/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** stay_alive
*/

#include <stdbool.h>

/* Ah, ha, ha, ha, stayin' alive, stayin' alive */
bool stay_alive(int new)
{
    static bool alive;

    if (new != -1)
        alive = new;
    return alive;
}
