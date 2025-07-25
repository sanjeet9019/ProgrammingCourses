#include "memory_util.h"
#include <stdlib.h>
#include <string.h>

void* allocate_buffer(size_t size) {
    return malloc(size);
}

void clear_buffer(char* buf, size_t size) {
    if (buf) memset(buf, 0, size);
}

void release_buffer(void* buf) {
    free(buf);
}