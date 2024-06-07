##
## EPITECH PROJECT, 2023
## map_generator
## File description:
## Makefile
##

CC = gcc

NAME = visualizer

SRC := $(shell find -name "*.c")

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -I include -l csfml-graphics -l csfml-window \
	-l csfml-system -l csfml-audio -lm

clean:
	rm -rf *#
	rm -rf *~
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
