# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 17:54:15 by gsever            #+#    #+#              #
#    Updated: 2022/11/02 12:39:02 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minirt

#	Flags for compile
CC			= gcc
FLAGS		= -Wall -Werror -Wextra

#	All process use for compiling.
UNAME		:= $(shell uname -s)
NUMPROC		:= 8

OS			:= NULL

#	Libft Part --> OK
LIBFTDIR		= ./libraries/libft
# LIBFT		= $(LIBFTDIR)/libft.a

#	Minilibx Part --> OK
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./libraries/modules/minilibx_opengl/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

#	Locations Part --> OK
LIBRARIES	= \
	-L$(LIBFTDIR)/ -lft \
	-L$(MINILIBX_DIRECTORY) -lmlx -lm -framework OpenGL -framework AppKit

# -L.brew/opt/readline/lib -lreadline
INCLUDES	= \
	-I$(HEADERS_DIRECTORY) \
	-I$(LIBFTDIR)/includes \
	-I$(MINILIBX_HEADERS) \

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
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
END		= \033[m
RESET	= \033[0m
X		= \033[m

#	COLORS BOLD--> B🟥 B🟩 B🟦
B_CYAN		= \033[1;36m
B_BLUE		= \033[1;34m
B_YELLOW	= \033[1;33m
B_GREEN		= \033[1;32m
B_RED		= \033[1;31m
B_RESET		= \033[1m
#NOTE: \033[ ile derlenince calisiyor \e[ ile derlenince bozuk calisiyor.

#	LEAKS --> Checking this program have memory leaks.
LEAKS_PH	= leaks -atExit -- ./minishell
#	You can use //system("leaks a.out");

#	Compiling with all threads.
ifeq ($(UNAME), Linux)
	NUMPROC	:= $(shell grep -c ^processor /proc/cpuinfo)
	OS = "You are connected from -$(CYAN)$(UNAME)$(X)- 🐧 Welcome -$(CYAN)$(USER)$(X)- 😄!"
else ifeq ($(UNAME), Darwin)
	NUMPROC	:= $(shell sysctl -n hw.ncpu)
	OS = "You are connected from 42 school's iMac 🖥 ! Welcome $(CYAN)$(USER)$(X)"
	ifeq ($(USER), yuandre)
		OS = "You are connected from -$(CYAN)MacBook$(X)- 💻 Welcome -$(CYAN)$(USER)$(X)-!"
	endif
	ifeq ($(USER), akaraca)
		OS = "You are connected from -$(CYAN)MacBook$(X)- 💻 Welcome -$(CYAN)$(USER)$(X)-!"
	endif
endif
# You can use --> man sysctl -> shell: sysctl -a | grep "hw.ncpu"

.PHONY: all clean fclean re leaksps

all:
	@$(MAKE) $(NAME) -j $(NUMPROC) --no-print-directory
#	@$(MAKE) -s $(NAME) -j $(NUMPROC)

#	Compiling
$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@printf "%-57b %b" "$(BLUE)COMPILED $(CYAN)$@" "$(GREEN)[✓]$(X)\n"

$(NAME): libft $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBRARIES) -o $(NAME)
	@printf "%-57b %b" "$(GREEN)CREATED $(NAME)" "[FINISHED]$(X)\n"
	@echo $(OS) $(NUMPROC) cekirdekle derlendi

#	Objects file creating
$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

#	My Library (Minilibx inside libft) --> OK
libft:
ifneq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), $(NAME)))
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
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

leaksps:
	$(LEAKS_RT)
