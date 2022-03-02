# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeser <aeser@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 16:57:24 by aeser             #+#    #+#              #
#    Updated: 2022/02/20 15:32:46 by aeser            ###   ########.fr        #
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
