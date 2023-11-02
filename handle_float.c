/*
** EPITECH PROJECT, 2023
** HANDLE FLOAT
** File description:
** Handle Float for My printf
*/
#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

static char get_signal(long double n, format_string *fs)
{
    char *plus = my_strstr(fs->flags, "+");
    char *space = my_strstr(fs->flags, " ");

    if (n < 0)
        return '-';
    if (plus)
        return '+';
    if (space)
        return ' ';
    return 0;
}

static void put_chars(int n, char c)
{
    for (int i = 0; i < n; i++) {
        my_putchar(c);
    }
}

static int put_float(long double n, int precision, char signal)
{
    if (precision < 0)
        return my_putfloat(n, 6);
    if (precision == 0)
        return my_put_nbr(n);
    return my_putfloat(n, precision);
}

static int handle_width(long double n, int num_len,
    format_string *fs, char signal)
{
    char *right = my_strstr(fs->flags, "-");
    char *zero = my_strstr(fs->flags, "0");

    if (right == 0 && zero == 0)
        put_chars(fs->width - num_len, ' ');
    if (signal != 0)
        my_putchar(signal);
    if (right == 0 && zero != 0)
        put_chars(fs->width - num_len, '0');
    put_float(n, fs->precision, signal);
    if (right != 0)
        put_chars(fs->width - num_len, ' ');
    return fs->width;
}

static long double get_n(va_list *args, format_string *fs)
{
    long double res = 0;

    if (my_strcmp(fs->len_mod, "L") == 0)
        return va_arg(*args, long double);
    return va_arg(*args, double);
}

int handle_float_inner(long double n, format_string *fs)
{
    int num_len;
    int precision = fs->precision;
    char signal = get_signal(n, fs);

    if (n < 0)
        n = n * (-1);
    num_len = my_getfloat_len(n, precision);
    if (signal != 0)
        num_len += 1;
    if (num_len >= fs->width) {
        if (signal != 0)
            my_putchar(signal);
        put_float(n, precision, signal);
        return num_len;
    }
    return handle_width(n, num_len, fs, signal);
}

int handle_float(va_list *args, format_string *fs)
{
    long double n = get_n(args, fs);

    return handle_float_inner(n, fs);
}
