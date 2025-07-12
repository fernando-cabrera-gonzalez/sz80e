#include "mem_test.h"
#include "utl_public.h"
#include "z80_public.h"

#define MEM_SIZE 64 * 1024

int main(int argc, char *argv[]) {
    uint8_t totalCycles;

    mem_init(MEM_SIZE);

    Z80InitData z80InitData = {argv[1], memory, &mem_read, &mem_write, NULL, NULL, NULL, 0};
    z80_init(&z80InitData);

    int key;
    do {
        key = utl_check_keyboard();
        totalCycles = z80_update();
        totalCycles += mem_getContendedCycles();
    } while(key != 27);

    mem_dispose();

    return 0;
}