#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "helpers.h"

Test (handle_str, precision, .init = cr_redirect_stdout)
{
    char *str = "Shake it off";
    int cnt = my_printf("%.7s", str);

    cr_assert_stdout_eq_str("Shake i");
    cr_assert_eq(cnt, 7);
}

Test (handle_str, flags, .init = cr_redirect_stdout)
{
    char *str = "Pasteis";
    int cnt = 0;

    cnt += my_printf("%#s\n", str);
    cnt += my_printf("%#10.5s\n", str);
    cnt += my_printf("% 010s\n", str);
    cnt += my_printf("%+ -10s\n", str);
    cnt += my_printf("%+ -010s\n", str);
    cnt += my_printf("%+ 0-10s\n", str);

    cr_assert_stdout_eq_str("Pasteis\n     Paste\n   Pasteis\nPasteis   \nPasteis   \nPasteis   \n");
    cr_assert_eq(cnt, 63);
}