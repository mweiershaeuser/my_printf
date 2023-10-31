#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test (my_printf, oct_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 123;
    int cnt = my_printf("%o %o", test1, test2);
    cr_assert_stdout_eq_str("52 173");
    cr_assert_eq(cnt, 6);
}

Test (my_printf, oct_flags_test, .init = cr_redirect_stdout)
{
    unsigned int n = 42;
    int cnt = 0;

    cnt += my_printf("%#o\n", n);
    cnt += my_printf("%#10o\n", n);
    cnt += my_printf("% 010o\n", n);
    cnt += my_printf("%+ -10o\n", n);
    cnt += my_printf("%+ -010o\n", n);
    cnt += my_printf("%+ 0-10o\n", n);
    cr_assert_stdout_eq_str(
        "052\n       052\n0000000052\n52        \n52        \n52        \n");
    cr_assert_eq(cnt, 59);
}

Test (my_printf, unsigned_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 123;
    int cnt = my_printf("%u %u", test1, test2);

    cr_assert_stdout_eq_str("42 123");
    cr_assert_eq(cnt, 6);
}

Test (my_printf, unsigned_flags_test, .init = cr_redirect_stdout)
{
    unsigned int n = 42;
    int cnt = 0;

    cnt += my_printf("%#0u\n", n);
    cnt += my_printf("%#10u\n", n);
    cnt += my_printf("% 010u\n", n);
    cnt += my_printf("%+ -10u\n", n);
    cnt += my_printf("%+ -010u\n", n);
    cnt += my_printf("%+ 0-10u\n", n);
    cr_assert_stdout_eq_str(
        "42\n        42\n0000000042\n42        \n42        \n42        \n");
    cr_assert_eq(cnt, 58);
}

Test (my_printf, oct_uns_zero, .init = cr_redirect_stdout)
{
    unsigned int test1 = 0;
    int cnt = my_printf("%o %u", test1, test1);

    cr_assert_stdout_eq_str("0 0");
    cr_assert_eq(cnt, 3);
}