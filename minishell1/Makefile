##
## Makefile for Makefile in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
## 
## Made by BETTINELLI Paul-Marie
## Login   <Paul-Marie@epitech.net>
## 
## Started on  Tue Jan 17 09:15:19 2017 BETTINELLI Paul-Marie
## Last update Sat Jul 15 09:23:12 2017 BETTINELLI Paul-Marie
##

CC	=	@gcc
AR	=	@ar rc
RM	=	@rm -f

SRC	=	$(addprefix src/,	\
		get_essential_environ.c	\
		error_handling_env.c	\
		access_to_pid.c		\
		concatenation.c		\
		environ.c		\
		my_exec.c		\
		swap_tab.c		\
		get_path.c		\
		normal.c		\
		new_cmd.c		\
		get_cmd.c		\
		split.c			\
		mysh.c			\
		loop.c			\
		cmd.c			\
		main.c)

LIB	=	$(addprefix lib/my/,	\
		my_sort_to_wordtab.c	\
		my_str_to_wordtab.c	\
		get_next_line.c		\
		my_put_nbr.c		\
		my_putchar.c		\
		my_strcpy.c		\
		my_revstr.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_intlen.c		\
		get_line.c		\
		number.c)

NOM	=	$(basename $(notdir $(SRC)))
NAME	=	mysh

OBJ	=	$(addprefix obj/, $(addsuffix .o, $(NOM)))
OBJL	=	$(LIB:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -g3
CPPFLAGS=	-Iinclude
LDFLAGS	=	-Llib/my/libmy.a
LDLIBS	=	-lm

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJL)
	$(AR) lib/my/libmy.a $(OBJL)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDLIBS) -o $(NAME) $(OBJ) -L. ./lib/my/libmy.a
	$(eval($(MAK) = 42))
ifeq ($(MAK),)
	@echo -e "\033[32m* * * * * COMPLETED * * * * *\033[0m"
endif

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJL)

fclean:	clean
	$(RM) $(NAME)
	$(RM) lib/my/libmy.a
	$(eval($(CLE) = 42))
ifeq ($(CLE),)
	@echo -e "\033[31m* * * * *  CLEANED  * * * * *\033[0m"
endif

re:	fclean all

obj/%.o:	src/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -c -o $@ $< && echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" || echo -e "\e[91;5m[KO]\e[25m" $< "\033[0m"

$(VERBOSE).SILENT: all clean fclean re

.PHONY: all clean fclean re
