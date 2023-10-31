/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** handle g conversion
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"
#include "include/my_printf.h"

int handle_g(va_list *params, format_string *fs, int upper)
{
    return 0;
}

int handle_g_lower(va_list *params, format_string *fs)
{
    return handle_g(params, fs, 0);
}

int handle_g_upper(va_list *params, format_string *fs)
{
    return handle_g(params, fs, 1);
}
