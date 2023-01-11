# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 02:23:57 by gsever            #+#    #+#              #
#    Updated: 2022/11/11 10:39:22 by akaraca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libft.a

CC				:= gcc
FLAGS			:= -Wall -Werror -Wextra

#	Includes Files --> Kutuphane
INCLUDES_DIR	:= ./includes
INCLUDES		:= -I$(INCLUDES_DIR)
MODULES			= $(wildcard modules/*)

#	Sources Files --> Kaynak
SOURCES_DIRECTORY	:= ./sources
SOURCES			:= $(wildcard $(SOURCES_DIRECTORY)/*.c)

#	Objects Files --> Derleme sonrasi
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

.PHONY: all clean fclean re $(MODULES)

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS) $(MODULES)
	@ar -rcs $(NAME) $(OBJECTS) $(addsuffix /objects/*.o, $(MODULES))
	@printf "%-57b %b" "$(GREEN)CREATED $(NAME)" "$(GREEN)[FINISHED]$(X)\n"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
# @echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
# @printf "%-57b %b" "$(BLUE)COMPILED $(LB)$@" "$(GREEN)[✓]$(X)\n"

$(MODULES):
	@make -C $@ $(MAKECMDGOALS)
	@printf "%-14b %-42b %b" "$(BLUE)$(MAKECMDGOALS)" "$(LB)$@" "$(GREEN)[✓]$(X)\n"

clean: $(MODULES)
	@rm -rf $(OBJECTS_DIRECTORY)
	@printf "%-14b %-42b %b" "$(BLUE)$(MAKECMDGOALS)" "$(LB)$(NAME)" "$(GREEN)[✓]$(X)\n"
# @echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"

fclean: clean $(MODULES)
	@rm -f $(NAME)
	@printf "%-14b %-42b %b" "$(BLUE)$(MAKECMDGOALS)" "$(LB)$(NAME)" "$(GREEN)[✓]$(X)\n"
# @echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all
