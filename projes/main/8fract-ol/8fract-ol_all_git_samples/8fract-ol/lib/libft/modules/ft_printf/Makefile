# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 23:23:50 by tjensen           #+#    #+#              #
#    Updated: 2021/09/15 11:52:10 by tjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_printf

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./include/ -I../../include/

SDIR		= src
SRCS		= ft_printf.c ft_format.c ft_flags.c ft_prec_width.c \
			  ft_print_chrstr.c ft_print_dec.c ft_print_hex.c ft_print_helper.c

ODIR		= obj
OBJS		= $(addprefix $(ODIR)/, $(SRCS:.c=.o))

.PHONY: all
all: $(NAME)

.PHONY: debug
debug: fclean
debug: CFLAGS += -O0 -DDEBUG -g
debug: all

.PHONY: release
release: fclean
release: CFLAGS	+= -O2 -DNDEBUG
release: all

.PHONY: $(NAME)
$(NAME): prep $(OBJS)

.PHONY: $(ODIR)/%.o
$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: prep
prep:
	mkdir -p $(ODIR)

.PHONY: clean
clean:
	$(RM) -r $(ODIR)

.PHONY: fclean
fclean: clean

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: all
