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

static int handle_n_flag(va_list *args, int cnt)
{
    int *cur = va_arg(*args, int *);
    
    *cur = cnt;
    return 0;
}

static int handle_others(const char *format, va_list *args, int cnt)
{
    switch (*format) {
    case 'n':
        return handle_n_flag(args, cnt);
    case '\0':
        return -1;
    default:
	my_putchar('%');
        my_putchar(*format);
	return 2;
    }
}

static int get_format(const char *format, va_list *args, int cnt)
{
    for (int i = 0; i < FLAG_MAP_LENGTH; i++) {
        if (FLAG_MAP[i].flag == *format) {
            return FLAG_MAP[i].exec(args);
        }
    }
    return handle_others(format, args, cnt);
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
            res = get_format(format, &args, cnt);
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
