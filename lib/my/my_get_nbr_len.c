/*
** EPITECH PROJECT, 2023
** MY_GET_NBR_LEN
** File description:
** Function that returns number len
*/
#include "../../include/my.h"

static long int get_next(long long int nb)
{
    int cnt = 1;

    nb = nb / 10;
    if (nb != 0) {
        cnt += get_next(nb);
    }
    return cnt;
}

int my_get_nbr_len(long long int nb)
{
    long long int lg = nb;
    int cnt = 0;

    if (lg < 0) {
        cnt++;
        lg = lg * -1;
    }
    cnt += get_next(lg);
    return cnt;
}
