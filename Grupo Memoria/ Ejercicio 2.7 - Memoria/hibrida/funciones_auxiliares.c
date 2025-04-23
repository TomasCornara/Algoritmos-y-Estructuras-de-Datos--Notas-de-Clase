#include "funciones_auxiliares.h"

void *mMemcpy(void *a, const void *b, size_t num)
{
    char *dest = (char *)a;
    const char *src = (const char *)b;

    while (num--)
        *dest++ = *src++;

    return a;
}
