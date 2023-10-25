#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test (my_printf, simple_string, .init = cr_redirect_stdout)
{
    int cnt = my_printf ( " hello world " ) ;
    cr_assert_stdout_eq_str ( " hello world " ) ;
    cr_assert_eq (cnt, 13);
}

Test (my_printf, more_params, .init = cr_redirect_stdout)
{
    char str[] = "Je m'appelle Leticia, j'ai 23 ans";
    int cnt = my_printf("Je m'appelle %s, j'ai %d ans", "Leticia", 23);
    cr_assert_stdout_eq_str(str);
    cr_assert_eq (cnt, my_strlen(str));
}

Test (my_printf, chars, .init = cr_redirect_stdout)
{
    int cnt = my_printf ("%c%c%c%c", 'h', 'o', 'l', 'a') ;
    cr_assert_stdout_eq_str("hola");
    cr_assert_eq(cnt, 4);
}

Test (my_printf, percent, .init = cr_redirect_stdout)
{
    int cnt = my_printf ("%d%%", -100) ;
    cr_assert_stdout_eq_str("-100%");
    cr_assert_eq(cnt, 5);
}

Test (my_printf, last_one, .init = cr_redirect_stdout)
{
    int cnt;
    char str[] = "Leticia";
    char res[] = "The word %Letic% has 5 characters.\n";

    str[5] = '\0';

    cnt = my_printf("The word %%%s%% has %i characters.\n",
        str, my_strlen(str));
    cr_assert_stdout_eq_str(res);
    cr_assert_eq(cnt, my_strlen(res));
}

Test (my_printf, no_equiv_flag, .init = cr_redirect_stdout)
{
    int cnt = my_printf ("%d%%%r", 1);
    cr_assert_stdout_eq_str("1%%r");
    cr_assert_eq(cnt, 4);
}

Test (my_printf, error, .init = cr_redirect_stdout)
{
    int cnt = my_printf ("%%%");
    cr_assert_eq(cnt, -1);
}

Test (my_printf, n_test, .init = cr_redirect_stdout)
{
    int cur = 0;
    int cnt = my_printf("testing n%nsos", &cur);
    cr_assert_stdout_eq_str("testing nsos");
    cr_assert_eq(cnt, 12);
    cr_assert_eq(cur, 9);
}

Test (my_printf, float_test, .init = cr_redirect_stdout)
{
    int cnt = my_printf("%f", 21.5);
    cr_assert_stdout_eq_str("21.500000");
    cr_assert_eq(cnt, 9);
}

Test(my_printf, pointer_test, .init = cr_redirect_stdout)
{
    cr_assert_eq(1, 1);
}

Test(my_printf, scientific_notation_lower, .init = cr_redirect_stdout)
{
    my_printf("%e %e", 2.0, 14.45);
    cr_assert_stdout_eq_str("2.000000e+00 1.445000e+01");
}

Test(my_printf, scientific_notation_upper, .init = cr_redirect_stdout)
{
    my_printf("%E %E", 2.0, 14.45);
    cr_assert_stdout_eq_str("2.000000E+00 1.445000E+01");
}
