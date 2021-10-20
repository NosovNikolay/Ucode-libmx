#include "libmx.h"

static int new_len(char *str_trim) {
    
    int len = 0;
    
    if(!str_trim)
        return 0;

    for (int i = 0; i < mx_strlen(str_trim); i++) {
        if (!mx_isspace(str_trim[i]))
            len++;
        else if (mx_isspace(str_trim[i])
                && !mx_isspace(str_trim[i + 1]))
            len++;
    }
    return len;
}

char *mx_del_extra_spaces(const char *str) {
    
    int j = 0;

    char *buff = mx_strtrim(str);

    char *result = mx_strnew(new_len(buff));
    
    if(buff == NULL || result == NULL)
        return NULL;

    for (int i = 0; i < mx_strlen(buff); i++) {
        if (!mx_isspace(buff[i])) {
            result[j] = buff[i];
            j++;
        }   
        else if (mx_isspace(buff[i]) 
                && !mx_isspace(buff[i + 1])) {
            result[j] = ' ';
            j++;
        } 
    }
    mx_strdel(&buff);
    return result;
}


