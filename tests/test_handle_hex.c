#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test (handle_hex, hex_x_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 123;
    int cnt = my_printf("%x %x", test1, test2);
    cr_assert_stdout_eq_str("2a 7b");
    cr_assert_eq(cnt, 5);
}

Test (handle_hex, hex_X_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 123;
    int cnt = my_printf("%X %X", test1, test2);
    cr_assert_stdout_eq_str("2A 7B");
    cr_assert_eq(cnt, 5);
}

Test (handle_hex, hex_x_hash_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 0;
    int cnt = my_printf("%#x %#x", test1, test2);
    cr_assert_stdout_eq_str("0x2a 0");
    cr_assert_eq(cnt, 6);
}

Test (handle_hex, hex_X_hash_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 0;
    int cnt = my_printf("%#X %#X", test1, test2);
    cr_assert_stdout_eq_str("0X2A 0");
    cr_assert_eq(cnt, 6);
}

Test (handle_hex, hex_x_flags_test, .init = cr_redirect_stdout)
{
    unsigned int n = 42;
    int cnt = 0;
    cnt += my_printf("% x\n", n);
    cnt += my_printf("% 10x\n", n);
    cnt += my_printf("% 010x\n", n);
    cnt += my_printf("%+ -10x\n", n);
    cnt += my_printf("%+ -010x\n", n);
    cnt += my_printf("%+ 0-10x\n", n);
    cr_assert_stdout_eq_str("2a\n        2a\n000000002a\n2a        \n2a        \n2a        \n");
    cr_assert_eq(cnt, 58);
}

Test (handle_hex, hex_X_flags_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 123;
    int cnt = my_printf("%X %X", test1, test2);
    cr_assert_stdout_eq_str("2A 7B");
    cr_assert_eq(cnt, 5);
}

Test (handle_hex, pointer_test, .init = cr_redirect_stdout)
{
    unsigned long long int fake_pointer = 140728941421448;
    int cnt = my_printf("%p", fake_pointer);
    cr_assert_stdout_eq_str("0x7ffe02902388");
    cr_assert_eq(cnt, 14);
}

Test (handle_hex, handle_len_mod, .init = cr_redirect_stdout)
{
    int cnt = 0;
    unsigned char n1 = 250;
    unsigned short int n2 = -30000;
    unsigned int n3 = 2000000000;
    unsigned long int n4 = 2147483646;
    unsigned long long int n5 = 9223372036854775800;

    cnt += my_printf("%16hhx\n", n1);
    cnt += my_printf("%16hx\n", n2);
    cnt += my_printf("%16x\n", n3);
    cnt += my_printf("%16lx\n", n4);
    cnt += my_printf("%16llx\n", n5);

    cr_assert_stdout_eq_str(
	    "              fa\n            8ad0\n        77359400\n        7ffffffe\n7ffffffffffffff8\n"
        );
    cr_assert_eq (cnt, 85);
}
