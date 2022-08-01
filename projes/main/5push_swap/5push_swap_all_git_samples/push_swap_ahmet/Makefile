NAME	:= push_swap.a
B_NAME	:= checker.a

APP		:= push_swap
B_APP	:= checker

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
FILES	:= $(wildcard *.c)
OBJ		:= $(FILES:%.c=%.o)

B_FILES	:=  $(wildcard bonus/*.c )
B_OBJ	:= $(B_FILES:%.c=%.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	$(CC) -o $(APP) $(NAME)

all: $(NAME) bonus

bonus: $(B_OBJ) 
	ar -rcs $(B_NAME) $(B_OBJ)
	$(CC) -o $(B_APP) $(B_NAME)

clean:
	@rm -f *.o
	@rm -f bonus/*.o

fclean: clean
	@rm -f $(NAME) $(APP)
	@rm -f $(B_NAME) $(B_APP)

re: fclean all

.PHONY: all clean fclean re bonus
