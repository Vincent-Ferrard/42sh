##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## just a Makefile of the project
##

CFLAGS	=	-Wall -Wextra -W -I../include

BONUS_FILE	=	moveto.c	\
			get_prompt.c

FILE	=	../shell/cd.c			\
		../src/main.c			\
		../src/process.c		\
		../shell/split.c		\
		../shell/setenv.c		\
		../func/is_alpha.c		\
		../func/list_dir.c		\
		../func/function.c		\
		../func/func_comp.c		\
		../src/format_str.c		\
		../func/my_strlen.c		\
		../shell/next_obj.c		\
		../shell/execution.c		\
		../func/str_concat.c		\
		../shell/subcommand.c		\
		../src/play_with_fd.c		\
		../src/find_in_list.c		\
		../malloc/my_malloc.c		\
		../get/get_function.c		\
		../func/func_display.c		\
		../malloc/my_realloc.c		\
		../get/get_next_line.c		\
		../get/get_var_in_env.c		\
		../get/get_function_list.c

OBJ	=	$(FILE:.c=.o)

OBJ_BONUS	=	$(BONUS_FILE:.c=.o)

NAME	=	42sh

all:	$(OBJ_BONUS)	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(OBJ_BONUS) $(CFLAGS)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re
