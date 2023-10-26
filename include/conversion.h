/*
** EPITECH PROJECT, 2023
** conversion specifiers
** File description:
** Header file for conversion specifiers in my_printf
*/

#include <stdarg.h>
#include "my_printf.h"

#ifndef CONVERSION_H
    #define CONVERSION_H
typedef struct conversion_map {
    char spec;
    int (*exec) (va_list *params);
} conversion_map;

const int CONVERSION_MAP_LENGTH = 13;

const conversion_map CONVERSION_MAP[] = {
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
    {'e', &handle_scientific_not_lower},
    {'E', &handle_scientific_not_upper}
};
#endif
