/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Header file for my_printf
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H
int handle_int(va_list* params);
int handle_char(va_list* params);
int handle_str(va_list* params);
int handle_percent(va_list* params);
#endif
