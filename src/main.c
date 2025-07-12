#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "mem_test.h"
#include "utl.h"
#include "z80_public.h"

#define MEM_SIZE 64 * 1024

int main(int argc, char *argv[]) {
    uint8_t totalCycles;

    mem_init(MEM_SIZE);

    Z80InitData z80InitData = {argv[1], memory, &mem_read, &mem_write, NULL, NULL, NULL, 0};
    z80_init(&z80InitData);

    int count = 10000;
    do {
        count--;
        if (count == 0) {
            count = 10000;
            if (key_pressed()) {
                int key = get_key();
                if (key == 27) {
                    z80_debug();
                }
            }
        }

        totalCycles = z80_update();
        totalCycles += mem_getContendedCycles();
    } while(true);

    mem_dispose();

    return 0;
}