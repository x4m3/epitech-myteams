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
    global_teams->list_of_direct_message->list_of_message =
        add_private_message(
            message, uuid1, global_teams->list_of_direct_message);
    client_response(user->list_of_instance->socket_fd, message);
}

direct_message_t *check_if_conv_exist(net_user_t *user, char *msg_body,
    char *user_uuid, my_teams_t *global_teams)
{
    TAILQ_FOREACH(global_teams->list_of_direct_message,
        &global_teams->direct_message_head, next_direct_message)
    {
        if (is_good_uuuid(user->user->user_uuid, user_uuid,
                global_teams->list_of_direct_message)
            == true) {
            add_private_message(msg_body, user->user->username,
                global_teams->list_of_direct_message);
            return global_teams->list_of_direct_message;
        }
        if (is_good_uuuid(user_uuid, user->user->user_uuid,
                global_teams->list_of_direct_message)
            == true) {
            add_private_message(msg_body, user->user->user_uuid,
                global_teams->list_of_direct_message);
            return global_teams->list_of_direct_message;
        }
    }
    return NULL;
}

void cmd_send(net_user_t *user, char **args)
{
    my_teams_t *global_teams = get_global_teams(NULL);
    char *user_uuid = args[1];
    char *msg_body = args[2];
    direct_message_t *dm = NULL;

    if (check_input_args(2, args, user->socket_fd) == false)
        return;
    dm = check_if_conv_exist(user, msg_body, user_uuid, global_teams);
    global_teams->list_of_direct_message = dm;
    printf("apres avoir trouve le dm %p \n",
        global_teams->list_of_direct_message);
    if (global_teams->list_of_direct_message == NULL)
        create_conversation(
            global_teams, user->user->user_uuid, user_uuid, msg_body);
    else
        add_private_message(msg_body, user->user->user_uuid,
            global_teams->list_of_direct_message);
    server_event_private_message_sended(
        user->user->user_uuid, user_uuid, msg_body);
}
