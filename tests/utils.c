/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** utils
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
