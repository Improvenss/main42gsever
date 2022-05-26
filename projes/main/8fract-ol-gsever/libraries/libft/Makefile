# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 02:23:57 by gsever            #+#    #+#              #
#    Updated: 2022/05/25 16:50:01 by gsever           ###   ########.fr        #
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

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
