#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "helpers.h"

Test (handle_float, float_test, .init = cr_redirect_stdout)
{
    int cnt = my_printf("%f", 21.5);
    cr_assert_stdout_eq_str("21.500000");
    cr_assert_eq(cnt, 9);
}

Test (handle_float, precision_zero, .init = cr_redirect_stdout)
{
    double n = 21.5;
    int cnt = my_printf("%.0f %2.f", n, n);
    cr_assert_stdout_eq_str("21 21");
    cr_assert_eq(cnt, 5);
}

Test (handle_float, precision_test, .init = cr_redirect_stdout)
{
    int cnt = my_printf("%5.4f", 21.5);
    cr_assert_stdout_eq_str("21.5000");
    cr_assert_eq(cnt, 7);
}

