/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_SQUARE_ROOT
** File description:
** return the square root of the function given as an argument
*/
#include "my.h"

int my_sqrt(int nb)
{
    int square = 0;

    while (square * square <= nb) {
        if (square * square >= nb) {
            return (square);
        }
        square = square + 1;
    }
    return (0);
}
