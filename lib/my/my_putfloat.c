/*
** EPITECH PROJECT, 2023
** MY_PUTFLOAT
** File description:
** Function that displays the number given as a parameter
*/
#include "../../include/my.h"

static long int get_next_int(long int nb)
{
    long int next = nb % 10;
    int cnt = 0;

    nb = nb / 10;
    if (nb != 0) {
        cnt += get_next_int(nb);
    }
    cnt++;
    my_putchar(next + '0');
    return cnt;
}

static double put_float(double nb, int precision)
{
    int intpart = (int) nb;
    int cnt = 0;
    int rest = 0;

    nb = nb - intpart;
    my_putchar('.');
    for (int i = 0; i < precision; i++) {
        nb = nb * 10;
        rest = (int) nb % 10;
        my_putchar(rest + '0');
        cnt++;
    }
    return cnt + 1;
}

int my_putfloat(double nb, int precision)
{
    int cnt = 0;

    if (nb < 0) {
        my_putchar('-');
        cnt++;
        nb = nb * -1;
    }
    if (precision < 0)
        precision = 6;
    cnt += get_next_int((int) nb);
    cnt += put_float(nb, precision);
    return cnt;
}
