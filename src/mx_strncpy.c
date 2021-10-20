#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    if ((dst == 0) && (src == 0))
        return NULL;

    char *begin = dst;
    while (*src && len--) {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return begin;
}
