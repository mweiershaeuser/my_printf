/*
** EPITECH PROJECT, 2023
** HANDLE_INT
** File description:
** Int handler for My printf
*/
#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

static void put_chars(int n, char c)
{
    for (int i = 0; i < n; i++) {
        my_putchar(c);
    }
}

static int handle_width(int n, int num_len, format_string *fs)
{
    char *right = my_strstr(fs->flags, "-");
    char *zero = my_strstr(fs->flags, "0");
    char to_print = zero == 0 ? ' ' : '0';

    if (right == 0) {
        put_chars(fs->width - num_len, to_print);
    }
    my_put_nbr(n);
    if (right != 0) {
        put_chars(fs->width - num_len, ' ');
    }
    return fs->width;
}

int handle_int(va_list *args, format_string *fs)
{
    int n = va_arg(*args, int);
    int num_len = my_get_nbr_len(n);

    if (num_len >= fs->width) {
        my_put_nbr(n);
        return num_len;
    } else
        return handle_width(n, num_len, fs);
}
