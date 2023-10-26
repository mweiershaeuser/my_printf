/*
** EPITECH PROJECT, 2023
** length modifiers
** File description:
** Header file for length modifiers in my_printf
*/

#include <stdarg.h>
#include "my_printf.h"

#ifndef LEN_MOD_H
    #define LEN_MOD_H
const int LEN_MODS_LENGTH = 10;
const char *LEN_MODS[] = {
    "hh",
    "ll",
    "h",
    "l",
    "q",
    "L",
    "j",
    "z",
    "Z",
    "t"
};
#endif
