#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *str1 = (unsigned char *)s1;
    unsigned char *str2 = (unsigned char *)s2;
    int compare_status = 0;

    if (s1 == s2) {
        return compare_status;
    }
    while (n > 0) {
        if (*str1!= *str2) { 
            compare_status = (*str1> *str2) ? 1 : -1;
            break;
        }
        n--;
        str1++;
        str2++;
    }
    return compare_status;
}

