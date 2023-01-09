# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 22:03:08 by tjensen           #+#    #+#              #
#    Updated: 2022/10/22 04:02:21 by gsever           ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME        := minishell

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -O2

#	All process use for compiling.
UNAME		:= $(shell uname -s)
NUMPROC		:= 8

OS			:= NULL
# RL_INC_OS	= /goinfre/$(USER)/brew/Cellar/readline/8.2.1/include
# RL_LIB_OS	= /goinfre/$(USER)/brew/Cellar/readline/8.2.1/lib
 RL_INC_OS = /opt/homebrew/Cellar/readline/8.2.1/include/
 RL_LIB_OS = /opt/homebrew/Cellar/readline/8.2.1/lib

CPPFLAGS    := -I./inc -I./lib/libft/inc \
	-I$(RL_INC_OS)
# -I/Users/gsever/goinfre/brew/include
# -I/opt/homebrew/Cellar/readline/8.2.1/include/
DEPFLAGS     = -MT $@ -MMD -MP -MF $(DDIR)/$*.d

LDFLAGS     := -L./lib/libft \
	-L$(RL_LIB_OS)
# -L/Users/gsever/goinfre/brew/lib
# -L/opt/homebrew/Cellar/readline/8.2.1/lib

LDLIBS      := -lft -lreadline

VPATH       := src/ src/builtin/ src/cmd/ src/env/ src/exec/ src/expand/ \
			   src/lexer/ src/parser/ src/printer/ src/redir/ src/signals/ \
			   src/token/ src/utils/
SRCS        := minishell.c
SRCS        += builtin_echo.c builtin_cd.c builtin_exit.c builtin_pwd.c \
			   builtin_env.c builtin_export.c builtin_unset.c builtin.c
SRCS        += cmd.c scmd.c
SRCS        += env.c env_modify.c
SRCS        += exec.c exec_pipeline.c exec_pipeline_pipes.c exec_scmd.c \
			   exec_scmd_path.c exec_wait.c exec_group.c exec_exit_status.c
SRCS        += expand.c expand_wildcard.c expand_wildcard_utils.c \
			   expand_var.c expand_var_split.c
SRCS        += lexer.c lexer_syntax.c lexer_token_other.c lexer_token_text.c
SRCS        += parser.c parser_scmd.c parser_pipeline.c parser_group.c \
			   parser_heredoc.c
SRCS        += printer_token.c printer_scmd.c printer_cmd.c
SRCS        += redir.c redir_undo.c
SRCS        += signals.c
SRCS        += token.c token_list.c
SRCS        += utils_error.c utils_gnl.c utils_lst.c utils_split.c utils_str.c

ODIR        := obj
OBJS        := $(SRCS:%.c=$(ODIR)/%.o)

DDIR        := $(ODIR)/.deps
DEPS        := $(SRCS:%.c=$(DDIR)/%.d)

# **************************************************************************** #
#	SYSTEM SPECIFIC SETTINGS							   					   #
# **************************************************************************** #

# ifeq ($(shell uname -s), Linux)
# 	CFLAGS += -D LINUX -Wno-unused-result
# endif

#	Compiling with all threads.
ifeq ($(UNAME), Linux)
	NUMPROC	:= $(shell grep -c ^processor /proc/cpuinfo)
	OS = "You are connected from -$(CYAN)$(UNAME)$(X)- 🐧 Welcome -$(CYAN)$(USER)$(X)- 😄!"
	RL_INC_OS := /goinfre/homebrew/opt/readline/include -fcommon
	RL_LIB_OS := /goinfre/homebrew/opt/readline/lib -fcommon
else ifeq ($(UNAME), Darwin)
	NUMPROC	:= $(shell sysctl -n hw.ncpu)
	OS = "You are connected from 42 school's iMac 🖥 ! Welcome $(CYAN)$(USER)$(X)"
	ifeq ($(USER), yuandre)
		OS = "You are connected from -$(CYAN)MacBook$(X)- 💻 Welcome -$(CYAN)$(USER)$(X)-!"
		RL_INC_OS := /opt/homebrew/Cellar/readline/8.2.1/include/
		RL_LIB_OS := /opt/homebrew/Cellar/readline/8.2.1/lib
	endif
	ifeq ($(USER), akaraca)
		OS = "You are connected from -$(CYAN)MacBook$(X)- 💻 Welcome -$(CYAN)$(USER)$(X)-!"
		RL_INC_OS	:= /goinfre/$(USER)/homebrew/Cellar/readline/8.2.1/include
		RL_LIB_OS	:= /goinfre/$(USER)/homebrew/Cellar/readline/8.2.1/lib
	endif
endif

# **************************************************************************** #
#   RULES                                                                      #
# **************************************************************************** #

.PHONY: all clean fclean re test

$(NAME): lib/libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)
	@echo $(OS) $(NUMPROC) cekirdekle derlendi

$(ODIR)/%.o: %.c $(DDIR)/%.d | $(ODIR) $(DDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

$(ODIR):
	mkdir -p $@

$(DDIR):
	mkdir -p $@

%.a:
	$(MAKE) -C $(dir $@)

all:
	@$(MAKE) $(NAME) -j $(NUMPROC)

clean:
	$(MAKE) -C lib/libft fclean
	$(RM) -r $(DDIR) $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	@cd tests && bash tester.sh a

$(DEPS):
include $(wildcard $(DEPS))
