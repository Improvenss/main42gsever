# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 19:51:09 by tjensen           #+#    #+#              #
#    Updated: 2021/10/15 14:17:09 by tjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

MODULES		= $(wildcard modules/*)
INCLUDES	= -I./include/

# find all SRCS "ls -l *.c | awk '{printf("%s ", $9)}'"
SDIR		= src
SRCS_FILES	= ft_abs.c ft_atod.c ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c ft_fibonacci.c \
			  ft_find_next_prime.c ft_free.c ft_free_split.c ft_get_numlen.c ft_get_unumlen.c ft_is_prime.c \
			  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			  ft_iterative_factorial.c ft_iterative_power.c ft_itoa.c ft_lstadd_back.c \
			  ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			  ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_ltoa.c ft_max.c \
			  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_base_fd.c ft_putnbr_fd.c \
			  ft_putstr_fd.c ft_putunbr_base_fd.c ft_putunbr_fd.c \
			  ft_recursive_factorial.c ft_recursive_power.c ft_split.c ft_sqrt.c \
			  ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			  ft_strrchr.c ft_strtrim.c ft_strtoi.c ft_substr.c ft_tolower.c ft_toupper.c
SRCS		= $(addprefix $(SDIR)/, $(SRCS_FILES))

ODIR		= obj
OBJS		= $(SRCS:$(SDIR)/%.c=$(ODIR)/%.o)

# COLORS
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

# **************************************************************************** #
#						SYSTEM SPECIFIC SETTINGS							   #
# **************************************************************************** #

UNAME_S	= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += -D LINUX -Wno-unused-result
endif

# **************************************************************************** #
#									RULES									   #
# **************************************************************************** #

.PHONY: all
all: header $(NAME)

.PHONY: debug
debug: CFLAGS += -O0 -DDEBUG -g
debug: all

.PHONY: release
release: fclean
release: CFLAGS	+= -O2 -DNDEBUG
release: all

header:
	@printf "%b" "###############################################\n"
	@printf "%-14b %b" "$(WARN_COLOR)#######" "LIBFT$(NO_COLOR)\n"

.PHONY: $(NAME)
$(NAME): $(MODULES) prep $(OBJS)
	@ar -crs $(NAME) $(OBJS) $(addsuffix /obj/*.o, $(MODULES))
	@printf "%-14b %-42b %b" "$(OK_COLOR)=======" "$(OK_COLOR)$(NAME)" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

.PHONY: $(ODIR)/%.o
$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "%-57b %b" "$(COM_COLOR)compile $(OBJ_COLOR)$@" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

.PHONY: $(MODULES)
$(MODULES):
	@make -C $@ $(MAKECMDGOALS)
	@printf "%-14b %-42b %b" "$(COM_COLOR)$(MAKECMDGOALS)" "$(OBJ_COLOR)$@" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

.PHONY: prep
prep:
	@mkdir -p $(ODIR)

.PHONY: clean
clean: header $(MODULES)
	@$(RM) -r $(ODIR)
	@printf "%-50b %b" "$(COM_COLOR)clean" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

.PHONY: fclean
fclean: header $(MODULES) clean
	@$(RM) $(NAME)
	@printf "%-50b %b" "$(COM_COLOR)fclean" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

.PHONY: re
re: header fclean all

.PHONY: bonus
bonus: all
