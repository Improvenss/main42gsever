# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 20:22:17 by gsever            #+#    #+#              #
#    Updated: 2022/06/14 12:57:59 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CHECKER		:= checker

#	Flags for compile
CC			:= gcc
FLAGS		:= -Wall -Werror -Wextra 
INCLUDES	:= -I$(HEADERS_DIRECTORY) -I$(LIBFTDIR)/includes
LIBRARIES	:= -L$(LIBFTDIR) -lft

#	Libft Part --> OK
LIBFTDIR	= ./libraries/libft

#	HEADERS Parts --> Kutuphane --> OK
INCLUDES_DIR	:= ./includes
INCLUDES		:= -I$(INCLUDES_DIR)

#	Sources Files --> Kaynak
SOURCES_DIRECTORY	:= ./sources
SOURCES			:= $(wildcard $(SOURCES_DIRECTORY)/*.c)

#	Object Files --> (Compiled files directory) -> OK
OBJECTS_DIRECTORY	:= ./objects
OBJECTS			:= $(SOURCES:$(SOURCES_DIRECTORY)/%.c=$(OBJECTS_DIRECTORY)/%.o)

#	COLORS --> 🟥 🟩 🟦
LB		:= \033[0;36m
BLUE	:= \033[0;34m
YELLOW	:= \033[0;33m
GREEN	:= \033[0;32m
RED		:= \033[0;31m
RESET	:= \033[0m
X		:= \033[m

.PHONY: all libft clean fclean re

all: $(NAME)

$(NAME): libft $(OBJECTS_DIRECTORY) $(OBJECTS)
	ar -rcs $(NAME) $(LIBRARIES) $(OBJECTS)
	@printf "%-57b %b" "$(GREEN)CREATED $(NAME)" "$(GREEN)[FINISHED]$(X)\n"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@printf "%-57b %b" "$(BLUE)COMPILED $(LB)$@" "$(GREEN)[✓]$(X)\n"

libft:
ifneq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), $(NAME) $(CHECKER)))
	@make -C $(LIBFTDIR) $(MAKECMDGOALS) --silent
else
	@make -C $(LIBFTDIR) --silent
endif

clean: libft
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"

fclean: libft clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
