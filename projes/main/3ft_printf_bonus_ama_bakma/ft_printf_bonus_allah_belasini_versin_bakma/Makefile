# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 15:37:57 by aeser             #+#    #+#              #
#    Updated: 2022/03/04 11:53:27 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -I ./include

SRCS		:= src
SRC			:= $(wildcard $(SRCS)/*.c)
SRCS_BONUS	:= srcbonus
SRC_BONUS	:= $(wildcard $(SRCS_BONUS)/*.c)

OBJDIR		:= objects
LIBFT		:= $(OBJDIR)/libft.a
OBJ			:= $(SRC:$(SRCS)/%.c=$(OBJDIR)/%.o)
OBJ_BONUS	:= $(SRC_BONUS:$(SRCS_BONUS)/%.c=$(OBJDIR)/%.o)

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

bonus: $(OBJDIR) $(LIBFT) $(OBJ_BONUS)
	@mv $(OBJDIR)/libft.a libftprintf.a
	@ar -rcs $(NAME) $(OBJ_BONUS)

re: fclean all

.PHONY: all clean fclean bonus re
