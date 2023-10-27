#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "helpers.h"

Test (handle_int, basic_test, .init = cr_redirect_stdout)
{
    int n = 42;
    int cnt = 0;

    cnt += my_printf("%d", n);

    cr_assert_stdout_eq_str("42");
    cr_assert_eq (cnt, 2);
}

Test (handle_int, handle_zero_minus, .init = cr_redirect_stdout)
{
    int n = 42;
    int cnt = 0;

    cnt += my_printf("%10d", n);
    cnt += my_printf("%010d", n);
    cnt += my_printf("%-10d", n);
    cnt += my_printf("%-010d", n);
    cnt += my_printf("%0-10d", n);

    cr_assert_stdout_eq_str(
        "        42000000004242        42        42        ");
    cr_assert_eq (cnt, 50);
}

Test (handle_int, handle_plus_space, .init = cr_redirect_stdout)
{
    int n = 42;
    int cnt = 0;

    cnt += my_printf("%     d", n);
    cnt += my_printf("% 10d", n);
    cnt += my_printf("% 010d", n);
    cnt += my_printf("%+ -10d", n);
    cnt += my_printf("%+ -010d", n);
    cnt += my_printf("%+010d", n);
    
    cr_assert_stdout_eq_str(
        " 42        42 000000042+42       +42       +000000042");
    cr_assert_eq (cnt, 53);
}

Test (handle_int, handle_plus_space_neg, .init = cr_redirect_stdout)
{
    int n = -42;
    int cnt = 0;

    cnt += my_printf("%     d", n);
    cnt += my_printf("% 10d", n);
    cnt += my_printf("% 010d", n);
    cnt += my_printf("%+ -10d", n);
    cnt += my_printf("%+ -010d", n);
    cnt += my_printf("%+010d", n);

    cr_assert_stdout_eq_str(
        "-42       -42-000000042-42       -42       -000000042");
    cr_assert_eq (cnt, 53);
}  
