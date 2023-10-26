/*
** EPITECH PROJECT, 2023
** BASIC FLAGS
** File description:
** Basic flags for My printf
*/
#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

int handle_int(va_list *args, format_string *fs)
{
    return my_put_nbr(va_arg(*args, int));
}

int handle_char(va_list *args, format_string *fs)
{
    my_putchar(va_arg(*args, int));
    return 1;
}

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
    return my_putfloat(va_arg(*args, double), 6);
}
