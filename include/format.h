/*
** EPITECH PROJECT, 2023
** format string
** File description:
** Header for the format string of my_printf
*/

#ifndef FORMAT_H
    #define FORMAT_H
typedef struct format_string {
    int dollar;
    char *flags;
    int width;
    int precision;
    char *len_mod;
} format_string;
#endif
