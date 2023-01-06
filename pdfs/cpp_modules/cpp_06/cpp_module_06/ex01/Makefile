# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 11:28:13 by cyalniz           #+#    #+#              #
#    Updated: 2022/10/25 11:28:13 by cyalniz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convers

FILES = $(wildcard *.cpp)

CC = c++ 

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

OBJECTS = $(FILES:.cpp=.o)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all