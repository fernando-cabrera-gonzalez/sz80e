/*
 * mem_test.c - Memory Management
 *
 * This file implements memory allocation, read, write, and cleanup functions
 * for the Z80 emulator. It provides a simple memory model for the emulated system.
 *
 * Functions:
 *   - mem_init:    Allocate and initialize memory
 *   - mem_read:    Read a byte from memory
 *   - mem_write:   Write a byte to memory
 *   - mem_dispose: Free allocated memory
 */

#include <malloc.h>
#include <stdint.h>

uint8_t *memory;

void mem_init(size_t size) {
    memory = (uint8_t*) calloc(size, sizeof(uint8_t));
}

uint8_t mem_read(uint16_t address) {
    return memory[address];   
}

void mem_write(uint16_t address, uint8_t value) {
    memory[address] = value;
}

uint8_t mem_getContendedCycles() {
    return 0;
}

void mem_dispose() {
    free(memory);
}