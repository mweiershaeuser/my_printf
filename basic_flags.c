/*
** EPITECH PROJECT, 2023
** BASIC FLAGS
** File description:
** Basic flags for My printf
*/
#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

int handle_n_flag(va_list *args, int cnt)
{
    int *cur = va_arg(*args, int *);

    *cur = cnt;
    return 0;
}

static void put_chars(int n, char c)
{
    for (int i = 0; i < n; i++) {
        my_putchar(c);
    }
}

static int handle_width(char *str, int str_len,
    format_string *fs)
{
    char *right = my_strstr(fs->flags, "-");

    if (right == 0) {
        put_chars(fs->width - str_len, ' ');
    }
    my_putstr_precision(str, str_len);
    if (right != 0) {
        put_chars(fs->width - str_len, ' ');
    }
    return fs->width;
}

int handle_str(va_list *args, format_string *fs)
{
    char *str = va_arg(*args, char *);
    int len = my_strlen(str);

    if (fs->precision != -1 && fs->precision < len)
        len = fs->precision;
    if (len < fs->width)
        return handle_width(str, len, fs);
    return my_putstr_precision(str, fs->precision);
}

int handle_percent(va_list *args, format_string *fs)
{
    my_putchar('%');
    return 1;
}
