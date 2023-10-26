/*
** EPITECH PROJECT, 2023
** p_flag
** File description:
** p flag for my_printf
*/

#include <stdarg.h>

int handle_pointer(va_list *params)
{
    return my_getint_base(va_arg(*params, unsigned int), "0123456789abcdef");
}
