#ifndef Z80_H
#define Z80_H

#include <stdio.h>

#include "opcodes.h"
#include "z80_public.h"

extern Opcode* opcodePtr;

typedef struct {
    uint16_t pc;
    uint16_t sp;
    union {
        struct {
            uint8_t ixl;
            uint8_t ixh;
        };
        uint16_t ix;
    };
    union {
        struct {
            uint8_t iyl;
            uint8_t iyh;
        };
        uint16_t iy;
    };
    uint8_t i;
    uint8_t r;

    /* Main register set */

    union {
        struct {
            uint8_t f;
            uint8_t a;
        };
        uint16_t af;
        struct Flags {
            uint8_t c  : 1;
            uint8_t n  : 1;
            uint8_t pv : 1;
            uint8_t x  : 1;
            uint8_t h  : 1;
            uint8_t y  : 1;
            uint8_t z  : 1;
            uint8_t s  : 1;
        } flags;
    };

    union {
        struct {
            uint8_t c;
            uint8_t b;
        };
        uint16_t bc;
    };

    union {
        struct {
            uint8_t e;
            uint8_t d;
        };
        uint16_t de;
    };

    union {
        struct {
            uint8_t l;
            uint8_t h;
        };
        uint16_t hl;
    };

    /* Alternate register set */

    uint16_t af2;
    uint16_t bc2;
    uint16_t de2;
    uint16_t hl2;

    uint8_t imode;
    bool _int;
    bool _iff1;
    bool _iff2;

    bool _halt;
} Z80;

extern Z80 z80;
extern uint8_t numCycles;

    /* ================================================================ */
    /*                           MISC FUNCTIONS                         */
    /* ================================================================ */

unsigned int getParity(uint8_t value);
void loadZ80(char *fileName, uint8_t* dst);
void loadSNA();

    /* ================================================================ */
    /*                          Z80 FUNCTIONS                           */
    /* ================================================================ */

void z80_reset();
Opcode* z80_fetchAndDecode();
Opcode* z80_step();
void z80_printState();
void z80_printOpcode(Opcode* opcodePtr, uint16_t pc, uint8_t numCycles);

#endif