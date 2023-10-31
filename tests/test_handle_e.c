#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "helpers.h"

Test(my_printf, scientific_notation_lower, .init = cr_redirect_stdout)
{
    my_printf("%e %e %e %e %e", 2.0, 14.46, -3.7, 0.78, -0.007);
    //receive_output("scientific_notation_lower_test.txt");
    cr_assert_stdout_eq_str("2.000000e+00 1.446000e+01 -3.700000e+00 7.800000e-01 -7.000000e-03");
}

Test(my_printf, scientific_notation_upper, .init = cr_redirect_stdout)
{
    my_printf("%E %E %E %E %E", 2.0, 14.46, -3.7, 0.78, -0.007);
    //receive_output("scientific_notation_upper_test.txt");
    cr_assert_stdout_eq_str("2.000000E+00 1.446000E+01 -3.700000E+00 7.800000E-01 -7.000000E-03");
}