#ifndef UTL_H
#define UTL_H

#include <stdint.h>

int utl_load_binary(const char* fileName, uint8_t* dst);
int utl_save_binary(const char* fileName, uint8_t* src);
bool utl_has_file_extension(const char *fileName, const char *extension);

#endif