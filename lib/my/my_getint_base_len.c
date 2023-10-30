/*
** EPITECH PROJECT, 2023
** MY_GETINT_BASE_LEN
** File description:
** Function that converts and returns the length of a decimal number
** into a number in a given base.
*/
#include <stdlib.h>
#include "../../include/my.h"

static int my_getint_base_size(
    unsigned long long int nbr, char const *base)
{
    int len = my_strlen(base);
    int i = 0;

    while (nbr != 0) {
        nbr = nbr / len;
        i++;
    }
    return i;
}

static char *get_str(unsigned long long int nbr, char const *base)
{
    int len = my_strlen(base);
    int dig;
    int i = 0;
    int size = my_getint_base_size(nbr, base);
    char *dest = malloc(sizeof(char) * (size + 1));

    if (nbr == 0)
        return "0";
    while (nbr != 0) {
        dig = nbr % len;
        nbr = nbr / len;
        dest[i++] = base[dig];
    }
    dest[i] = '\0';
    return my_revstr(dest);
}

int my_getint_base_len(unsigned long long int nbr, char const *base)
{
    char *str = get_str(nbr, base);

    return my_strlen(str);
}
