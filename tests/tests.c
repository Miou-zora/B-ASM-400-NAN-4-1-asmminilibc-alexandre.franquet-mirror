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

    long *result = my_memset(result_to_modif, '\0', 24);
    long *expected = memset(expected_to_modif, '\0', 24);

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

    cr_assert_eq(result, result_to_modif);
    for (int i = 0; i < 3; i++)
        cr_assert_eq(result[i], result_to_modif[i]);
    cr_assert_eq(expected, expected_to_modif);
    for (int i = 0; i < 3; i++)
        cr_assert_eq(expected[i], expected_to_modif[i]);
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

Test(strcmp, casual, .init = loader)
{
    int result = my_strcmp("abc", "abc");
    int expected = strcmp("abc", "abc");

    cr_assert_eq(result, expected);
}

Test(strcmp, str_with_only_one_zero, .init = loader)
{
    int result = my_strcmp("\0", "\0");
    int expected = strcmp("\0", "\0");

    cr_assert_eq(result, expected);
}

Test(strcmp, str_first_greater, .init = loader)
{
    int result = my_strcmp("abc", "ab");
    int expected = strcmp("abc", "ab");

    cr_assert_eq(result, expected);
}

Test(strcmp, str_second_greater, .init = loader)
{
    int result = my_strcmp("ab", "abc");
    int expected = strcmp("ab", "abc");

    cr_assert_eq(result, expected);
}

Test(strcmp, str_first_greater_with_zero, .init = loader)
{
    int result = my_strcmp("abc", "abd");
    int expected = strcmp("abc", "abd");

    cr_assert_eq(result, expected);
}

Test(strcmp, str_second_greater_with_zero, .init = loader)
{
    int result = my_strcmp("abd", "abc");
    int expected = strcmp("abd", "abc");

    cr_assert_eq(result, expected);
}

Test(memmove, casual, .init = loader)
{
    char *result_to_modif = malloc(sizeof(char) * 3);
    char *expected_to_modif = malloc(sizeof(char) * 3);
    char *result = my_memmove(result_to_modif, "abc", 3);
    char *expected = memmove(expected_to_modif, "abc", 3);

    for (int i = 0; i < 3; i++)
        cr_assert_eq(result[i], expected[i]);
}

Test(memmove, str_with_only_one_zero, .init = loader)
{
    char *result_to_modif = malloc(sizeof(char) * 1);
    char *expected_to_modif = malloc(sizeof(char) * 1);
    char *result = my_memmove(result_to_modif, "\0", 1);
    char *expected = memmove(expected_to_modif, "\0", 1);

    for (int i = 0; i < 1; i++)
        cr_assert_eq(result[i], expected[i]);
}

Test(memmove, zero_modif, .init = loader)
{
    char *result_to_modif = malloc(sizeof(char) * 3);
    char *expected_to_modif = malloc(sizeof(char) * 3);
    char *result = my_memmove(result_to_modif, "abc", 0);
    char *expected = memmove(expected_to_modif, "abc", 0);

    cr_assert_eq(result, result_to_modif);
    for (int i = 0; i < 3; i++)
        cr_assert_eq(result[i], result_to_modif[i]);
    cr_assert_eq(expected, expected_to_modif);
    for (int i = 0; i < 3; i++)
        cr_assert_eq(expected[i], expected_to_modif[i]);
}

Test(memmove, with_long, .init = loader)
{
    long *result_to_modif = malloc(sizeof(long) * 3);
    result_to_modif[0] = 1;
    result_to_modif[1] = 2;
    result_to_modif[2] = 3;
    long *expected_to_modif = malloc(sizeof(long) * 3);
    expected_to_modif[0] = 1;
    expected_to_modif[1] = 2;
    expected_to_modif[2] = 3;

    long *result = my_memmove(result_to_modif, "abc", 2);
    long *expected = memmove(expected_to_modif, "abc", 2);

    for (int i = 0; i < 3; i++)
        cr_assert_eq(result[i], expected[i]);
}

Test(memmove, string_dest_overlap_src, .init = loader)
{
    char *result_to_modif = strdup("abcd");
    char *expected_to_modif = strdup("abcd");
    char *result = my_memmove(result_to_modif, result_to_modif + 1, 2);
    char *expected = memmove(expected_to_modif, expected_to_modif + 1, 2);

    for (int i = 0; i < 4; i++)
        cr_assert_eq(result[i], expected[i]);

}

Test(memmove, string_src_overlap_dest, .init = loader)
{
    char *result_to_modif = strdup("abcd");
    char *expected_to_modif = strdup("abcd");
    result_to_modif += 1;
    expected_to_modif += 1;
    char *result = my_memmove(result_to_modif, result_to_modif - 1, 2);
    char *expected = memmove(expected_to_modif, expected_to_modif - 1, 2);
    result_to_modif -= 1;
    expected_to_modif -= 1;

    for (int i = 0; i < 4; i++)
        cr_assert_eq(result[i], expected[i]);
}

Test(strncmp, casual, .init = loader)
{
    int result = my_strncmp("abc", "abc", 4);
    int expected = strncmp("abc", "abc", 4);

    cr_assert_eq(result, expected);
}

Test(strncmp, str_with_only_one_zero, .init = loader)
{
    int result = my_strncmp("\0", "\0", 1);
    int expected = strncmp("\0", "\0", 1);

    cr_assert_eq(result, expected);
}

Test(strncmp, str_first_greater, .init = loader)
{
    int result = my_strncmp("abc", "ab", 3);
    int expected = strncmp("abc", "ab", 3);

    cr_assert_eq(result, expected);
}

Test(strncmp, str_second_greater, .init = loader)
{
    int result = my_strncmp("ab", "abc", 3);
    int expected = strncmp("ab", "abc", 3);

    cr_assert_eq(result, expected);
}

Test(strncmp, str_first_greater_with_zero, .init = loader)
{
    int result = my_strncmp("abc", "abd", 4);
    int expected = strncmp("abc", "abd", 4);

    cr_assert_eq(result, expected);
}

Test(strncmp, str_second_greater_with_zero, .init = loader)
{
    int result = my_strncmp("abd", "abc", 4);
    int expected = strncmp("abd", "abc", 4);

    cr_assert_eq(result, expected);
}

Test(strncmp, str_more, .init = loader)
{
    int result = my_strncmp("abc", "abc", 5);
    int expected = strncmp("abc", "abc", 5);

    cr_assert_eq(result, expected);
}


Test(strncmp, little, .init = loader)
{
    int result = my_strncmp("ac", "ab", 1);
    int expected = strncmp("ac", "ab", 1);

    cr_assert_eq(result, expected);
}


Test(strncmp, zero, .init = loader)
{
    int result = my_strncmp("a", "b", 0);
    int expected = strncmp("a", "b", 0);

    cr_assert_eq(result, expected);
}

Test(strncmp, more_than_hundred_letter, .init = loader)
{
    int result = my_strncmp("bb", "ab", -1);
    int expected = strncmp("bb", "ab", -1);

    cr_assert_eq(result, expected);
}

Test(strcasecmp, casual, .init = loader)
{
    int result = my_strcasecmp("abe", "abc");
    int expected = strcasecmp("abe", "abc");

    cr_assert_eq(result, expected);
}

Test(strcasecmp, maj_no_diff, .init = loader)
{
    int result = my_strcasecmp("abC", "abc");
    int expected = strcasecmp("abC", "abc");

    cr_assert_eq(result, expected);
}

Test(strcasecmp, maj_diff, .init = loader)
{
    int result = my_strcasecmp("abC", "abd");
    int expected = strcasecmp("abC", "abd");

    cr_assert_eq(result, expected);
}


Test(strcasecmp, double_maj, .init = loader)
{
    int result = my_strcasecmp("abC", "abC");
    int expected = strcasecmp("abC", "abC");

    cr_assert_eq(result, expected);
}

Test(strcasecmp, right_maj, .init = loader)
{
    int result = my_strcasecmp("abe", "abC");
    int expected = strcasecmp("abe", "abC");

    cr_assert_eq(result, expected);
}

Test(strcasecmp, no_letter, .init = loader)
{
    int result = my_strcasecmp("ab]", "ab]");
    int expected = strcasecmp("ab]", "ab]");

    cr_assert_eq(result, expected);
}

Test(strcasecmp, no_character, .init = loader)
{
    int result = my_strcasecmp("\0", "\0");
    int expected = strcasecmp("\0", "\0");

    cr_assert_eq(result, expected);
}

Test(strcasecmp, more_character_left, .init = loader)
{
    int result = my_strcasecmp("a\0", "\0");
    int expected = strcasecmp("a\0", "\0");

    cr_assert_eq(result, expected);
}

Test(strcasecmp, more_character_right, .init = loader)
{
    int result = my_strcasecmp("\0", "a\0");
    int expected = strcasecmp("\0", "a\0");

    cr_assert_eq(result, expected);
}

Test(strcasecmp, special_char_maj, .init = loader)
{
    int result = my_strcasecmp("@\0", "E\0");
    int expected = strcasecmp("@\0", "E\0");

    cr_assert_eq(result, expected);
}

Test(strcasecmp, special_char_min, .init = loader)
{
    int result = my_strcasecmp("@\0", "e\0");
    int expected = strcasecmp("@\0", "e\0");

    cr_assert_eq(result, expected);
}

Test(strstr, casual, .init = loader)
{
    char *input = "abc";
    char *result = my_strstr(input, "bc");
    char *expected = strstr(input, "bc");

    cr_assert_eq(result, expected);
}

Test(strstr, no_str_in_str, .init = loader)
{
    char *input = "abc";
    char *result = my_strstr(input, "d");
    char *expected = strstr(input, "d");

    cr_assert_eq(result, expected);
}

Test(strstr, zero_value, .init = loader)
{
    char *input = "abc";
    char *result = my_strstr(input, "\0");
    char *expected = strstr(input, "\0");

    cr_assert_eq(result, expected);
}

Test(strstr, big_two_value, .init = loader)
{
    char *input = "abc";
    char *result = my_strstr(input, "azer");
    char *expected = strstr(input, "azer");

    cr_assert_eq(result, expected);
}

Test(strstr, empty_first_parameter, .init = loader)
{
    char *input = "";
    char *result = my_strstr(input, "bc");
    char *expected = strstr(input, "bc");

    cr_assert_eq(result, expected);
}

Test(strstr, all_empty, .init = loader)
{
    char *input = "";
    char *result = my_strstr(input, "");
    char *expected = strstr(input, "");

    cr_assert_eq(result, expected);
}

Test(strstr, empty_second_parameter, .init = loader)
{
    char *input = "abc";
    char *result = my_strstr(input, "");
    char *expected = strstr(input, "");

    cr_assert_eq(result, expected);
}

Test(strstr, empty_both_parameter, .init = loader)
{
    char *input = "";
    char *result = my_strstr(input, "");
    char *expected = strstr(input, "");

    cr_assert_eq(result, expected);
}

Test(strstr, big_first_parameter, .init = loader)
{
    char *input = "azertyuiopqsdfghjklmwxcvbn";
    char *result = my_strstr(input, "qsdfghjklmwxcvbn");
    char *expected = strstr(input, "qsdfghjklmwxcvbn");

    cr_assert_eq(result, expected);
}

Test(strstr, big_second_parameter, .init = loader)
{
    char *input = "qsdfghjklmwxcvbn";
    char *result = my_strstr(input, "azertyuiopqsdfghjklmwxcvbn");
    char *expected = strstr(input, "azertyuiopqsdfghjklmwxcvbn");

    cr_assert_eq(result, expected);
}

Test(strstr, big_both_parameter, .init = loader)
{
    char *input = "This is a simple string";
    char *result = my_strstr(input, "simple");
    char *expected = strstr(input, "simple");

    cr_assert_eq(result, expected);
}

Test(strpbrk, casual, .init = loader)
{
    char str[] = "tonsoir a tous et a toute\n";
    char not_wanted[] = "te";
    char *result = my_strpbrk(str, not_wanted);
    char *expected = strpbrk(str, not_wanted);

    cr_assert_eq(result, expected);
}

Test(strpbrk, not_in_str, .init = loader)
{
    char str[] = "tonsoir a tous et a toute\n";
    char not_wanted[] = "z";
    char *result = my_strpbrk(str, not_wanted);
    char *expected = strpbrk(str, not_wanted);

    cr_assert_eq(result, expected);
}

Test(strpbrk, empty_str, .init = loader)
{
    char str[] = "";
    char not_wanted[] = "te";
    char *result = my_strpbrk(str, not_wanted);
    char *expected = strpbrk(str, not_wanted);

    cr_assert_eq(result, expected);
}

Test(strpbrk, empty_not_wanted, .init = loader)
{
    char str[] = "tonsoir a tous et a toute\n";
    char not_wanted[] = "";
    char *result = my_strpbrk(str, not_wanted);
    char *expected = strpbrk(str, not_wanted);

    cr_assert_eq(result, expected);
}

Test(strpbrk, empty_both, .init = loader)
{
    char str[] = "";
    char not_wanted[] = "";
    char *result = my_strpbrk(str, not_wanted);
    char *expected = strpbrk(str, not_wanted);

    cr_assert_eq(result, expected);
}

Test(strcspn, casual, .init = loader)
{
    char str[] = "tonsoir a tous et a toute\n";
    char not_wanted[] = "te";
    size_t result = my_strcspn(str, not_wanted);
    size_t expected = strcspn(str, not_wanted);

    cr_assert_eq(result, expected);
}

Test(strcspn, not_in_str, .init = loader)
{
    char str[] = "tonsoir a tous et a toute\n";
    char not_wanted[] = "z";
    size_t result = my_strcspn(str, not_wanted);
    size_t expected = strcspn(str, not_wanted);

    cr_assert_eq(result, expected);
}

Test(strcspn, empty_str, .init = loader)
{
    char str[] = "";
    char not_wanted[] = "te";
    size_t result = my_strcspn(str, not_wanted);
    size_t expected = strcspn(str, not_wanted);

    cr_assert_eq(result, expected);
}

Test(strcspn, empty_not_wanted, .init = loader)
{
    char str[] = "tonsoir a tous et a toute\n";
    char not_wanted[] = "";
    size_t result = my_strcspn(str, not_wanted);
    size_t expected = strcspn(str, not_wanted);

    cr_assert_eq(result, expected);
}

Test(strcspn, empty_both, .init = loader)
{
    char str[] = "";
    char not_wanted[] = "";
    size_t result = my_strcspn(str, not_wanted);
    size_t expected = strcspn(str, not_wanted);

    cr_assert_eq(result, expected);
}

Test(test_strcmp, normal_strncmp, .init = loader)
{
    char *str = "allo";
    char *str2 = "testou";

    cr_assert_eq(my_strncmp(str, str2, 3),strncmp(str, str2, 3));
    cr_assert_str_eq(str, "allo");
    cr_assert_str_eq(str2, "testou");
}

Test(test_strcmp, equal_strncmp, .init = loader)
{
    char *str = "testou";
    char *str2 = "testou";

    cr_assert_eq(my_strncmp(str, str2, 1),strncmp(str, str2, 1));
    cr_assert_str_eq(str, "testou");
    cr_assert_str_eq(str2, "testou");
}

Test(test_strcmp, no_string_strncmp, .init = loader)
{
    char *str = "";
    char *str2 = "";

    cr_assert_eq(my_strncmp(str, str2, 3),strncmp(str, str2, 3));
    cr_assert_str_eq(str, "");
    cr_assert_str_eq(str2, "");
}

Test(test_strcmp, one_empty_string_strncmp, .init = loader)
{
    char *str = "testT";
    char *str2 = "testt";

    cr_assert_eq(my_strncmp(str, str2, 0),strncmp(str, str2, 0));
    cr_assert_str_eq(str, "testT");
    cr_assert_str_eq(str2, "testt");
}

Test(test_strcmp, zero_string_strncmp, .init = loader)
{
    char *str = "a";
    char *str2 = "b";

    cr_assert_eq(my_strncmp(str, str2, 0),strncmp(str, str2, 0));
    cr_assert_str_eq(str, "a");
    cr_assert_str_eq(str2, "b");
}

Test(my_strncmp, falsee, .init=loader)
{
    cr_assert_eq(my_strncmp("azc", "abc", 3), strncmp("azc", "abc", 3));
}

Test(my_strncmp, basic, .init=loader)
{
    cr_assert_eq(my_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
}

Test(my_strncmp, basic2, .init=loader)
{
    cr_assert_eq(my_strncmp("abc", "abz", 2), strncmp("abc", "abz", 2));
}

Test(my_strncmp, basic3, .init=loader)
{
    cr_assert_eq(my_strncmp("abz", "abc", 2), strncmp("abz", "abc", 2));
}

Test(my_strncmp, long_str1, .init=loader)
{
    cr_assert_eq(my_strncmp("azert", "abz", 3), strncmp("azert", "abz", 3));
}

Test(my_strncmp, long_str2, .init=loader)
{
    cr_assert_eq(my_strncmp("azert", "abz", 1), strncmp("azert", "abz", 1));
}

Test(my_strncmp, long_str3, .init=loader)
{
    cr_assert_eq(my_strncmp("azert", "abz", 5), strncmp("azert", "abz", 5));
}

Test(my_strncmp, long_str4, .init=loader)
{
    cr_assert_eq(my_strncmp("Lylian", "L", 1), strncmp("Lylian", "L", 1));
}

Test(my_strncmp, long_str5, .init=loader)
{
    cr_assert_eq(my_strncmp("\0", "\0", 2), strncmp("\0", "\0", 2));
}

Test(my_strncmp, long_str6, .init=loader)
{
    cr_assert_eq(my_strncmp("\0", "\0", 1), strncmp("\0", "\0", 1));
}

Test(my_strncmp, long_str7, .init=loader)
{
    cr_assert_eq(my_strncmp("\0", "\0", 0), strncmp("\0", "\0", 0));
}

Test(my_strncmp, long_str8, .init=loader)
{
    cr_assert_eq(my_strncmp("hello", "hello World", 12), strncmp("hello", "hello World", 12));
}

Test(my_strncmp, long_str9, .init=loader)
{
    cr_assert_eq(my_strncmp("hello", "hello World", 10), strncmp("hello", "hello World", 10));
}

Test(my_strncmp, long_type, .init=loader)
{
    char *str = calloc(100, sizeof(char));
    char *str2 = calloc(100, sizeof(char));

    str[0] = -1;
    str2[0] = -1;

    str[1] = -2;
    str2[1] = -2;

    cr_assert_eq(my_strncmp(str, str2, -1), strncmp(str, str2, -1));
}

Test(my_strncmp, after_null, .init=loader)
{
    char *str = calloc(100, sizeof(char));
    char *str2 = calloc(100, sizeof(char));

    str[0] = 'a';
    str[1] ='b';
    str[2] = 0;
    str[3] = 1;

    str2[0] = 'a';
    str2[1] = 'b';
    str2[2] = 0;
    str2[3] = 2;

    cr_assert_eq(my_strncmp(str, str2, 5), strncmp(str, str2, 5));
}

