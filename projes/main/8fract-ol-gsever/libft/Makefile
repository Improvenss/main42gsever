# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 02:23:57 by gsever            #+#    #+#              #
#    Updated: 2022/05/25 15:50:05 by gsever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			:= $(OBJ_DIR)/libft.a

CC				:= gcc

#	Includes Files
INCLUDES_DIR	:= includes
CFLAGS			:= -Wall -Wextra -Werror -I ./$(INCLUDES_DIR)

#	Sources Files
SOURCES_DIR		:= sources
SOURCES			:= $(wildcard $(SOURCES)/*.c)

#	Objects Files
OBJ_DIR			:= objects
OBJ				:= $(SOURCES:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)/ft_*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
