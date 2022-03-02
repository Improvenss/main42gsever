# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeser <aeser@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 15:37:57 by aeser             #+#    #+#              #
#    Updated: 2022/02/20 15:37:58 by aeser            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a
SRCS	:= src
SRC		:= $(wildcard $(SRCS)/*.c)

OBJDIR	:= objects
LIBFT	:= $(OBJDIR)/libft.a
OBJ		:= $(SRC:$(SRCS)/%.c=$(OBJDIR)/%.o)
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I ./include

$(NAME): $(OBJDIR) $(LIBFT) $(OBJ)
	@mv $(OBJDIR)/libft.a libftprintf.a
	@ar -rcs $(NAME) $(OBJ)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@make -C libft

$(OBJDIR)/%.o: $(SRCS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJDIR)/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)

re: fclean all

.PHONY: all re clean fclean
