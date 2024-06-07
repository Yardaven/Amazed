/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_POWER_IT
** File description:
** return nb to thte power of p but recursive
*/

int my_power(int nb, int p)
{
    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    nb = nb * my_power(nb, p - 1);
    p = p - 1;
    return (nb);
}
