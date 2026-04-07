##
## EPITECH PROJECT, 2026
## epitech
## File description:
## makefile
##


SRC = src/execution.c \
      src/find_command.c \
      src/get_env.c \
      src/handle_command.c \
      src/main.c \
      src/my_putchar.c \
      src/my_putstr.c \
      src/my_str_to_word_array.c \
      src/my_strcat_path.c \
      src/my_strcmp.c \
      src/my_strlen.c \
      src/my_strncmp.c \
      src/my_strcpy.c \
      src/parser.c \
      src/my_strdup.c \
      src/env_handle.c \
      src/set_env.c \
      src/update_env.c \
      src/count_nodes.c \
      src/change_directory.c \
      src/list_to_tab.c \
      src/print_argv.c \
      src/my_strcat.c \
      src/pipe.c \
      src/semicolon.c \
      src/free.c \
      src/process_command.c \
      src/redirections.c \
      src/mys_str_to_word_array.c \

NAME = mysh

all: $(NAME)

$(NAME):
	clang -o $(NAME) $(SRC) -g3
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
