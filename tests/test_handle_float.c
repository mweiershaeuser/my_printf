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

Test (handle_float, flags_test, .init = cr_redirect_stdout)
{
    int cnt = 0;
    float n = 42.7;

    cnt += my_printf("% .3f\n", n);
    cnt += my_printf("% 10.2f\n", n);
    cnt += my_printf("% 010.2f\n", n);
    cnt += my_printf("%+ -10f\n", n);
    cnt += my_printf("%+ -010f\n", n);
    cnt += my_printf("%+ 0-10.2f\n", n);
    
    cr_assert_stdout_eq_str(" 42.700\n     42.70\n 000042.70\n+42.700000\n+42.700000\n+42.70    \n");
    cr_assert_eq(cnt, 63);
}
