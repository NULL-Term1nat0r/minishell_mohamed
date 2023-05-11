# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 10:47:26 by fvon-nag          #+#    #+#              #
#    Updated: 2023/05/11 21:55:10 by estruckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = main.c \
			parsing_utils.c \
			parsing_redirection.c \
			lexer.c \
			parser.c \
			input_analysis.c \
			signals.c \
			syscommands.c \
			syscommands_utils.c \
			execution.c \
			link_list_utils/create_list.c \
			link_list_utils/link_list.c \
			builtin_utils/builtins_utils.c \
			builtins/echo.c \
			builtins/execute_buildins.c \
			builtins/env.c \
			builtins/pwd.c \
			builtins/cd.c


NAME = minishell
LIBFT = ./Libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I $(HOME)/goinfre/.brew/opt/readline/include/

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -L$(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline $(SOURCES) -o $(NAME)

$(LIBFT):
	make -C Libft

clean:
	make -C Libft clean

fclean: clean
	make fclean -C Libft
	rm -rf $(NAME) minishell.dSYM

re: fclean all

.PHONY: all bonus libft clean fclean re

