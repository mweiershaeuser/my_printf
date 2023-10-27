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

Test (handle_int, handle_int_flags, .init = cr_redirect_stdout)
{
    int n = 42;
    int cnt = 0;

    cnt += my_printf("%10d", n);
    cnt += my_printf("%010d", n);
    cnt += my_printf("%-10d", n);
    cnt += my_printf("%-010d", n);
    cnt += my_printf("%0-10d", n);

    //receive_output("handle_int_flags_test.txt");
    cr_assert_stdout_eq_str(
        "        42000000004242        42        42        ");
    cr_assert_eq (cnt, 50);
}
