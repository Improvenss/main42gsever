# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 12:48:35 by gsever            #+#    #+#              #
#    Updated: 2022/02/25 19:40:53 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -I . -c
FILES		:= $(shell find . -type f -name "*.c")
LIBFT_PATH	:= ./libft
LIBFT_A		:= ./libft/libft.a
OBJ			:= $(FILES:%.c=%.o)

$(NAME): $(OBJ)
	@echo "\033[92m--libft.a finded from libft\033[0m--"
	ar -rcs $(NAME) $(OBJ)
	@echo "\033[92mLIBFTPRINTF SUCCESFULLY COMPILED!!]"

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	
re: fclean all

bonus:

.PHONY: all clean fclean re bonus