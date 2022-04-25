# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 19:51:09 by tjensen           #+#    #+#              #
#    Updated: 2021/09/28 16:08:23 by tjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

MODULES		= $(wildcard modules/*)
INCLUDES	= -I./include/

# find all SRCS "ls -l *.c | awk '{printf("%s ", $9)}'"
SDIR		= src
SRCS_FILES	= ft_abs.c ft_atol.c ft_atod.c ft_bzero.c ft_calloc.c ft_fibonacci.c \
			  ft_find_next_prime.c ft_get_numlen.c ft_get_unumlen.c ft_is_prime.c \
			  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			  ft_iterative_factorial.c ft_iterative_power.c ft_lstadd_back.c \
			  ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			  ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_ltoa.c \
			  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_base_fd.c ft_putnbr_fd.c \
			  ft_putstr_fd.c ft_putunbr_base_fd.c ft_putunbr_fd.c \
			  ft_recursive_factorial.c ft_recursive_power.c ft_split.c ft_sqrt.c \
			  ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRCS		= $(addprefix $(SDIR)/, $(SRCS_FILES))

ODIR		= obj
OBJS		= $(SRCS:$(SDIR)/%.c=$(ODIR)/%.o)

.PHONY: all
all: $(NAME)

.PHONY: debug
debug: CFLAGS += -O0 -DDEBUG -g
debug: all

.PHONY: release
release: CFLAGS	+= -O2 -DNDEBUG
release: all

.PHONY: $(NAME)
$(NAME): $(MODULES) prep $(OBJS)
	ar -crs $(NAME) $(OBJS) $(addsuffix /obj/*.o, $(MODULES))

.PHONY: $(ODIR)/%.o
$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: $(MODULES)
$(MODULES):
	make -C $@ $(MAKECMDGOALS)

.PHONY: prep
prep:
	mkdir -p $(ODIR)

.PHONY: clean
clean: $(MODULES)
	$(RM) -r $(ODIR)

.PHONY: fclean
fclean: $(MODULES) clean
	$(RM) $(NAME)

.PHONY: re
re: $(MODULES) fclean all

.PHONY: bonus
bonus: all
