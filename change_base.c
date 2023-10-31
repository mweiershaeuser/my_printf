/*
** EPITECH PROJECT, 2023
** BASIC FLAGS
** File description:
** Basic flags for My printf
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

static int handle_width_oct(unsigned int n, int num_len, format_string *fs)
{
    char *right = my_strstr(fs->flags, "-");
    char *zero = my_strstr(fs->flags, "0");

    if (right == 0 && zero == 0) {
        put_chars(fs->width - num_len, ' ');
    }
    if (my_strstr(fs->flags, "#"))
        my_putstr("0");
    if (right == 0 && zero != 0) {
        put_chars(fs->width - num_len, '0');
    }
    my_getint_base(n, "01234567");
    if (right != 0) {
        put_chars(fs->width - num_len, ' ');
    }
    return fs->width;
}

static int handle_width_uns(unsigned int n, int num_len, format_string *fs)
{
    char *right = my_strstr(fs->flags, "-");
    char *zero = my_strstr(fs->flags, "0");

    if (right == 0) {
        put_chars(fs->width - num_len, zero != 0 ? '0' : ' ');
    }
    my_getint_base(n, "0123456789");
    if (right != 0) {
        put_chars(fs->width - num_len, ' ');
    }
    return fs->width;
}

int handle_oct(va_list *args, format_string *fs)
{
    int cnt = 0;
    unsigned int n = va_arg(*args, unsigned int);

    if (n == 0) {
        my_putchar('0');
        return 1;
    }
    if (my_strstr(fs->flags, "#"))
        cnt += 1;
    cnt += my_getint_base_len(n, "01234567");
    if (cnt < fs->width) {
        return handle_width_oct(n, cnt, fs);
    } else {
        if (my_strstr(fs->flags, "#"))
            my_putstr("0");
        my_getint_base(n, "01234567");
        return cnt;
    }
}

int handle_unsigned(va_list *args, format_string *fs)
{
    int cnt = 0;
    unsigned int n = va_arg(*args, unsigned int);

    if (n == 0) {
        my_putchar('0');
        return 1;
    }
    cnt += my_getint_base_len(n, "0123456789");
    if (cnt < fs->width) {
        return handle_width_uns(n, cnt, fs);
    } else {
        return my_getint_base(n, "0123456789");
    }
}
