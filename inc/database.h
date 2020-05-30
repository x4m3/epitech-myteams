/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** database
*/

#ifndef DATABASE_H_
#define DATABASE_H_

#include <stdbool.h>
#include <stdio.h>

#define DB_ROOT_PATH    ".database/"
#define DB_USERS_PATH   DB_ROOT_PATH "users/"
#define DB_PRIVATE_PATH DB_ROOT_PATH "private/"

typedef enum {
    USER = 5,
    PRIVATE_MSG = 11,
    TEAM = 4,
    CHANNEL = 7,
    THREAD = 6
} file_extension_e;

void recursive_mkdir(const char *dir);
char *construct_filename(char *name, file_extension_e ext);
char *construct_filepath(char *base_path, char *filename);
FILE *open_file_write(const char *file_path);

#endif /* !DATABASE_H_ */
