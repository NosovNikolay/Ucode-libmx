#include "libmx.h"

void mx_strdel(char **str) {
    if (!*str) {
        return;
    }
    free(*str);
    *str = NULL;
}
