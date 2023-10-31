/*
** EPITECH PROJECT, 2023
** HANDLE_INT
** File description:
** Int handler for My printf
*/
#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

static char get_signal(long long int n, format_string *fs)
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

static int handle_width(long long int n, int num_len,
    format_string *fs, int signal)
{
    char *right = my_strstr(fs->flags, "-");
    char *zero = my_strstr(fs->flags, "0");

    if (signal != 0)
        num_len += 1;
    if (right == 0 && zero == 0) {
        put_chars(fs->width - num_len, ' ');
    }
    if (signal != 0)
        my_putchar(signal);
    if (right == 0 && zero != 0) {
        put_chars(fs->width - num_len, '0');
    }
    my_put_ll(n);
    if (right != 0) {
        put_chars(fs->width - num_len, ' ');
    }
    return fs->width;
}

static long long int get_n(va_list *args, format_string *fs)
{
    long long int res = 0;

    if (my_strlen(fs->len_mod) == 0)
        return va_arg(*args, int);
    if (my_strcmp(fs->len_mod, "h") == 0)
        return (short) va_arg(*args, int);
    if (my_strcmp(fs->len_mod, "hh") == 0)
        return (char) va_arg(*args, int);
    if (my_strcmp(fs->len_mod, "l") == 0)
        return va_arg(*args, long int);
    if (my_strcmp(fs->len_mod, "ll") == 0)
        return va_arg(*args, long long int);
}

int handle_int(va_list *args, format_string *fs)
{
    long long int n = get_n(args, fs);
    int signal = get_signal(n, fs);
    int num_len;

    if (n < 0)
        n = n * (-1);
    num_len = my_get_nbr_len(n);
    if (num_len >= fs->width) {
        if (signal != 0) {
            my_putchar(signal);
            num_len += 1;
        }
        my_put_ll(n);
        return num_len;
    } else
        return handle_width(n, num_len, fs, signal);
}
