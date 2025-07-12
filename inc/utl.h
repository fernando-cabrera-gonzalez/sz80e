#ifndef UTL_H
#define UTL_H

#include <stdint.h>

int utl_loadBinary(const char* fileName, uint8_t* dst);
int utl_saveBinary(const char* fileName, uint8_t* src);
bool key_pressed();
int get_key();
bool hasFileExtension(const char *fileName, const char *extension);

#endif