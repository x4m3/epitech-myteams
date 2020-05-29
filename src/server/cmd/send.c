/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** send
*/

#include "server.h"

static bool is_good_uuuid(char uuid1[UUID_STR_LEN], char uuid2[UUID_STR_LEN],
    direct_message_t *direct_message)
{
    if (strcmp(direct_message->uuid1, uuid1) == 0) {
        if (strcmp(direct_message->uuid2, uuid2) == 0)
            return true;
    }
    return false;
}

void create_conversation(my_teams_t *global_teams, char uuid1[UUID_STR_LEN],
    char uuid2[UUID_STR_LEN], char message[MAX_BODY_LENGTH])
{
    user_info_t *user = find_user(global_teams, false, uuid2);
    global_teams->list_of_direct_message =
        add_direct_message(global_teams, uuid1, uuid2);
    TAILQ_INSERT_HEAD(&global_teams->direct_message_head,
        global_teams->list_of_direct_message, next_direct_message);
    global_teams->list_of_direct_message->list_of_message =
        add_private_message(
            message, uuid1, global_teams->list_of_direct_message);
    client_response(user->user_uuid, message);
}
void cmd_send(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    char *user_uuid_no_quotes = NULL;
    char *message_body_no_quotes = NULL;

    user_uuid_no_quotes = remove_quotes(args[1]);
    message_body_no_quotes = remove_quotes(args[2]);
    TAILQ_FOREACH(global_teams->list_of_direct_message,
        &global_teams->direct_message_head, next_direct_message)
    {
        if (is_good_uuuid(user->user->user_uuid, user_uuid_no_quotes,
                global_teams->list_of_direct_message)
            == true) {
            add_private_message(message_body_no_quotes, user->user->username,
                global_teams->list_of_direct_message);
            return;
        }
    }
    create_conversation(global_teams, user->user->user_uuid,
        user_uuid_no_quotes, message_body_no_quotes);
    client_response(user->socket_fd, "message send");
}
