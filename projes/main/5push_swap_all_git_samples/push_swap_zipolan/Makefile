NAME	=	push_swap

CC		=	gcc

SRCS 	= 	src/args.c src/check_error.c src/compute.c \
				src/ft_split.c src/main.c src/mark.c \
				src/perform.c src/ps.c src/push_to_b.c \
				src/r.c  src/rr.c src/sort_big.c src/sort_small.c \
				src/utils.c src/utils2.c \

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			cc ${FLAGS} ${OBJS} -o ${NAME}

%.o : %.c
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re