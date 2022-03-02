# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 19:14:22 by gsever            #+#    #+#              #
#    Updated: 2022/03/02 15:33:02 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
CC		:= clang
CFLAGS	:= -Wall -Wextra -Werror -I . -c
FILES	:= $(shell find . -type f -name "*.c")
OBJ		:= $(FILES:%.c=%.o)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "\033[92m	!!LIBFT SUCCESFULLY COMPILED!!\033[0m"

all: $(NAME)
	@echo "\033[92m-->	FIRST STEP 		'OK'\033[0m"

clean:
	@rm -f *.o
	@echo "\033[92m-->	LIBFT'S		*.o 	FILES CLEARED\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[92m-->	LIBFT'S		libft.a 	FILE CLEARED\033[0m"

re: fclean all

.PHONY: all clean fclean re
