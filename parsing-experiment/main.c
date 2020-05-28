#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>
#include "myteams.h"

typedef struct {
    char uuid[UUID_STR_LEN];
    char username[MAX_NAME_LENGTH];
} user_t;

void remove_end_of_line(char *str)
{
    size_t pos_end_of_line = 0;

    for (size_t i = 0; str[i]; i++)
        if (str[i] == '\n')
            pos_end_of_line = i;
    if (pos_end_of_line != 0)
        str[pos_end_of_line] = 0;
}

void store_key(char *dest)
{
    char *value = strtok(NULL, "=");
    for (size_t i = 0; value[i]; i++)
        dest[i] = value[i];
}

int load(void)
{
    user_t user = {0};
    FILE *source = fopen("./abcdef.user", "r");
    size_t buffer_len = 0;
    char *buffer = NULL;
    char *key = NULL;

    if (source == NULL)
        return 1;

    while (getline(&buffer, &buffer_len, source) != -1) {
        remove_end_of_line(buffer);
        key = strtok(buffer, "=");
        if (strcmp(key, "UUID") == 0) {
            store_key(user.uuid);
            user.uuid[UUID_STR_LEN] = 0;
        }
        if (strcmp(key, "USERNAME") == 0) {
            store_key(user.username);
            user.username[MAX_NAME_LENGTH] = 0;
        }
        if (strcmp(key, "SUBSCRIBED_TEAM") == 0) {
            char *value = strtok(NULL, "=");
            printf("SUBSCRIBED_TEAMS: [%s]\n", value);
        }
    }
    printf("user.UUID: [%s]\n", user.uuid);
    printf("user.username: [%s]\n", user.username);
    free(buffer);
    fclose(source);
    return 0;
}

char *construct_output_name(char *name)
{
    char *str = malloc(sizeof(char) * (strlen(name) + 5) + 1);
    size_t i = 0;

    if (str == NULL)
        return NULL;
    for (; name[i]; i++) {
        str[i] = name[i];
    }
    str[i] = '.';
    str[i + 1] = 'u';
    str[i + 2] = 's';
    str[i + 3] = 'e';
    str[i + 4] = 'r';
    str[i + 5] = 0;
    return str;
}

int save(void)
{
    user_t user = {0};
    FILE *output = NULL;
    char *output_filename = NULL;

    strcpy(user.uuid, "abcdef");
    strcpy(user.username, "phil");
    output_filename = construct_output_name(user.uuid);
    if (output_filename == NULL)
        return 1;
    output = fopen(output_filename, "w");
    free(output_filename);
    if (output == NULL)
        return 1;
    fprintf(output, "UUID=%s\n", user.uuid);
    fprintf(output, "USERNAME=%s\n", user.username);
    fclose(output);
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 2;
    if (strcmp(av[1], "load") == 0)
        return load();
    if (strcmp(av[1], "save") == 0)
        return save();
    return 2;
}
