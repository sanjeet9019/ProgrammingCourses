#include "string_util.h"
#include <string.h>

int is_empty(const char* str) {
    return str == NULL || str[0] == '\0';
}

int are_equal(const char* s1, const char* s2) {
    if (!s1 || !s2) return 0;
    return strcmp(s1, s2) == 0;
}