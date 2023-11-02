/*
** EPITECH PROJECT, 2023
** HANDLE_BINARY
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

static int handle_width_bin(unsigned int n, int num_len, format_string *fs)
{
    char *right = my_strstr(fs->flags, "-");
    char *zero = my_strstr(fs->flags, "0");

    if (right == 0 && zero == 0) {
        put_chars(fs->width - num_len, ' ');
    }
    if (my_strstr(fs->flags, "#"))
        my_putstr("0b");
    if (right == 0 && zero != 0) {
        put_chars(fs->width - num_len, '0');
    }
    my_getint_base(n, "01");
    if (right != 0) {
        put_chars(fs->width - num_len, ' ');
    }
    return fs->width;
}

int handle_binary(va_list *args, format_string *fs)
{
    int cnt = 0;
    unsigned int n = va_arg(*args, unsigned int);

    if (n == 0) {
        my_putchar('0');
        return 1;
    }
    if (my_strstr(fs->flags, "#"))
        cnt += 2;
    cnt += my_getint_base_len(n, "01");
    if (cnt < fs->width) {
        return handle_width_bin(n, cnt, fs);
    } else {
        if (my_strstr(fs->flags, "#"))
            my_putstr("0b");
        my_getint_base(n, "01");
        return cnt;
    }
}
