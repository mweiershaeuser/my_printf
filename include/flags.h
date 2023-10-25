/*
** EPITECH PROJECT, 2023
** flags
** File description:
** Header file for flags in my_printf
*/

#include <stdarg.h>
#include "my_printf.h"

#ifndef FLAGS_H
    #define FLAGS_H
typedef struct flag_map {
    char flag;
    int (*exec) (va_list *params);
} flag_map;

const int FLAG_MAP_LENGTH = 12;

const flag_map FLAG_MAP[] = {
    {'d', &handle_int},
    {'i', &handle_int},
    {'c', &handle_char},
    {'s', &handle_str},
    {'%', &handle_percent},
    {'f', &handle_float},
    {'X', &handle_hex_upper},
    {'x', &handle_hex_lower},
    {'o', &handle_oct},
    {'u', &handle_unsigned},
    {'p', &handle_pointer},
    {'e', &handle_scientific_not}
};
#endif
