/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Header file for my_printf
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H
int handle_int(va_list *params);
int handle_char(va_list *params);
int handle_str(va_list *params);
int handle_percent(va_list *params);
int handle_float(va_list *params);
int handle_hex_upper(va_list *params);
int handle_hex_lower(va_list *params);
int handle_oct(va_list *params);
int handle_unsigned(va_list *params);
int handle_pointer(va_list *params);
int handle_scientific_not(va_list *params);
#endif
