#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <wchar.h>
#include "../include/my.h"
#include "helpers.h"

Test(handle_c, basic_test, .init = cr_redirect_stdout)
{
    int cnt = my_printf("%c%c%c%c", 'h', 'o', 'l', 'a');
    cr_assert_stdout_eq_str("hola");
    cr_assert_eq(cnt, 4);
}

Test(handle_c, width, .init = cr_redirect_stdout)
{
    int cnt = my_printf("%5c", 'h');
    cr_assert_stdout_eq_str("    h");
    cr_assert_eq(cnt, 5);
}

Test(handle_c, width_right, .init = cr_redirect_stdout)
{
    int cnt = my_printf("%-5c", 'h');
    cr_assert_stdout_eq_str("h    ");
    cr_assert_eq(cnt, 5);
}

Test(handle_c, l_modifier, .init = cr_redirect_stdout)
{
    wint_t c = 'h';
    int cnt = my_printf("%lc", c);
    cr_assert_stdout_eq_str("h");
    cr_assert_eq(cnt, 1);
}
