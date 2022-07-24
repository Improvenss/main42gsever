# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 20:22:17 by gsever            #+#    #+#              #
#    Updated: 2022/07/25 00:48:40 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CHECKER		= checker

#	Flags for compile
CC			= gcc
FLAGS		= -Wall -Werror -Wextra

#	Libft Part --> OK
LIBFTDIR	= ./libraries/libft

#	Locations Part --> not ok
LIBRARIES	= -L$(LIBFTDIR)/ -lft
INCLUDES	= -I$(HEADERS_DIRECTORY) -I$(LIBFTDIR)/includes/

#	HEADERS Parts --> Kutuphane --> OK
HEADERS_LIST = \
	push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

#	Source Files --> OK
SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = \
			algorithms_push_b.c\
			args.c\
			check_error.c\
			compute.c\
			find.c\
			free.c\
			main.c\
			mark.c\
			operations_push.c\
			operations_r_reverse.c\
			operations_rotate.c\
			operations_swap.c\
			perform.c\
			score_init.c\
			sort_small.c\
			sorting.c\
			utils.c\
			write_all_stack.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

#	Checker Files --> OK
CHECKER_DIRECTORY = ./sources/
CHECKER_LIST = \
			algorithms_push_b.c\
			args.c\
			check_error.c\
			checker_ps.c\
			checker.c\
			compute.c\
			find.c\
			free.c\
			mark.c\
			operations_push.c\
			operations_r_reverse.c\
			operations_rotate.c\
			operations_swap.c\
			perform.c\
			score_init.c\
			utils.c\
			write_all_stack.c
CHECKER_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(CHECKER_LIST))

#	Object Files --> (Compiled files directory) -> OK
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
OBJECTS_CH_DIRECTORY = objects/
OBJECTS_CH_LIST = $(patsubst %.c, %.o, $(CHECKER_LIST))
OBJECTS_CH = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_CH_LIST))

#	COLORS --> 🟥 🟩 🟦
LB		= \033[0;36m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
GREEN	= \033[0;32m
RED		= \033[0;31m
RESET	= \033[0m
X		= \033[m

#	LEAKS --> Checking this program have memory leaks.
LEAKS	= leaks -atExit -- ./push_swap 9 1 8 2 7 3 6 4 5

.PHONY: all libft clean fclean re leaks

all: $(NAME) checker

#	Compiling
$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@printf "%-57b %b" "$(BLUE)COMPILED $(LB)$@" "$(GREEN)[✓]$(X)\n"

$(NAME): libft $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBRARIES)
	@printf "%-57b %b" "$(GREEN)CREATED $(NAME)" "$(GREEN)[FINISHED]$(X)\n"

#	Objects file creating
$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

#	My Library --> OK
libft:
ifneq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), $(NAME) $(CHECKER)))
	@make -C $(LIBFTDIR) $(MAKECMDGOALS) --silent
else
	@make -C $(LIBFTDIR) --silent
endif

clean: libft
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
#@echo "$(NAME): $(RED)$(CHECKER_DIRECTORY) was deleted$(RESET)"

fclean: libft clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
#@echo "$(NAME): $(RED)$(CHECKER) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

leaks:
	$(LEAKS)

# **************************************************************************** #
#						       CHECKER RULES        						   #
# **************************************************************************** #

# $(CHECKER): libft $(OBJECTS_DIRECTORY) $(CHECKER) $(OBJECTS)
# 	@$(CC) $(FLAGS) -o $(CHECKER) $(OBJECTS) $(LIBRARIES)
# 	@printf "%-57b %b" "$(GREEN)CREATED $(NAME)" "$(GREEN)[FINISHED]$(X)\n"

$(CHECKER): libft $(OBJECTS_CH)
	$(CC) $(FLAGS) -o $(CHECKER) $(OBJECTS_CH) $(LIBRARIES)
	@printf "%-57b %b" "$(GREEN)CREATED $(CHECKER)" "$(GREEN)[FINISHED]$(X)\n"