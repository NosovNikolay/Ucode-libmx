#include "libmx.h"
char *mx_strndup(const char *s1, size_t n) {
    char *duplicate = NULL;

    if ((int)n < mx_strlen(s1)) {
        n = mx_strlen(s1);
    }

    duplicate = mx_strnew(n);
    mx_strncpy(duplicate, s1, n);

    return duplicate;
}
