/*
** EPITECH PROJECT, 2023
** p_flag
** File description:
** p flag for my_printf
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

int handle_pointer(va_list *params, format_string *fs)
{
    int cnt = 2;
    unsigned long long int n = va_arg(*params, unsigned long long int);

    cnt += my_getint_base_len(n, "0123456789abcdef");
    my_putstr("0x");
    my_getint_base(n, "0123456789abcdef");
    return cnt;
}
