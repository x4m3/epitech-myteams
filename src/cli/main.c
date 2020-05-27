/*
** EPITECH PROJECT, 2020
** epitech-myteams
** File description:
** main
*/

#include "client.h"
#include "myteams.h"

static int helper(void)
{
    printf("USAGE:\t./myteams_cli ip port\n\tip\tis the server ip "
           "address on which the server socket listens\n\tport\tis the port"
           " number on which the server socket listens\n");
    return (0);
}

static int parse_args(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        return (helper());
    } else if (ac != 3) {
        fprintf(stderr, "Wrong arguments\n");
        return (84);
    }
    else
        return (1);
}

_Noreturn static void client_prompt(int sockFd)
{
    char buffer[MAX_BODY_LENGTH];
    int i;
    while (1) {
        bzero(buffer, sizeof(buffer));
        i = 0;
        while ((buffer[i++] = getchar() != '\n'));
        write(sockFd, buffer, sizeof(buffer));
    }
}

int main(int ac, char **av)
{
    client_t *client = malloc(sizeof(client_t));
    struct sockaddr_in servaddr;
    char *ptr;
    uint32_t port;
    int i;

    if ((i = parse_args(ac, av)) != 1)
        return (i);
    port = strtol(av[2], &ptr, 10);
    if ((client->sockFd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error creating client socket\n");
        return (84);
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(av[1]);
    servaddr.sin_port = htons(port);
    connect(client->sockFd,(struct sockaddr *)&servaddr, sizeof(servaddr));
    client_prompt(client->sockFd);
    close(client->sockFd);
    return (0);
}
