/*
** EPITECH PROJECT, 2023
** MY_GETFLOAT_LEN
** File description:
** Function that returns number len
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
    return cnt;
}

static double put_float(double nb, int precision)
{
    int intpart = (int) nb;
    int cnt = 0;
    int rest = 0;

    nb = nb - intpart;
    for (int i = 0; i < precision; i++) {
        nb = nb * 10;
        rest = (int) nb % 10;
        cnt++;
    }
    return cnt + 1;
}

int my_getfloat_len(double nb, int precision)
{
    int cnt = 0;

    if (nb < 0) {
        cnt++;
        nb = nb * -1;
    }
    if (precision < 0)
        precision = 6;
    cnt += get_next_int((int) nb);
    cnt += put_float(nb, precision);
    return cnt;
}
