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