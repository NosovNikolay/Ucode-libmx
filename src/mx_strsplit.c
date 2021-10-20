#include "libmx.h"

char **mx_strsplit(char const *s, char c) {
    if (s == NULL) return NULL;
    char **words = (char**)malloc((mx_count_words(s, c) + 1) * 8);
    int skip = 0;
    int char_count = 0;
    int word_idx = 0;
    while (*s == c) s++;
    while (*s) {
        if (*s++ == c) {
            if (!skip) {
                words[word_idx++] = mx_strncpy(mx_strnew(char_count), s - char_count - 1, char_count);
                skip = 1;
                char_count = 0;
            }
            continue;
        }
        skip = 0;
        char_count++;
        if (*s == '\0')
            words[word_idx++] = mx_strncpy(mx_strnew(char_count), s - char_count, char_count);
    }
    words[word_idx] = NULL;
    return words;
}
