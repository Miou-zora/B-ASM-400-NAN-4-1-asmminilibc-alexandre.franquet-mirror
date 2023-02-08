/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-alexandre.franquet-mirror
** File description:
** minilib
*/

#ifndef MINILIB_H_
    #define MINILIB_H_

#include <stddef.h>
int (*my_strlen)(const char *str);
char *(*my_strchr)(const char *str, int c);
char *(*my_strrchr)(const char *str, int c);
void *(*my_memset)(void *s, int c, size_t n);
void *(*my_memcpy)(void *dest, const void *src, size_t n);
int (*my_strcmp)(const char *s1, const char *s2);
void *(*my_memmove)(void *dest, const void *src, size_t n);
int (*my_strncmp)(const char *s1, const char *s2, size_t n);
int (*my_strcasecmp)(const char *s1, const char *s2);
char *(*my_strstr)(const char *haystack, const char *needle);
char *(*my_strpbrk)(const char *s, const char *accept);
size_t (*my_strcspn)(const char *s, const char *reject);

#endif /* !MINILIB_H_ */
