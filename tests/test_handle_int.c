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

Test (handle_int, handle_len_mod, .init = cr_redirect_stdout)
{
    int cnt = 0;
    unsigned char n1 = 250;
    short int n2 = -30000;
    int n3 = 2000000000;
    long int n4 = 2147483646;
    long long int n5 = 9223372036854775800;

    cnt += my_printf("%hhd\n", n1);
    cnt += my_printf("%hd\n", n2);
    cnt += my_printf("%d\n", n3);
    cnt += my_printf("%ld\n", n4);
    cnt += my_printf("%lld\n", n5);

    cr_assert_stdout_eq_str(
	"-6\n-30000\n2000000000\n2147483646\n9223372036854775800\n");
    cr_assert_eq (cnt, 52);
}
