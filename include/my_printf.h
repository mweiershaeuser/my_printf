/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Header file for my_printf
*/

#include <stdarg.h>
#include "format.h"

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H
int handle_int(va_list *params, format_string *fs);
int handle_char(va_list *params, format_string *fs);
int handle_str(va_list *params, format_string *fs);
int handle_percent(va_list *params, format_string *fs);
int handle_float_inner(long double n, format_string *fs);
int handle_float(va_list *params, format_string *fs);
int handle_hex_upper(va_list *params, format_string *fs);
int handle_hex_lower(va_list *params, format_string *fs);
int handle_oct(va_list *params, format_string *fs);
int handle_unsigned(va_list *params, format_string *fs);
int handle_pointer(va_list *params, format_string *fs);
int get_exp(double nb);
int handle_scientific_not(double nb, format_string *fs, char e);
int handle_scientific_not_lower(va_list *params, format_string *fs);
int handle_scientific_not_upper(va_list *params, format_string *fs);
int handle_g_lower(va_list *params, format_string *fs);
int handle_g_upper(va_list *params, format_string *fs);
int handle_binary(va_list *params, format_string *fs);
int handle_n_flag(va_list *args, int cnt);
#endif
