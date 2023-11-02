/*
** EPITECH PROJECT, 2023
** MY_PUTSTR_PRECISION
** File description:
** Function that displays, one-by-one, the characters
** of a string until a specified precision
*/
#include "../../include/my.h"

int my_putstr_precision(char const *str, int precision)
{
    int i = 0;

    if (precision == -1)
        precision = my_strlen(str);
    while (str[i] != '\0' && i < precision) {
        my_putchar(str[i]);
        i++;
    }
    return precision;
}
