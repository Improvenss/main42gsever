# **************************************************************************** #
#                                                          LE - /              #
#                                                              /               #
#   Makefile                                         .::    .:/ .      .::     #
#                                                 +:+:+   +:    +:  +:+:+      #
#   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+       #
#                                                 #+#   #+    #+    #+#        #
#   Created: 2017/11/07 17:44:25 by eruaud       #+#   ##    ##    #+#         #
#   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     # #
#                                                         /                    #
#                                                        /                     #
# **************************************************************************** #
NAME = libft.a
CC = gcc
CFLAGS = -I includes -Wall -Wextra -Werror -c
FUNC = putchar strcpy strstr strnstr strncpy strncmp strncat \
strlcat strcat putstr putnbr isprint isdigit isalpha isalnum tolower \
toupper atoi strlen strcmp strdup memset bzero memcpy memccpy isascii \
memmove memchr memcmp strchr strrchr memalloc memdel strnew strdel \
strclr striter striteri strmap strmapi strequ strnequ strsub strjoin\
putchar_fd putstr_fd putendl putendl_fd putnbr_fd strtrim strsplit\
itoa lstnew lstdelone lstdel lstadd lstiter lstmap abs itoa_base \
swap isspace strupcase strlowcase strcapitalize isupper islower \
isblank strndup puttab_fd get_next_line
HEADER = -I includes/
NFUNC = $(addprefix ft_, $(FUNC))
PRINTF = ft_prf_atoi ft_prf_d ft_prf_launcher ft_prf_o ft_prf_pc ft_prf_s \
		 ft_prf_strutils2 ft_prf_c ft_prf_d2 ft_prf_numutil ft_printf \
		 ft_prf_p ft_prf_putwchar ft_prf_strutils ft_prf_utils ft_prf_x prf_tags
OBJ = $(addprefix build/, $(addsuffix .o, $(NFUNC))) \
      $(addprefix build/, $(addsuffix .o, $(PRINTF)))
SRC = $(addprefix src/, $(addsuffix .c, $(NFUNC))) \
      $(addprefix src, $(addsuffix .c, $(PRINTF)))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

./build/%.o : ./src/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

norm :
	@norminette $(SRC)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY = all clean fclean norm re
