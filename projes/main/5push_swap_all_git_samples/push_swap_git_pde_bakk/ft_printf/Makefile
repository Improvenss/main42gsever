# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pde-bakk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/02 17:36:51 by pde-bakk      #+#    #+#                  #
#    Updated: 2021/04/05 14:03:35 by pde-bakk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
INCLUDE = -I ./include_internal

SRC_DIR = ./src
SRC = ft_printf.c ft_flags.c ft_itoa_base.c ft_putstuff.c \
ft_typefinder.c ft_longfinders.c ft_longlongfinders.c ft_shortfinders.c \
ft_shortshortfinders.c ft_floats.c ft_moreputstuff.c ft_ultoa.c ft_floats2.c \
ft_floats3.c ft_memsetfunctions.c

FILES = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra
ifdef DEBUG
  FLAGS += -g -fsanitize=address
else
  FLAGS += -Ofast
endif

# COLORS
SHELL := /bin/bash
PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(YELLOW)Linking the library\n"
	ar -rcs $(NAME) $(OBJS)
	@printf "$(GREEN)Done!$(RESET)\n"

%.o: %.c
	@$(CC) -c $(FLAGS) $(INCLUDE) $^ -o $@

clean:
	@/bin/rm -f *.o *~ *.gch $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

bonus: re
	@printf "$(PINK)Linking bonus files$(RESET)\n"
