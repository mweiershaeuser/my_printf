/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** My printf
*/
#include <stdarg.h>
#include "include/my.h"
#include "include/my_printf.h"
#include "include/flags.h"

int handle_int(va_list *args)
{
    return my_put_nbr(va_arg(*args, int));
}

int handle_char(va_list *args)
{
    my_putchar(va_arg(*args, int));
    return 1;
}

int handle_str(va_list *args)
{
    return my_putstr(va_arg(*args, char *));
}

int handle_percent(va_list *args)
{
    my_putchar('%');
    return 1;
}


static int get_format(const char *format, va_list *args)
{
    for (int i = 0; i < FLAG_MAP_LENGTH; i++) {
        if (FLAG_MAP[i].flag == *format) {
            return FLAG_MAP[i].exec(args);
        }
    }
    
    switch (*format) {
    case '\0':
        return -1;
    default:
        my_putchar('%');
        my_putchar(*format);
        return 2;
    }
}

int my_printf(const char *format, ...)
{
    va_list args;
    int cnt = 0;
    int res = 0;

    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            res = get_format(format, &args);
            cnt += res;
        } else {
            my_putchar(*format);
            cnt++;
        }
        format++;
        if (res < 0)
            return res;
    }
    va_end(args);
    return cnt;
}
