/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** My printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "include/my.h"
#include "include/my_printf.h"
#include "include/format.h"
#include "include/flags.h"
#include "include/len_mod.h"
#include "include/conversion.h"

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

static char *get_flag(const char **format)
{
    return "";
}

static int get_width(const char **format)
{
    return 0;
}

static int get_precision(const char **format)
{
    return 0;
}

static char *get_len_mod(const char **format)
{
    return "";
}

static int convert(const char *format, va_list *args,
    int cnt, format_string *fs)
{
    for (int i = 0; i < CONVERSION_MAP_LENGTH; i++) {
        if (CONVERSION_MAP[i].spec == *format) {
            return CONVERSION_MAP[i].exec(args, fs);
        }
    }
    return handle_others(format, args, cnt);
}

static int get_format(const char **format, va_list *args, int cnt)
{
    format_string *fs;

    fs = malloc(sizeof(format_string));
    fs->flags = get_flag(format);
    fs->width = get_width(format);
    fs->precision = get_precision(format);
    fs->len_mod = get_len_mod(format);
    return convert(*format, args, cnt, fs);
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
            res = get_format(&format, &args, cnt);
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
