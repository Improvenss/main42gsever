# gcc minishell.c ft_split.c ft_strjoin.c *.h -lreadline && ./a.out
NAME	:= minishell.a

APP		:= minishell

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -lreadline
FILES	:= $(wildcard *.c)
OBJ		:= $(FILES:%.c=%.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	$(CC) $(OBJ) -o $(APP)

all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME) $(APP)

re: fclean all

.PHONY: all clean fclean re
