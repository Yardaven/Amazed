##
## EPITECH PROJECT, 2023
## makefile
## File description:
## make file for the lib
##

SRC 	=	src/lib/my/my_printf.c \
		src/lib/my/my_put_nbr.c \
		src/lib/my/low_char.c \
		src/lib/my/my_strcmp.c\
		src/lib/my/my_putstr.c \
		src/lib/my/my_putchar.c \
		src/lib/my/my_put_float.c \
		src/lib/my/my_put_float_prec.c \
		src/lib/my/my_put_pointer.c \
		src/lib/my/is_n.c \
		src/lib/my/my_strlen.c \
		src/lib/my/conv_hexa.c \
		src/lib/my/decioctal.c \
		src/lib/my/is_sign.c \
		src/lib/my/my_revstr.c \
		src/lib/my/float_len.c \
		src/lib/my/exposant.c \
		src/lib/my/loop.c \
		src/lib/my/is_s_prec.c \
		src/lib/my/my_put_unsigned.c \
		src/lib/my/my_str_isnum.c \
		src/lib/my/my_strcpy.c \
		src/lib/my/my_strdup.c \
		src/lib/my/my_getnbr.c \
		src/lib/my/my_str_isalpha.c \

OBJ	=  	$(SRC:.c=.o)

NAME	= 	src/libmy.a

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc src/*.c -I -L src/libmy.a -o amazed -W -Werror -Wextra -Wall
clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)
	rm generated_map.txt
	rm amazed

re: all fclean

launch:
	make src/
	make src/bonus/csfml_map_generator/
	make src/bonus/visualizer/
	./src/bonus/csfml_map_generator/map_generator ; ./amazed < generated_map.txt | ./src/bonus/visualizer/visualizer 

cleanmess: fclean
	make fclean src/bonus/csfml_map_generator/
	make clean src/bonus/visualizer/
