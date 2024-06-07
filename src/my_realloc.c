/*
** EPITECH PROJECT, 2023
** Parser.c
** File description:
** sucreeeh et parsing
*/
#include "path.h"
#include <string.h>

void my_memcopy(void *dest, const void *src, size_t size)
{
    char *dest_ptr = (char *)dest;
    const char *src_ptr = (const char *)src;

    for (size_t i = 0; i < size; i++) {
        dest_ptr[i] = src_ptr[i];
    }
}

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc(size);
    size_t min_size = size;

    if (size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
        return malloc(size);
    if (new_ptr != NULL) {
        my_memcopy(new_ptr, ptr, min_size);
    }
    if (ptr != NULL)
        free(ptr);
    return new_ptr;
}
