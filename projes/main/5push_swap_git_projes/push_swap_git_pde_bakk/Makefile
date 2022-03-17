NAME = push_swap checker
INCLUDE = -Iinclude -Ilibft/include -Igetnextline/include -Ift_printf/include -Ilibc_vector/include

SRC_DIR = ./src
CHUNK_DIR = $(SRC_DIR)/chunk
UTILS_DIR = $(SRC_DIR)/utils
STACK_DIR = $(SRC_DIR)/stack
OPERATIONS_DIR = $(SRC_DIR)/operations
CHECKER_DIR = $(SRC_DIR)/checker
SOLVER_DIR = $(SRC_DIR)/solver

UTILS = utils parsing max_in_stack
STACK_FILES = stack print_stacks stack_checks stack_operations
OP_FILES = operations push swap rotate reverse_rotate
CHECKER_FILES = checker
CHUNK_FILES = chunk chunk_size
SOLVER_FILES = main solving_utils set_sorted_pos radix_sort chunk_sort optimization smol_sort \
	push_chunks_to_b push_chunks_back_to_a

SRCS = $(addprefix $(UTILS_DIR)/, $(addsuffix .c, $(UTILS))) \
		$(addprefix $(CHUNK_DIR)/, $(addsuffix .c, $(CHUNK_FILES))) \
		$(addprefix $(STACK_DIR)/, $(addsuffix .c, $(STACK_FILES))) \
		$(addprefix $(OPERATIONS_DIR)/, $(addsuffix .c, $(OP_FILES)))
CHECKER_SRCS = $(addprefix $(CHECKER_DIR)/, $(addsuffix .c, $(CHECKER_FILES)))
SOLVER_SRCS = $(addprefix $(SOLVER_DIR)/, $(addsuffix .c, $(SOLVER_FILES)))

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
SOLVER_OBJS = $(SOLVER_SRCS:.c=.o)
LIBS_FOR_CHECKER = libft.a getnextline.a ft_printf.a
LIBS_FOR_PUSHSWAP = libft.a ft_printf.a libc_vector.a

# COLORS
PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

CFLAGS = -Wall -Werror -Wextra -pedantic
ifdef DEBUG
 CFLAGS += -g -fsanitize=address
else
 CFLAGS += -Ofast
endif
ifdef OPCOUNT
 CFLAGS += -D OPCOUNT
endif
SHELL := /bin/bash
export SHELL
export DEBUG

all: $(NAME)

$(word 1, $(NAME)): $(OBJS) $(SOLVER_OBJS) $(LIBS_FOR_PUSHSWAP)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(SOLVER_OBJS) $(LIBS_FOR_PUSHSWAP) -o $@
	@printf "$(PINK)Done building push_swap $(RESET)\n"

$(word 2, $(NAME)): $(OBJS) $(CHECKER_OBJS) $(LIBS_FOR_CHECKER)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(CHECKER_OBJS) $(LIBS_FOR_CHECKER) -o $@
	@printf "$(PINK)Done building checker $(RESET)\n"

%.a: %
#	@echo -e "$(GREEN)Compiling $@ in directory $< $(RESET)"
	@make -sC $<
	cp $</$@ .

%.o: %.c
#	echo -e "$(BLUE) Compiling file $< to $@ $(RESET)"
	$(CC) -c $(CFLAGS) $(INCLUDE) $^ -o $@

clean:
	/bin/rm -f $(OBJS) $(CHECKER_OBJS) $(SOLVER_OBJS)
	@/bin/rm -f *.o *~ *.gch

fclean: clean
	@make fclean -sC libft
	@make fclean -sC getnextline
	@make fclean -sC ft_printf
	@make fclean -sC libc_vector
	/bin/rm -f $(NAME) libft.a getnextline.a ft_printf.a libc_vector.a

re: fclean all
