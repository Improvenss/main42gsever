# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 19:14:22 by gsever            #+#    #+#              #
#    Updated: 2022/02/25 19:28:53 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
CC		:= clang
CFLAGS	:= -Wall -Wextra -Werror -I . -c
FILES	:= $(shell find . -type f -name "*.c")
OBJ		:= $(FILES:%.c=%.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	@echo "\033[92m!!LIBFT SUCCESFULLY COMPILED!!\033[0m"

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
