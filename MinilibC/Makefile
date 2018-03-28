## 
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

LD		=	@ld
CC		=	@gcc
CXX		=	@g++
ASM		=	@nasm
ARM-AS		=	@arm-linux-gnueabi-as
ARM-LD		=	@arm-linux-gnueabi-ld

SRC		=	$(wildcard $(addprefix source/, *).asm)
NOM		=	$(basename $(notdir $(SRC)))
OBJ		=	$(addprefix object/, $(addsuffix .o, $(NOM)))
SRC-CRIT	=	$(wildcard $(addprefix tests/, *).c)
SRC-TEST	=	$(addprefix test/, main.c)
SRC-ARM		=	$(wildcard $(addprefix bonus/, *).S)
SRC-32		=	$(wildcard $(addprefix bonus/, *).asm)
OBJ-TEST        =       $(SRC-TEST:.c=.o)
OBJ-CRIT        =       $(SRC-CRIT:.c=.o)
OBJ-ARM		=	$(SRC-ARM:.S=.o)
OBJ-32		=	$(SRC-32:.asm=.o)

CPPFLAGS	+=	-Wall -Wextra -fPIC -g3
LDFLAGS		+=	-shared
CFLAGS		+=	-Iinclude -fno-builtin
CXXFLAGS	+=	-IInclude -fno-builtin
ASFLAGS		+=	-felf64 -Iinclude/
32FLAGS		+=	-felf32 -Iinclude/
CRITFLAGS	=	-lcriterion --coverage

SURNAME		=	asm
NAME		=	libasm.so
NARME		=	arm
NAME-32		=	lib32.so

END		=	\033[0m
BOLD		=	\033[1m
GREY		=	\033[30m
RED		=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(LD) $(LDFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)* * * * * COMPLETED * * * * *$(END)"

test_run:	all $(OBJ-CRIT)
	@$(CC) $(CFLAGS) $(CRITFLAGS) $(OBJ-CRIT) -ldl
	@echo "$(GREEN)* * * * * COMPLETED * * * * *$(END)"
	./a.out

intosh:		$(OBJ-TEST)
	@$(CC) -L$(NAME) -o $(SURNAME) $(OBJ-TEST)
	@echo "$(GREEN)* * *  TESTS COMPLETED  * * *$(END)"

bonus:		$(OBJ-ARM) $(OBJ-32)
	@$(ARM-LD) -o $(NARME) $(OBJ-ARM)
	@$(LD) $(LDFLAGS) -melf_i386 -o $(NAME-32) $(OBJ-32)
	@echo "$(GREEN)* * * * * COMPLETED * * * * *$(END)"

clean:
	@find . -type f \( -iname "*~" \) -delete
	@$(RM) $(OBJ)
	@$(RM) $(OBJ-ARM)
	@$(RM) $(OBJ-TEST)
	@$(RM) $(OBJ-CRIT)
	@$(RM) $(OBJ-32)
	@echo "$(RED)* * * * *  CLEANED  * * * * *$(END)"

fclean:	clean
	@$(RM) $(SURNAME)
	@$(RM) $(NARME)
	@$(RM) $(NAME)
	@$(RM) $(NAME-32)
	@$(RM) a.out

re:	fclean all

object/%.o:	%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<			\
	&& echo "$(GREEN)[OK]$(BOLD)" $< "$(END)"			\
	|| echo "$(RED)[KO]$(BOLD)" $< "$(END)"

Object/%.o:	Source/%.cpp
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<			\
	&& echo "$(GREEN)[OK]$(BOLD)" $< "$(END)"			\
	|| echo "$(RED)[KO]$(BOLD)" $< "$(END)"

object/%.o:	source/%.asm
	@$(ASM) $(ASFLAGS) -o $@ $<					\
	&& echo "$(GREEN)[OK]$(BOLD)" $< "$(END)"			\
	|| echo "$(RED)[KO]$(BOLD)" $< "$(END)"

%.o:		%.S
	@$(ARM-AS) -o $@ $<						\
	&& echo "$(GREEN)[OK]$(BOLD)" $< "$(END)"			\
	|| echo "$(RED)[KO]$(BOLD)" $< "$(END)"

%.o:		%.asm
	@$(ASM) $(32FLAGS) -o $@ $<					\
	&& echo "$(GREEN)[OK]$(BOLD)" $< "$(END)"			\
	|| echo "$(RED)[KO]$(BOLD)" $< "$(END)"

.PHONY: all clean fclean re intosh bonus
