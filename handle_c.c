/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** c conversion
*/

#include <stdarg.h>
#include <wchar.h>
#include "include/my.h"
#include "include/format.h"

void handle_width(wint_t c, format_string *fs)
{
    for (int i = 0; i < (fs->width - 1); i++) {
        my_putchar(' ');
    }
}

int handle_char(va_list *args, format_string *fs)
{
    char *right = my_strstr(fs->flags, "-");
    wint_t c = va_arg(*args, wint_t);

    if (right == 0 && fs->width > 0) {
        handle_width(c, fs);
    }
    my_putchar(c);
    if (right != 0 && fs->width > 0) {
        handle_width(c, fs);
    }
    if (fs->width > 0) {
        return fs->width;
    } else {
        return 1;
    }
}
