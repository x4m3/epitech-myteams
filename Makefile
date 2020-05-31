##
## EPITECH PROJECT, 2020
## PSU_nmobjdump_2019
## File description:
## Makefile
##

OUTPUT_SERVER = myteams_server
OUTPUT_CLI = myteams_cli

BUILD_DIR = build

CC = cc
CFLAGS += -Wall -Wextra -I./libs/myteams -I./inc
LDFLAGS += -L ./libs/myteams -lmyteams -luuid

OBJ_SHARED = $(SRC_SHARED:%.c=$(BUILD_DIR)/%.o)
SRC_SHARED =	src/shared/remove_end_of_line.c

OBJ_SERVER = $(SRC_SERVER_MAIN:%.c=$(BUILD_DIR)/%.o)
SRC_SERVER =	    src/server/channel/delete_channel.c \
                    src/server/channel/init_channel.c \
                    src/server/channel/add_channel.c \
                    src/server/channel/find_channel.c \
                    src/server/channel/check_channel_uuid.c \
                    src/server/cmd/cmd.c \
                    src/server/cmd/create.c \
                    src/server/cmd/help.c \
                    src/server/cmd/info.c \
                    src/server/cmd/list.c \
                    src/server/cmd/login.c \
                    src/server/cmd/logout.c \
                    src/server/cmd/messages.c \
                    src/server/cmd/send.c \
                    src/server/cmd/subscribe.c \
                    src/server/cmd/subscribed.c \
                    src/server/cmd/use.c \
                    src/server/cmd/user.c \
                    src/server/cmd/users.c \
					src/server/cmd/tools/check_input_args.c \
					src/server/cmd/tools/get_number_args.c \
					src/server/get_global_teams.c \
					src/server/direct_message/add_direct_message.c \
					src/server/direct_message/delete_direct_message.c \
					src/server/direct_message/init_direct_message.c \
					src/server/direct_message/list_direct_message.c \
                    src/server/my_teams_uuid/init_myteams_uuid.c \
                    src/server/my_teams_uuid/delete_myteams_uuid.c \
					src/server/my_teams_uuid/list_user_subscribed.c \
					src/server/my_teams_uuid/add_myteams_uuid.c \
			        src/server/instance/delete_instance.c \
                    src/server/instance/init_instance.c \
                    src/server/instance/find_instance.c \
                    src/server/instance/get_number_instance.c \
                    src/server/instance/add_instance.c \
                    src/server/message/delete_message.c \
                    src/server/message/init_message.c \
                    src/server/message/list_private_message.c \
                    src/server/message/list_reply_thread.c \
                    src/server/message/add_message.c \
                    src/server/myteams/delete_myteams.c \
                    src/server/myteams/init_myteams.c \
                    src/server/team/delete_team.c \
                    src/server/team/init_team.c \
                    src/server/team/add_team.c \
                    src/server/team/find_team.c \
                    src/server/team/check_team_uuid.c \
                    src/server/team/list_user_subcribed.c \
                    src/server/team/list_team.c \
                    src/server/thread/delete_thread.c \
                    src/server/thread/init_thread.c \
                    src/server/thread/add_thread.c \
                    src/server/thread/find_thread.c \
                    src/server/thread/check_thread_uuid.c \
                    src/server/user_info/delete_user_info.c \
                    src/server/user_info/init_user_info.c \
                    src/server/user_info/add_user.c \
                    src/server/user_info/list_user.c \
                    src/server/client_delete.c \
                    src/server/client_handle.c \
                    src/server/client_init.c \
                    src/server/client_input.c \
                    src/server/client_response.c \
                    src/server/server_init.c \
                    src/server/server_loop.c \
					src/server/stay_alive.c \
					src/server/database/tools/construct_filepath.c \
					src/server/database/write_all.c \
					src/server/database/write/construct_filename.c \
					src/server/database/write/recursive_mkdir.c \
					src/server/database/write/open_file_write.c \
					src/server/database/write/user/write_users.c \
					src/server/database/write/user/store_subscribed_teams.c \
					src/server/database/load_all.c \
					src/server/database/load/user/load_user.c \
					src/server/database/load/open_file_read.c
SRC_SERVER_MAIN =	src/server/main.c \
				$(SRC_SERVER)

OBJ_CLI = $(SRC_CLI_MAIN:%.c=$(BUILD_DIR)/%.o)
SRC_CLI =	src/client/manage_serv_response.c
SRC_CLI_MAIN =	src/client/main.c \
				$(SRC_CLI)

TESTS_LDFLAGS += $(LDFLAGS) -lcriterion --coverage
TESTS_OUTPUT = unit_tests
TESTS_SRC = tests/utils.c \
			tests/test_client_input.c \
			$(SRC_SHARED) \
			$(SRC_SERVER) \
			$(SRC_CLI)

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

all: options $(OBJ_SHARED) server cli

options:
	@echo "  CC       $(CC)"
	@echo "  CFLAGS   $(CFLAGS)"
	@echo "  LDFLAGS  $(LDFLAGS)"

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@echo "  CC       $<"
	@$(CC) $(CFLAGS) -c $< -o $@

server: $(OBJ_SHARED) $(OBJ_SERVER)
	@echo "  BUILD    $(OUTPUT_SERVER)"
	@$(CC) -o $(OUTPUT_SERVER) $(OBJ_SHARED) $(OBJ_SERVER) $(LDFLAGS)

cli: $(OBJ_SHARED) $(OBJ_CLI)
	@echo "  BUILD    $(OUTPUT_CLI)"
	@$(CC) -o $(OUTPUT_CLI) $(OBJ_SHARED) $(OBJ_CLI) $(LDFLAGS)

build_tests:
	@echo "  RM       coverage"
	@rm -rf *.gcda *gcno
	@echo "  BUILD    $(TESTS_OUTPUT)"
	@$(CC) $(CFLAGS) -o $(TESTS_OUTPUT) $(TESTS_SRC) $(TESTS_LDFLAGS)

tests_run: build_tests
	@echo "  RUN      $(TESTS_OUTPUT)"
	@./$(TESTS_OUTPUT) --always-succeed
	@echo "  RUN      coverage"
	@gcovr --exclude tests/

clean:
	@echo "  RM       build"
	@rm -rf build
	@echo "  RM       coverage"
	@rm -rf *.gcda *gcno

fclean: clean
	@echo "  RM       $(OUTPUT_SERVER)"
	@rm -f $(OUTPUT_SERVER)
	@echo "  RM       $(OUTPUT_CLI)"
	@rm -f $(OUTPUT_CLI)
	@echo "  RM       $(TESTS_OUTPUT)"
	@rm -f $(TESTS_OUTPUT)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all server cli build_tests tests_run clean fclean re
