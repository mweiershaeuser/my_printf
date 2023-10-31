#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "helpers.h"

Test(my_printf, g_conversion_e, .init = cr_redirect_stdout)
{
    int count = my_printf("%g %.3g", 0.0000234, 1234.22);
    cr_assert_stdout_eq_str("2.340000e-05 1.234220e+03");
    cr_assert_eq(count, 25);
}

Test(my_printf, G_conversion_E, .init = cr_redirect_stdout)
{
    int count = my_printf("%G %.3G", 0.0000234, 1234.22);
    cr_assert_stdout_eq_str("2.340000E-05 1.234220E+03");
    cr_assert_eq(count, 25);
}