/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** database
*/

#ifndef DATABASE_H_
#define DATABASE_H_

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

#endif /* !DATABASE_H_ */
