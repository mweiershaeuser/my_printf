/*
** EPITECH PROJECT, 2023
** BASIC FLAGS
** File description:
** Basic flags for My printf
*/
#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

int handle_hex_upper(va_list *args, format_string *fs)
{
    return my_getint_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
}

int handle_hex_lower(va_list *args, format_string *fs)
{
    return my_getint_base(va_arg(*args, unsigned int), "0123456789abcdef");
}

int handle_oct(va_list *args, format_string *fs)
{
    return my_getint_base(va_arg(*args, unsigned int), "01234567");
}

int handle_unsigned(va_list *args, format_string *fs)
{
    return my_getint_base(va_arg(*args, unsigned int), "0123456789");
}
