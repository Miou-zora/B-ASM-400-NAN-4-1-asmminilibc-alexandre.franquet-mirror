/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-alexandre.franquet-mirror
** File description:
** test
*/

#include <dlfcn.h>
#include "minilib.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <criterion/criterion.h>

void loader(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        my_strcasecmp = dlsym(handle, "strcasecmp");
        my_memmove = dlsym(handle, "memmove");
        my_strncmp = dlsym(handle, "strncmp");
        my_strpbrk = dlsym(handle, "strpbrk");
        my_strcspn = dlsym(handle, "strcspn");
        my_strlen = dlsym(handle, "strlen");
        my_strchr = dlsym(handle, "strchr");
        my_strrchr = dlsym(handle, "strrchr");
        my_memset = dlsym(handle, "memset");
        my_memcpy = dlsym(handle, "memcpy");
        my_strcmp = dlsym(handle, "strcmp");
        my_strstr = dlsym(handle, "strstr");
    }
}

Test(strlen, casual, .init = loader)
{
    int result = my_strlen("abc");
    int expected = my_strlen("abc");

    cr_assert_eq(result, expected);
}

Test(strlen, str_with_only_one_zero, .init = loader)
{
    int result = my_strlen("\0");
    int expected = strlen("\0");

    cr_assert_eq(result, expected);
}

Test(strchr, casual, .init = loader)
{
    char *result = my_strchr("abc", 'a');
    char *expected = strchr("abc", 'a');

    cr_assert_eq(result, expected);
}

Test(strchr, str_with_only_one_zero, .init = loader)
{
    char *result = my_strchr("\0", '\0');
    char *expected = strchr("\0", '\0');

    cr_assert_eq(result, expected);
}

Test(strchr, str_without_char, .init = loader)
{
    char *result = my_strchr("abc", 'd');
    char *expected = strchr("abc", 'd');

    cr_assert_eq(result, expected);
}

Test(strchr, str_without_two_char, .init = loader)
{
    char *result = my_strchr("abcbd", 'b');
    char *expected = strchr("abcbd", 'b');

    cr_assert_eq(result, expected);
}

Test(strrchr, casual, .init = loader)
{
    char *result = my_strrchr("abc", 'a');
    char *expected = strrchr("abc", 'a');

    cr_assert_eq(result, expected);
}

Test(strrchr, str_with_only_one_zero, .init = loader)
{
    char *result = my_strrchr("\0", '\0');
    char *expected = strrchr("\0", '\0');

    cr_assert_eq(result, expected);
}

Test(strrchr, str_without_char, .init = loader)
{
    char *result = my_strrchr("abc", 'd');
    char *expected = strrchr("abc", 'd');

    cr_assert_eq(result, expected);
}

Test(strrchr, str_without_two_char, .init = loader)
{
    char *result = my_strrchr("abcbd", 'b');
    char *expected = strrchr("abcbd", 'b');

    cr_assert_eq(result, expected);
}

Test(memset, casual, .init = loader)
{

    char *result_to_modif = strdup("abc");
    char *expected_to_modif = strdup("abc");
    char *result = my_memset(result_to_modif, 'a', 3);
    char *expected = memset(expected_to_modif, 'a', 3);

    for (int i = 0; i < 3; i++)
        cr_assert_eq(result[i], expected[i]);
}

Test(memset, str_with_only_one_zero, .init = loader)
{

    char *result_to_modif = strdup("abc");
    char *expected_to_modif = strdup("abc");
    char *result = my_memset(result_to_modif, '\0', 1);
    char *expected = memset(expected_to_modif, '\0', 1);

    for (int i = 0; i < 3; i++) {
        cr_assert_eq(result[i], expected[i]);
    }
}

Test(memset, zero_modif, .init = loader)
{
    char *result_to_modif = strdup("abc");
    char *expected_to_modif = strdup("abc");
    char *result = my_memset(result_to_modif, '\0', 0);
    char *expected = memset(expected_to_modif, '\0', 0);

    for (int i = 0; i < 3; i++)
        cr_assert_eq(result[i], expected[i]);
}

Test(memset, with_long, .init = loader)
{
    long *result_to_modif = malloc(sizeof(long) * 3);
    result_to_modif[0] = 1;
    result_to_modif[1] = 2;
    result_to_modif[2] = 3;
    long *expected_to_modif = malloc(sizeof(long) * 3);
    expected_to_modif[0] = 1;
    expected_to_modif[1] = 2;
    expected_to_modif[2] = 3;

    long *result = my_memset(result_to_modif, '\0', 2);
    long *expected = memset(expected_to_modif, '\0', 2);

    for (int i = 0; i < 3; i++)
        cr_assert_eq(result[i], expected[i]);
}

Test(memcpy, casual, .init = loader)
{
    char *result_to_modif = malloc(sizeof(char) * 3);
    char *expected_to_modif = malloc(sizeof(char) * 3);
    char *result = my_memcpy(result_to_modif, "abc", 3);
    char *expected = memcpy(expected_to_modif, "abc", 3);

    for (int i = 0; i < 3; i++)
        cr_assert_eq(result[i], expected[i]);
}

Test(memcpy, str_with_only_one_zero, .init = loader)
{
    char *result_to_modif = malloc(sizeof(char) * 1);
    char *expected_to_modif = malloc(sizeof(char) * 1);
    char *result = my_memcpy(result_to_modif, "\0", 1);
    char *expected = memcpy(expected_to_modif, "\0", 1);

    for (int i = 0; i < 1; i++)
        cr_assert_eq(result[i], expected[i]);
}

Test(memcpy, zero_modif, .init = loader)
{
    char *result_to_modif = malloc(sizeof(char) * 3);
    char *expected_to_modif = malloc(sizeof(char) * 3);
    char *result = my_memcpy(result_to_modif, "abc", 0);
    char *expected = memcpy(expected_to_modif, "abc", 0);

    for (int i = 0; i < 3; i++)
        cr_assert_eq(result[i], expected[i]);
}

Test(memcpy, with_long, .init = loader)
{
    long *result_to_modif = malloc(sizeof(long) * 3);
    result_to_modif[0] = 1;
    result_to_modif[1] = 2;
    result_to_modif[2] = 3;
    long *expected_to_modif = malloc(sizeof(long) * 3);
    expected_to_modif[0] = 1;
    expected_to_modif[1] = 2;
    expected_to_modif[2] = 3;

    long *result = my_memcpy(result_to_modif, "abc", 2);
    long *expected = memcpy(expected_to_modif, "abc", 2);

    for (int i = 0; i < 3; i++)
        cr_assert_eq(result[i], expected[i]);
}