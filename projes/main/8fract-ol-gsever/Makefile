# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 15:04:59 by gsever            #+#    #+#              #
#    Updated: 2022/06/05 17:33:17 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc

#	Flags for compile

FLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = -lmlx -lm -lft\
	-L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY)\
	-framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

#	Libft Part --> OK
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libraries/libft
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

#	Minilibx Part --> OK
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./libraries/minilibx_opengl
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

#	HEADERS Parts --> Kutuphane --> OK
HEADERS_LIST = \
	fractol.h\
	key_macos_en.h\
	key_macos_de.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

#	Source Files --> OK
SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = \
			main.c\
			fractol.c\
			color.c\
			draw.c\
			helper.c\
			utils.c \
			key_actions.c\
			mouse_actions.c \
			fractal_mandelbrot.c\
			fractal_julia.c \
			fractal_burning_ship.c\
			fractal_celtic_mandelbrot.c\
			ft_atod.c\
			ft_get_unumlen.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

#	Object Files --> (Compiled files directory) -> OK
OBJECTS_DIRECTORY = objects/
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

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@printf "%-57b %b" "$(GREEN)CREATED $(NAME)" "$(GREEN)[FINISHED]$(X)\n"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@printf "%-57b %b" "$(BLUE)COMPILED $(LB)$@" "$(GREEN)[✓]$(X)\n"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@printf "%-57b %b" "$(BLUE)COMPILED $(LIBFT)" "$(GREEN)[✓]$(X)\n"

$(MINILIBX):
	@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(RESET)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)
	@printf "%-57b %b" "$(BLUE)COMPILED $(LB)$(MINILIBX)" "$(GREEN)[MINILIBX FINISHED]$(X)\n"


clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@echo "$(NAME): $(RED)$(LIBFT_DIRECTORY) was deleted$(RESET)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@echo "$(NAME): $(RED)$(MINILIBX_DIRECTORY) was deleted$(RESET)"
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(MINILIBX)
	@echo "$(NAME): $(RED)$(MINILIBX) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all