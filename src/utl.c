/*
 * utl.c - Utility Functions
 *
 * This file provides utility functions for file I/O operations, such as
 * loading and saving binary files. These are used for ROM and memory image
 * management in the emulator.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

long utl_load_binary(const char* fileName, uint8_t* dst) {
    FILE *f = fopen(fileName, "rb");
    long fileSize;

    if (f == NULL) {
        fprintf(stderr, "Error opening file %s from utl_load_binary()\n", fileName);
        return 0;
    }

    fseek(f, 0, SEEK_END);
    fileSize = ftell(f);
    fseek(f, 0, SEEK_SET); 
    
    fread(dst, sizeof(uint8_t), fileSize, f);
    fclose(f);

    return fileSize;
}

long utl_save_binary(const char* fileName, uint8_t* src) {
    FILE *f = fopen(fileName, "wb");

    if (f == NULL) {
        fprintf(stderr, "Error opening file %s from utl_save_binary()\n", fileName);
        return 0;
    }

    size_t written = fwrite(src, sizeof(uint8_t), 0xFFFF, f);
    if (written != 0xFFFF) {
        perror("Error writing to file");
        fclose(f);
        return 0;
    }
    fclose(f);

    return 1;
}

bool utl_has_file_extension(const char *fileName, const char *extension) {
    size_t fileLen = strlen(fileName);
    size_t extLen = strlen(extension);

    if (fileLen < extLen) return false;

    return strcmp(fileName + fileLen - extLen, extension) == 0;
}