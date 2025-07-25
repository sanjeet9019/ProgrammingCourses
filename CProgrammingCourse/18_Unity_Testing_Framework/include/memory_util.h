#ifndef MEMORY_UTIL_H
#define MEMORY_UTIL_H

#include <stddef.h>

void* allocate_buffer(size_t size);
void clear_buffer(char* buf, size_t size);
void release_buffer(void* buf);

#endif