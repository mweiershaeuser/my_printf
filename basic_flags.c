/*
** EPITECH PROJECT, 2023
** BASIC FLAGS
** File description:
** Basic flags for My printf
*/
#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

int handle_str(va_list *args, format_string *fs)
{
    return my_putstr(va_arg(*args, char *));
}

int handle_percent(va_list *args, format_string *fs)
{
    my_putchar('%');
    return 1;
}

int handle_float(va_list *args, format_string *fs)
{
    long double n = va_arg(*args, double);
    int num_len;
    int precision = fs->precision;

    num_len = my_getfloat_len(n, precision);
    if (num_len >= fs->width) {
        if (precision < 0)
            return my_putfloat(n, 6);
        if (precision == 0)
            return my_put_nbr(n);
        return my_putfloat(n, precision);
    }
}
