/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-alexandre.franquet-mirror
** File description:
** test
*/

#include <dlfcn.h>
#include "minilib.h"
#include <unistd.h>
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