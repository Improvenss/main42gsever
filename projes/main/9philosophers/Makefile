# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 18:14:42 by gsever            #+#    #+#              #
#    Updated: 2022/08/08 00:11:09 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philosophers

#	Flags for compile
CC			= gcc
FLAGS		= -Wall -Werror -Wextra

#	All process use for compiling.
# UNAME	:= $(shell uname -s)
NUMPROC	:= 8

#	Locations Part --> OK
INCLUDES	= -I$(HEADERS_DIRECTORY)

#	HEADERS Parts --> Kutuphane --> OK
HEADERS_DIRECTORY = ./includes/
# HEADERS_LIST = $(subst $(HEADERS_DIRECTORY),,$(wildcard $(HEADERS_DIRECTORY)*.h))
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

#	Source Files --> OK
SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = $(subst $(SOURCES_DIRECTORY),,$(wildcard $(SOURCES_DIRECTORY)*.c))
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

#	Object Files --> (Compiled files directory) -> OK
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

#	COLORS --> 🟥 🟩 🟦
LB		= \033[0;36m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
GREEN	= \033[0;32m
RED		= \033[0;31m
RESET	= \033[0m
X		= \033[m

#	LEAKS --> Checking this program have memory leaks.
LEAKS_PH	= leaks -atExit -- ./philosophers
#	You can use //system("leaks a.out");

.PHONY: all clean fclean re leaksps

all:
	@$(MAKE) $(NAME) -j $(NUMPROC)
#	@$(MAKE) -s $(NAME) -j $(NUMPROC)

#	Compiling
$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@printf "%-57b %b" "$(BLUE)COMPILED $(LB)$@" "$(GREEN)[✓]$(X)\n"

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)
	@printf "%-57b %b" "$(GREEN)CREATED $(NAME)" "$(GREEN)[FINISHED]$(X)\n"

#	Objects file creating
$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

#	Compiling with all threads.
ifeq ($(UNAME), Linux)
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME), Darwin)
	NUMPROC := $(shell sysctl -n hw.ncpu)
endif
# You can use --> man sysctl -> shell: sysctl -a | grep "hw.ncpu"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

leaksps:
	$(LEAKS_PH)
