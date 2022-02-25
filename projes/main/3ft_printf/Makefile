# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 12:48:35 by gsever            #+#    #+#              #
#    Updated: 2022/02/25 18:15:50 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -I . -c
FILES		:= $(shell find . -type f -name "*.c")
LIBFT_PATH	:= ./libft
OBJ			:= $(FILES:%.c=%.o)



$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all:

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	
re: fclean all

bonus:

.PHONY: all clean fclean re bonus