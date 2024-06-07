##
## EPITECH PROJECT, 2023
## makefile
## File description:
## make file for the lib
##

SRC 	=	lib/my/my_printf.c \
		lib/my/my_put_nbr.c \
		lib/my/low_char.c \
		lib/my/my_strcmp.c\
		lib/my/my_putstr.c \
		lib/my/my_putchar.c \
		lib/my/my_put_float.c \
		lib/my/my_put_float_prec.c \
		lib/my/my_put_pointer.c \
		lib/my/is_n.c \
		lib/my/my_strlen.c \
		lib/my/conv_hexa.c \
		lib/my/decioctal.c \
		lib/my/is_sign.c \
		lib/my/my_revstr.c \
		lib/my/float_len.c \
		lib/my/exposant.c \
		lib/my/loop.c \
		lib/my/is_s_prec.c \
		lib/my/my_put_unsigned.c \
		lib/my/my_str_isnum.c \
		lib/my/my_strcpy.c \
		lib/my/my_strdup.c \
		lib/my/my_getnbr.c \
		lib/my/my_str_isalpha.c \

OBJ	=  	$(SRC:.c=.o)

NAME	= 	libmy.a

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc *.c -I -L libmy.a -o amazed -W -Werror -Wextra -Wall
clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)
	rm amazed

re: all fclean

launch:
	make
	make bonus/csfml_map_generator/
	make bonus/visualizer/
	./bonus/csfml_map_generator/map_generator ; ./amazed < generated_map.txt | ./bonus/visualizer/visualizer 

cleanmess: fclean
	make fclean bonus/csfml_map_generator/
	make fclean bonus/visualizer/
