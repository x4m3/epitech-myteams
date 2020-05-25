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
LDFLAGS += -L ./libs/myteams -lmyteams

OBJ_SHARED = $(SRC_SHARED:%.c=$(BUILD_DIR)/%.o)
SRC_SHARED =	src/shared/bin.c

OBJ_SERVER = $(SRC_SERVER_MAIN:%.c=$(BUILD_DIR)/%.o)
SRC_SERVER =	src/server/server_init.c \
				src/server/server_loop.c \
				src/server/client_init.c \
				src/server/client_delete.c \
				src/server/client_handle.c \
				src/server/client_input.c \
				src/server/client_response.c \
				src/server/cmd/cmd.c \
				src/server/cmd/help.c \
				src/server/cmd/login.c \
				src/server/cmd/logout.c \
				src/server/cmd/users.c \
				src/server/cmd/user.c \
				src/server/cmd/send.c \
				src/server/cmd/messages.c \
				src/server/cmd/subscribe.c \
				src/server/cmd/subscribed.c \
				src/server/cmd/use.c \
				src/server/cmd/create.c \
				src/server/cmd/list.c \
				src/server/cmd/info.c
SRC_SERVER_MAIN =	src/server/main.c \
				$(SRC_SERVER)

OBJ_CLI = $(SRC_CLI_MAIN:%.c=$(BUILD_DIR)/%.o)
SRC_CLI =	src/cli/cli.c
SRC_CLI_MAIN =	src/cli/main.c \
				$(SRC_CLI)

TESTS_LDFLAGS += $(LDFLAGS) -lcriterion --coverage
TESTS_OUTPUT = unit_tests
TESTS_SRC = tests/utils.c \
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
	@echo "  BUILD    $(TESTS_OUTPUT)"
	@$(CC) $(CFLAGS) -o $(TESTS_OUTPUT) $(TESTS_SRC) $(TESTS_LDFLAGS)

tests_run: build_tests
	@echo "  RUN      $(TESTS_OUTPUT)"
	@./$(TESTS_OUTPUT) --always-succeed
	@echo "  RM       coverage"
	@rm -rf *.gcda *gcno
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
