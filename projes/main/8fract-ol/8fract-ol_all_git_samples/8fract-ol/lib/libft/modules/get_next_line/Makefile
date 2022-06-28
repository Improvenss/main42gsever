# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 10:42:31 by tjensen           #+#    #+#              #
#    Updated: 2021/09/15 11:23:51 by tjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./include/ -I../../include/

SDIR		= src
SRCS 		= $(SDIR)/get_next_line_bonus.c $(SDIR)/get_next_line_utils_bonus.c

ODIR		= obj
OBJS		= $(SRCS:$(SDIR)/%.c=$(ODIR)/%.o)

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

$(NAME): prep $(OBJS)

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
