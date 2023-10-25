/*
** EPITECH PROJECT, 2023
** e_flag
** File description:
** e_flag for my_printf
*/

#include <stdarg.h>
#include "include/my.h"

static int get_exp(double nb)
{
    int exp = 0;
    int rest = nb / 10;

    while (rest != 0) {
        exp++;
        rest = rest / 10;
    }
    return exp;
}

int handle_scientific_not(va_list *params)
{
    double nb = va_arg(*params, double);
    int exp;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    exp = get_exp(nb);
    for (int i = 0; i < exp; i++) {
        nb = nb / 10;
    }
    my_putfloat(nb, 6);
    my_putchar('e');
    if (exp < 10) {
        my_putchar('0');
    }
    my_put_nbr(exp);
    return 0;
}