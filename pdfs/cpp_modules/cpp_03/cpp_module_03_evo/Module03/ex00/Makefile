NAME =		ClapTrap
CC =		c++
FLAGS =		-Wall -Werror -Wextra -std=c++98
SOURCE =	main.cpp \
			ClapTrap.cpp \

$(NAME):
			$(CC) $(FLAGS) $(SOURCE) -o  $(NAME)
all:		$(NAME)

clean:
			rm -rf $(NAME)

re:			clean all

.PHONY:		all clean re