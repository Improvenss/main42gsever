# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:13:08 by gsever            #+#    #+#              #
#    Updated: 2022/11/06 01:23:03 by akaraca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line

#	Flags for compile
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I$(HEADERS_DIRECTORY)

#	HEADERS Parts --> Kutuphane --> OK
HEADERS_DIRECTORY = ./includes/
HEADERS_LIST = \
		get_next_line.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

#	Source Files --> OK
SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = \
		get_next_line.c\
		get_next_line_utils.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

#	Object Files --> (Compiled files directory) -> OK
OBJECTS_DIRECTORY = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

#	COLORS --> 🟥 🟩 🟦
LB		:= \033[0;36m
BLUE	:= \033[0;34m
YELLOW	:= \033[0;33m
GREEN	:= \033[0;32m
RED		:= \033[0;31m
RESET	:= \033[0m
X		:= \033[m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
# @printf "%-57b %b" "$(GREEN)COMPILED $(NAME)" "$(GREEN)[FINISHED]$(X)\n"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
# @echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
# @printf "%-57b %b" "$(BLUE)COMPILED $(LB)$@" "$(GREEN)[✓]$(X)\n"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
# @echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"

fclean: clean
# @echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
