NAME = push_swap

NAME_BONUS = push_swap_bonus

CHECKER = checker

CHECKER_BONUS = checker_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDES_PATH = includes/

INCLUDES = $(INCLUDES_PATH)utils.h

SRCS_PATH = srcs/push_swap/

SRCS_FILES = push_swap.c	utils.c	easy_solve.c	hard_solve.c	medium_solve.c

MAIN = srcs/push_swap/main.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

CHECKER_PATH = srcs/checker/

CHECKER_FILES = check.c

CHECKER_MAIN = srcs/checker/main.c

CHECKER_SRCS = $(addprefix $(CHECKER_PATH), $(CHECKER_FILES))

SHARE_PATH = srcs/share/

SHARE_FILES = parse.c	utils.c	operation1.c	operation2.c	operation3.c\
	operation4.c

SHARE_SRCS = $(addprefix $(SHARE_PATH), $(SHARE_FILES))

BONUS_PATH = srcs/bonus/

BONUS_FILES = bonus.c

BONUS_CHECKER_MAIN = srcs/bonus/main.c

BONUS2_PATH = srcs/bonus2/

BONUS2_FILES = bonus.c

BONUS2_MAIN = srcs/bonus2/main.c

BONUS2_SRCS = $(addprefix $(BONUS2_PATH), $(BONUS2_FILES))

BONUS_SRCS = $(addprefix $(BONUS_PATH), $(BONUS_FILES))

LIB_PATH = libft/

LIB = $(LIB_PATH)libft.a

OBJS = $(SRCS:.c=.o)

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

CHECKER_MAIN_OBJS = $(CHECKER_MAIN:.c=.o)

BONUS_CHECKER_MAIN_OBJS = $(BONUS_CHECKER_MAIN:.c=.o)

SHARE_OBJS = $(SHARE_SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

MAIN_OBJS = $(MAIN:.c=.o)

BONUS2_MAIN_OBJS = $(BONUS2_MAIN:.c=.o)

all : $(NAME) $(CHECKER)
	@echo "compile OK"

debug : CFLAGS+=-D\ DEBUG=1
debug : $(NAME) $(CHECKER)
	@echo "compile OK with debug version checker"

bonus : CFLAGS+=-D\ BONUS=1
bonus : $(CHECKER_BONUS) $(NAME_BONUS)
	@echo "compile bonus OK"

%.o : %.c $(INCLUDES) $(LIB)
	@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

$(LIB) :
	@$(MAKE) -C $(LIB_PATH)

$(NAME) : $(INCLUDES) $(OBJS) $(SHARE_OBJS) $(MAIN_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(SHARE_OBJS) $(MAIN_OBJS) $(LIB) -o $(NAME)

$(CHECKER) : $(INCLUDES) $(CHECKER_OBJS) $(SHARE_OBJS) $(CHECKER_MAIN_OBJS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(SHARE_OBJS) $(CHECKER_MAIN_OBJS) $(LIB) -o $(CHECKER)

$(CHECKER_BONUS) : $(INCLUDES) $(CHECKER_OBJS) $(SHARE_OBJS) $(BONUS_OBJS) $(BONUS_CHECKER_MAIN_OBJS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(SHARE_OBJS) $(BONUS_OBJS) $(BONUS_CHECKER_MAIN_OBJS) $(LIB) -o $(CHECKER_BONUS)

$(NAME_BONUS) : $(INCLUDES) $(OBJS) $(SHARE_OBJS) $(BONUS2_MAIN_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(SHARE_OBJS) $(BONUS2_OBJS) $(BONUS2_MAIN_OBJS) $(LIB) -o $(NAME_BONUS)

clean :
	@rm -rf $(OBJS) $(CHECKER_OBJS) $(SHARE_OBJS) $(CHECKER_MAIN_OBJS) $(MAIN_OBJS) $(BONUS_CHECKER_MAIN_OBJS) $(BONUS_OBJS) $(BONUS2_MAIN_OBJS)
	@$(MAKE) clean -C $(LIB_PATH)
	@echo "clean done"

fclean :
	@rm -rf $(OBJS) $(CHECKER_OBJS) $(SHARE_OBJS) $(CHECKER_MAIN_OBJS) $(MAIN_OBJS) $(BONUS_CHECKER_MAIN_OBJS) $(BONUS_OBJS) $(BONUS2_MAIN_OBJS)
	@rm -rf $(NAME) $(CHECKER) $(NAME_BONUS) $(CHECKER_BONUS) instructions
	@$(MAKE) fclean -C $(LIB_PATH)
	@echo "fclean done"

re : fclean all

norm :
	@norminette-old $(SRCS) $(INCLUDES) libft/*.c libft/*.h

.PHONY : all clean fclean re norm debug bonus
