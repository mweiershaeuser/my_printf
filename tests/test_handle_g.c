#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "helpers.h"

Test(my_printf, g_conversion_e, .init = cr_redirect_stdout)
{
    int count = my_printf("%g %.3g", 0.0000234, 1234.22);
    cr_assert_stdout_eq_str("2.34e-05 1.23e+03");
    cr_assert_eq(count, 17);
}

Test(my_printf, G_conversion_E, .init = cr_redirect_stdout)
{
    int count = my_printf("%G %.3G", 0.0000234, 1234.22);
    cr_assert_stdout_eq_str("2.34E-05 1.23E+03");
    cr_assert_eq(count, 17);
}

Test(my_printf, g_conversion_f, .init = cr_redirect_stdout)
{
    int count = my_printf("%g %.8g", 0.234, 1234.22);
    //receive_output("g_to_f_test.txt");
    cr_assert_stdout_eq_str("0.234 1234.22");
    cr_assert_eq(count, 13);
}