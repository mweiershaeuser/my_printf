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
    int pos = 0;
    int i = 0;
    char *found = malloc(sizeof(char) * 6);

    while (i < FLAGS_LENGTH) {
        if (FLAGS[i] == **format) {
            found[pos] = **format;
            pos++;
            (*format)++;
            i = 0;
        } else
            i++;
    }
    found[pos] = '\0';
    return found;
}

static int get_width(const char **format)
{
    int pos = 0;
    int res = -1;
    char *str = malloc(sizeof(char) * 11);

    while (is_number(**format)) {
        str[pos] = **format;
        pos++;
        (*format)++;
    }
    if (my_strlen(str))
        res = my_getnbr(str);
    free(str);
    return res;
}

static int get_precision(const char **format)
{
    char *str = malloc(sizeof(char) * 11);
    int res = -1;
    int pos = 0;

    if (**format != '.') {
        return -1;
    }
    (*format)++;
    while (is_number(**format)) {
        str[pos] = **format;
        (*format)++;
        pos++;
    }
    str[pos] = '\0';
    res = my_getnbr(str);
    free(str);
    return res;
}

static char *get_len_mod(const char **format)
{
    int pos = 0;
    char *len_mod = malloc(sizeof(char) * 3);
    int len_mod_len = 0;

    for (int i = 0; i < LEN_MODS_LENGTH; i++) {
        len_mod_len = my_strlen(LEN_MODS[i]);
        if (!my_strncmp(*format, LEN_MODS[i], len_mod_len)) {
            my_strncpy(len_mod, *format, len_mod_len);
            pos = pos + len_mod_len;
            (*format) += len_mod_len;
            break;
        }
    }
    len_mod[pos] = '\0';
    return len_mod;
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
    int res = 0;

    fs = malloc(sizeof(format_string) + 1);
    fs->flags = get_flag(format);
    fs->width = get_width(format);
    fs->precision = get_precision(format);
    fs->len_mod = get_len_mod(format);
    res = convert(*format, args, cnt, fs);
    free(fs->flags);
    free(fs->len_mod);
    free(fs);
    return res;
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
