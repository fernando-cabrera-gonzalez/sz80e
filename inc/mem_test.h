#ifndef MEM_H
#define MEM_H

#include <stdint.h>

extern uint8_t *memory;

void mem_init(size_t size);
uint8_t mem_read(uint16_t address);
void mem_write(uint16_t address, uint8_t value);
uint8_t mem_getContendedCycles();
void mem_dispose();

#endif