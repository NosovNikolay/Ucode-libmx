#include "libmx.h"

void *mx_realloc(void *ptr, size_t new_size) {
    size_t cur_size = 0;
    void *tmp = NULL;

    if (!ptr){
        return malloc(new_size);
    }

    cur_size = malloc_size(ptr);
    
    if (new_size <= cur_size) {
        return ptr;
    }

    tmp = malloc(new_size);
    mx_memcpy(tmp, ptr, cur_size);
    free(ptr);
    
    return tmp;
}
