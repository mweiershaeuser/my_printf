#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test (bin_test, bin_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 123;
    int cnt = my_printf("%b %b", test1, test2);
    cr_assert_stdout_eq_str("101010 1111011");
    cr_assert_eq(cnt, 14);
}

Test (bin_test, bin_zero, .init = cr_redirect_stdout)
{
    unsigned int test1 = 0;
    int cnt = my_printf("%b", test1);

    cr_assert_stdout_eq_str("0");
    cr_assert_eq(cnt, 1);
}
