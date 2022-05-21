# **************************************************************************** #
#                                                          LE - /              #
#                                                              /               #
#   Makefile                                         .::    .:/ .      .::     #
#                                                 +:+:+   +:    +:  +:+:+      #
#   By: ruaud <ruaud@student.42.fr>                +:+   +:    +:    +:+       #
#                                                 #+#   #+    #+    #+#        #
#   Created: 0017/12/28 15:26:42 by ruaud        #+#   ##    ##    #+#         #
#   Updated: 2018/04/24 18:51:20 by eruaud      ###    #+. /#+    ###.fr       #
#                                                         /                    #
#                                                        /                     #
# **************************************************************************** #

NAME = checker
PNAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMMON = testfiles cmds utils utils2 utils3 utils4 filling filling2
FUNC = checker $(COMMON)
PFUNC = algo_bucket algo_century algo_millenium algo_bogo splitter \
		push_swap $(COMMON)
PSRC = $(addprefix src/, $(addsuffix .c, $(PFUNC)))
POBJ = $(addprefix build/, $(addsuffix .o, $(PFUNC)))
SRC = $(addprefix src/, $(addsuffix .c, $(FUNC)))
OBJ = $(addprefix build/, $(addsuffix .o, $(FUNC)))
RED = \033[1;31m
GREEN = \033[1;92m
BLUE = \033[34;1m
YELLOW = \033[0;33m
HEADER = -I includes/ -I libft/includes/
LDLIBS = -lft
LDFLAGS = -L libft/

all: $(NAME)

$(NAME): $(OBJ) $(POBJ)
	@echo "\033[1;31mCompiling project..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HEADER) $(LDLIBS) $(LDFLAGS)
	@$(CC) $(CFLAGS) -o $(PNAME) $(POBJ) $(HEADER) $(LDLIBS) $(LDFLAGS)
	@echo "\033[1;92mSuccess !"

./build/%.o: ./src/%.c
	@echo "     $(YELLOW) → Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)
	@echo "     $(GREEN)   OK"

norm :
	@norminette $(SRC)
	@norminette $(PSRC)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(POBJ)
	@echo "  $(YELLOW)OBJ files have been deleted."

fclean:
	@/bin/rm -f $(OBJ) $(NAME)
	@/bin/rm -f $(POBJ) $(PNAME)
	@echo "  $(YELLOW)$(NAME) and OBJ files have been deleted."

re: fclean $(NAME)

.PHONY = all clean fclean re norm lib
