# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 01:31:26 by Nik               #+#    #+#              #
#    Updated: 2019/08/30 21:46:53 by Nik              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER=checker

PUSH_SWAP=push_swap

SRCS1=CH/*.c

SRCS2=PS/*.c

INCLUDES=libft/libft.a utils/*.c

FLAGS=-Werror -Wextra -Wall -fsanitize=address

all: $(NAME)
	@make -C libft/ all
	gcc -o $(CHECKER) $(FLAGS) $(SRCS1) $(INCLUDES)
	gcc -o $(PUSH_SWAP) $(FLAGS) $(SRCS2) $(INCLUDES)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(CHECKER)
	/bin/rm -f $(PUSH_SWAP)
	@make -C libft/ fclean

re: fclean all

push_swap:
	gcc -o $(PUSH_SWAP) $(FLAGS) $(SRCS2) $(INCLUDES)

checker:
	gcc -o $(CHECKER) $(FLAGS) $(SRCS1) $(INCLUDES)