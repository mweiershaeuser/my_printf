/*
** EPITECH PROJECT, 2023
** BASIC FLAGS
** File description:
** Basic flags for My printf
*/
#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

static int handle_hex(va_list *args, format_string *fs, int is_upper)
{
    int cnt = 0;
    unsigned int n = va_arg(*args, unsigned int);

    if (n == 0) {
        my_putchar('0');
        return 1;
    }
    if (my_strstr(fs->flags, "#")) {
        cnt += 2;
        my_putstr(is_upper ? "0X" : "0x");
    }
    return cnt + my_getint_base(
        n, is_upper ? "0123456789ABCDEF" : "0123456789abcdef");
}

int handle_hex_upper(va_list *args, format_string *fs)
{
    return handle_hex(args, fs, 1);
}

int handle_hex_lower(va_list *args, format_string *fs)
{
    return handle_hex(args, fs, 0);
}

int handle_oct(va_list *args, format_string *fs)
{
    return my_getint_base(va_arg(*args, unsigned int), "01234567");
}

int handle_unsigned(va_list *args, format_string *fs)
{
    return my_getint_base(va_arg(*args, unsigned int), "0123456789");
}
