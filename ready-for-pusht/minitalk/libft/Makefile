# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 02:23:57 by gsever            #+#    #+#              #
#    Updated: 2022/03/22 20:02:35 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OBJDIR	:= ../objects
NAME	:= $(OBJDIR)/libft.a
CFLAGS	:= -Wall -Wextra -Werror -I ../include -c
FILES	:= $(shell find . -type f -name "ft_*.c")
OBJ		:= $(FILES:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJDIR)/ft_*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
