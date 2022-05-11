# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 02:26:20 by gsever            #+#    #+#              #
#    Updated: 2022/04/25 19:31:49 by gsever           ###   ########.fr        #
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
