# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 02:23:57 by gsever            #+#    #+#              #
#    Updated: 2022/06/13 23:30:44 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libft.a
CC				:= gcc

#	Includes Files --> Kutuphane
INCLUDES_DIR	:= includes

#	Sources Files --> Kaynak
SOURCES_DIR		:= sources
SOURCES			:= $(wildcard $(SOURCES_DIR)/*.c)

#	Objects Files --> Derleme sonrasi
OBJ_DIR			:= objects
OBJ				:= $(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS			:= -Wall -Werror -Wextra -I ./$(INCLUDES_DIR)

#	COLORS --> 🟥 🟩 🟦
LB		:= \033[0;36m
BLUE	:= \033[0;34m
YELLOW	:= \033[0;33m
GREEN	:= \033[0;32m
RED		:= \033[0;31m
RESET	:= \033[0m
X		:= \033[m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@printf "%-57b %b" "$(GREEN)CREATED $(NAME)" "$(GREEN)[FINISHED]$(X)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "%-57b %b" "$(BLUE)COMPILED $(LB)$@" "$(GREEN)[✓]$(X)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re