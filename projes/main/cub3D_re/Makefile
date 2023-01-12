# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 23:06:05 by gsever            #+#    #+#              #
#    Updated: 2023/01/12 17:55:25 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

#	Flags for compile
CC			= cc
FLAGS		= -Wall -Werror -Wextra

#	All process use for compiling.
UNAME		:= $(shell uname -s)

#	Libft Part --> OK
LIBFTDIR	= ./libraries/libft

#	Minilibx Part --> OK
# MINILIBX_DIRECTORY	= /libraries/minilibx_opengl
MINILIBX			= $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_HEADERS	= $(MINILIBX_DIRECTORY)

#	Locations Part --> OK
#	-lft vardi sildim.
LIBRARIES	= \
	-L$(LIBFTDIR)/ -lft \
	-L$(MINILIBX_DIRECTORY) $(MINILIBX_FLAGS)

INCLUDES	= \
	-I$(HEADERS_DIRECTORY) \
	-I$(LIBFTDIR)/includes
#	-I$(MINILIBX_HEADERS)

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

# Before run in the linux, set this input(for Xming): export DISPLAY=localhost:0.0
export DISPLAY = localhost:0.0

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

#	Compiling with all threads.
ifeq ($(UNAME), Linux)
	NUMPROC	:= $(shell grep -c ^processor /proc/cpuinfo)
	MINILIBX_DIRECTORY	:= ./libraries/minilibx_linux
	MINILIBX_FLAGS		:= -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz
	OS = "You are connected from -$(CYAN)$(UNAME)$(X)- 🐧 Welcome -$(CYAN)$(USER)$(X)- !"
else ifeq ($(UNAME), Darwin)
	NUMPROC	:= $(shell sysctl -n hw.ncpu)
	MINILIBX_DIRECTORY	:= ./libraries/minilibx_opengl
# MINILIBX_DIRECTORY	:= ./libraries/minilibx_42
	MINILIBX_FLAGS		:= -lm -lft -lmlx -framework OpenGL -framework AppKit
# MINILIBX_FLAGS		:= -lm -lft -framework Cocoa -framework OpenGL -framework IOKit
	OS = "You are connected from 42 school's iMac 🖥 ! Welcome $(CYAN)$(USER)$(X)"
	ifeq ($(USER), yuandre)
		OS = "You are connected from -$(CYAN)MacBook$(X)- 💻 Welcome -$(CYAN)$(USER)$(X)-!"
	endif
endif
# You can use --> man sysctl -> shell: sysctl -a | grep "hw.ncpu"

all:
	@$(MAKE) $(NAME) -j $(NUMPROC) --no-print-directory
#	@$(MAKE) -s $(NAME) -j $(NUMPROC)

$(NAME): libft $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBRARIES) -o $(NAME)
	@printf "%-57b %b" "$(GREEN)CREATED $(NAME)" "[FINISHED]$(X)\n"
	@echo $(OS) $(NUMPROC) cekirdekle derlendi

#	Compiling
$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@printf "%-57b %b" "$(BLUE)COMPILED $(CYAN)$@" "$(GREEN)[✓]$(X)\n"

#	Objects file creating
$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

clean: libft
	@rm -rf $(OBJECTS_DIRECTORY)

	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"

fclean: libft clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

# $(MINILIBX):
# 	@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(RESET)"
# 	@$(MAKE) -sC $(MINILIBX_DIRECTORY)
# 	@printf "%-57b %b" "$(BLUE)COMPILED $(LB)$(MINILIBX)" "$(GREEN)[MINILIBX FINISHED]$(X)\n"

#	My Library --> OK
libft:
ifneq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), $(NAME)))
	@make -sC $(MINILIBX_DIRECTORY) $(MAKECMDGOALS) --silent
	@make -sC $(LIBFTDIR) $(MAKECMDGOALS) --silent
else
	@make -sC $(MINILIBX_DIRECTORY) --silent
	@make -sC $(LIBFTDIR) --silent
endif

run:
	@echo "$(RED)You can run cub3D with Makefile as follows; 'make run MAP=map_1.cub'$(END)"
	@echo "$(YELLOW)▶ RUN CMD $(MAP)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/$(MAP)
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	./$(NAME) ./map/$(MAP)

maptest:
	@echo "$(GREEN)Before you start testing, set the false return value in main.c to 0.$(END)"
ifeq ($(wildcard cub3D), cub3D)

	@echo "$(BLUE)██████████████████▓▓▓▓▓▓▓▓▓▓⡷⠂MAP TEST⠐⢾▓▓▓▓▓▓▓▓▓▓██████████████████$(END)"


	@echo "$(YELLOW)▶ Out-of-Bounds Argument (map_chr_outside_2.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_chr_outside_2.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_chr_outside_2.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Out-of-Bounds Argument (map_chr_outside_1.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_chr_outside_1.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_chr_outside_1.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Map Empty vertical line (map_empty_line_3.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_empty_line_3.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_empty_line_3.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Map Empty line (map_empty_line_2.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_empty_line_2.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_empty_line_2.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ No spawn point (map_no_spawn.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_no_spawn.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_no_spawn.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Too many spwan point (map_to_many_spawn.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_to_many_spawn.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_to_many_spawn.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Extra character (map_extra_character.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_extra_character.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_extra_character.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Definitions is incorrect! (map_definitions_7.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_definitions_7.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_definitions_7.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Definitions is incorrect! (map_definitions_6.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_definitions_6.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_definitions_6.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Definitions file extension is incorrect! (map_definitions_5.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_definitions_5.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_definitions_5.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Definitions file does not exist! (map_definitions_4.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_definitions_4.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_definitions_4.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Definitions invalid input (map_definitions_3.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_definitions_3.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_definitions_3.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Definitions invalid input (map_definitions_2.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_definitions_2.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_definitions_2.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Definitions are missing or incorrect! (map_definitions_1.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_definitions_1.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_definitions_1.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ No map file (X.cub)$(END)"
	@./cub3D ./map/test_maps/X.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Empty map (map_empty.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_empty.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_empty.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ Empty line (map_empty_line.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_empty_line.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_empty_line.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"

	@echo "$(YELLOW)▶ No map (map_no_map.cub)$(END)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAP ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@cat ./map/test_maps/map_no_map.cub
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(END)"
	@./cub3D ./map/test_maps/map_no_map.cub
	@echo "$(GREEN)┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄$(END)"
else
	@echo "$(RED)▶ Must be compiled! $(END)"
endif

valleak:
	@valgrind -q --leak-check=yes --show-leak-kinds=all ./$(NAME) ./map/map_1.cub

leaks:
	@leaks $(NAME)

.PHONY: all clean fclean re libft run maptest valleak leaks