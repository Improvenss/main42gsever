# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 12:48:35 by gsever            #+#    #+#              #
#    Updated: 2022/03/02 13:42:17 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -I . -c
FILES		:= $(wildcard *.c)
LIBFT_PATH	:= ./libft
LIBFT_A		:= ./libft/libft.a
OBJ			:= $(FILES:%.c=%.o)
#compiling libft
libft_c:
	@make all -C $(LIBFT_PATH)
#libft.a moving up directory
libft_mv: libft_c
	@mv $(LIBFT_A) .
	@echo "\033[92m--> libft.a MOVED TO UP DIRECTORY\033[0m"
#compiling print files with libft.a. After deleting libft.a
$(NAME): $(OBJ)
	@ar -rcs $(NAME) libft.a $(OBJ)
	@echo "\033[92m--LIBFTPRINTF SUCCESFULLY COMPILED!!--\033[0m"
	@rm -f libft.a
	@echo "\033[92m-->	libft.a 	DELETED\033[0m"
	@echo "\033[92m	!!ALL STEPS SUCCESFULLY COMPILED FINISHED!!\033[0m"

all: libft_mv $(NAME) clean

clean:
	@rm -f *.o
	@echo "\033[33m-->	*.o 		FILES DELETED\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33m-->	libftprintf.a 	DELETED\033[0m"
	
	
re: fclean all

bonus:

.PHONY: all clean fclean re bonus