#include <stdlib.h>
#include <memory.h>

#include "dbg.h"
#include "opcodes_bit.h"
#include "opcodes_ext.h"
#include "opcodes_ix.h"
#include "opcodes_iy.h"
#include "opcodes_main.h"
#include "utl.h"
#include "z80.h"

#define MEM_BLOCK_LENGTH 16384

Z80 z80;
uint8_t numCycles;

uint8_t opcode, extOpcode, extBitOpcode;
uint16_t notImplementedList[256];
uint8_t niSize = 0;
 
Opcode* opcodePtr;

Z80MemReadFunc memReadFunc;
Z80MemWriteFunc memWriteFunc;
Z80IOReadFunc ioReadFunc;
Z80IOWriteFunc ioWriteFunc;
Z80RenderFunc renderFunc;


    /* ================================================================ */
    /*                           MISC FUNCTIONS                         */
    /* ================================================================ */

unsigned int getParity(uint8_t value) {
    int count = 0;
    uint8_t mask = 0x01;
    for (int i = 0; i < 8; i++) {
        count += (value & mask) != 0;
        mask <<= 1;
    }
    return count % 2 == 0;
}

void uncompressData(uint8_t* src, uint8_t* dst, uint16_t length) {
    uint8_t* block_end = dst + MEM_BLOCK_LENGTH;
    for (int i = 0; i < length && dst < block_end; i++) {
        if (*src == 0xED && *(src + 1) == 0xED) {
            for (int j = 0; j < *(src + 2); j++) {
                *dst = *(src + 3);
                dst++;
            }
            src += 4;
        } else {
            *dst = *src;
            src++;
            dst++;
        } 
    }
}

void loadZ80(char* fileName, uint8_t* dst) {
    uint8_t* bfr = (uint8_t *) calloc(48 * 1024, sizeof(uint8_t));
    uint16_t dataIndex = 0;

    long fileSize = utl_load_binary(fileName, bfr);

    // first header
    z80.a   = bfr[0];
    z80.f   = bfr[1];
    z80.bc  = bfr[2] + bfr[3] * 256;
    z80.hl  = bfr[4] + bfr[5] * 256;
    z80.pc  = bfr[6] + bfr[7] * 256;
    z80.sp  = bfr[8] + bfr[9] * 256;
    z80.i   = bfr[10];
    z80.r = (bfr[11] & 0x7F) | ((bfr[12] & 0x01) << 7);

    z80.de  = bfr[13] + bfr[14] * 256;
    z80.bc2 = bfr[15] + bfr[16] * 256;
    z80.de2 = bfr[17] + bfr[18] * 256;
    z80.hl2 = bfr[19] + bfr[20] * 256;
    z80.af2 = bfr[22] + bfr[21] * 256;
    z80.iy  = bfr[23] + bfr[24] * 256;
    z80.ix  = bfr[25] + bfr[26] * 256;
    z80._iff1 = bfr[27];
    z80._iff2 = bfr[28];
    z80.imode = bfr[29] & 0x03;

    // second header
    z80.pc = bfr[32] + bfr[33] * 256;

    // data blocks
    dataIndex = 30 + (bfr[30] + bfr[31] * 256) + 2;
    while (dataIndex < fileSize) {
        uint16_t dataLength = bfr[dataIndex] + bfr[dataIndex + 1] * 256;
        uint16_t dstAddress;
        switch(bfr[dataIndex + 2]) {
            case 8:
                dstAddress = 0x4000;
                break;
            case 4:
                dstAddress = 0x8000;
                break;
            case 5:
                dstAddress = 0xC000;
                break;
        }
        dataIndex += 3;

        uncompressData(&bfr[dataIndex], &dst[dstAddress], dataLength);
        dataIndex += dataLength;
    }    

    free(bfr);
}

void loadSNA(char* fileName, uint8_t* dst) {
    uint8_t* bfr = (uint8_t *) calloc(64 * 1024, sizeof(uint8_t));
    utl_load_binary(fileName, bfr);

    // header
    z80.i   = bfr[0];

    z80.hl2 = bfr[1] + bfr[2] * 256;
    z80.de2 = bfr[3] + bfr[4] * 256;
    z80.bc2 = bfr[5] + bfr[6] * 256;
    z80.af2 = bfr[7] + bfr[8] * 256;

    z80.hl  = bfr[9] + bfr[10] * 256;
    z80.de  = bfr[11] + bfr[12] * 256;
    z80.bc  = bfr[13] + bfr[14] * 256;

    z80.iy  = bfr[15] + bfr[16] * 256;
    z80.ix  = bfr[17] + bfr[18] * 256;

    z80.r   = bfr[20];
    z80.af  = bfr[21] + bfr[22] * 256;
    z80.sp  = bfr[23] + bfr[24] * 256;
    z80.imode = bfr[25] & 0x03;

    // data blocks
    memcpy(dst + 0x4000, bfr + 27, sizeof(uint8_t) * 1024 * 48);
    z80.pc = dst[z80.sp] + (dst[z80.sp + 1] << 8);
    z80.sp += 2;

    free(bfr);
}

void not_imp() {
    uint16_t item = opcode * 256 + extOpcode; 
    bool found = false;
    
    for (int i = 0; i < niSize; i++) {
        if (notImplementedList[i] == item) {
            found = true;
            break;
        }
    }
    
    if (!found) {
        notImplementedList[niSize++] = item;
        printf("ERROR: NOT IMPLEMENTED 0x%04x 0x%01x 0x%01x 0x%01x\n", z80.pc, opcode, extOpcode, extBitOpcode);
    }
}

    /* ================================================================ */
    /*                          Z80 FUNCTIONS                           */
    /* ================================================================ */

uint8_t z80_voidIoReadFunc(uint16_t address) {
    return 0;
} 

void z80_voidIoWriteFunc(uint16_t address, uint8_t value) {
}

void z80_voidRenderFunc() {
}

void z80_init(Z80InitData* z80InitData) {
    z80_reset(z80);

    if (z80InitData->ramFileName) {
        if (!utl_has_file_extension(z80InitData->ramFileName, ".z80") && 
            !utl_has_file_extension(z80InitData->ramFileName, ".sna")) {
            utl_load_binary(z80InitData->ramFileName, z80InitData->memoryPtr);  
        } else {        
            utl_load_binary("./bin/rom.bin", z80InitData->memoryPtr);    
            if (utl_has_file_extension(z80InitData->ramFileName, ".z80")) {
                loadZ80(z80InitData->ramFileName, z80InitData->memoryPtr);
            } else if (utl_has_file_extension(z80InitData->ramFileName, ".sna")) {
                loadSNA(z80InitData->ramFileName, z80InitData->memoryPtr);
            }
        }
    } else {
        utl_load_binary("./bin/rom.bin", z80InitData->memoryPtr);
    }

    memReadFunc = z80InitData->memReadFunc;
    memWriteFunc = z80InitData->memWriteFunc;
    ioReadFunc = z80InitData->ioReadFunc ? z80InitData->ioReadFunc : z80_voidIoReadFunc;
    ioWriteFunc = z80InitData->ioWriteFunc ? z80InitData->ioWriteFunc : z80_voidIoWriteFunc;
    renderFunc = z80InitData->renderFunc ? z80InitData->renderFunc : z80_voidRenderFunc;
    if (z80InitData->startAddress) {
        z80.pc = z80InitData->startAddress;
    }
}

void z80_reset() {
    z80.f = 0;
    z80.i = 0;
    z80.r = 0;
    z80.pc = 0x0000;
    z80.sp = 0xFFFF;

    z80.imode = 0;
    z80._int = false;
    z80._iff1 = z80._iff2 = false;

    z80._halt = false;
}

Opcode* z80_fetchAndDecode() {
    opcode = memReadFunc(z80.pc);
    switch(opcode) {
        case 0xCB:
            extOpcode = memReadFunc(z80.pc + 1);
            return &bitOpcodePtrs[extOpcode];
        case 0xDD:
            extOpcode = memReadFunc(z80.pc + 1);
            if (extOpcode != 0xCB) {              
                return &ixOpcodePtrs[extOpcode];
            } else {
                extBitOpcode = memReadFunc(z80.pc + 3);
                return &ixBitOpcodePtrs[extBitOpcode];
            }
        case 0xED:
            extOpcode = memReadFunc(z80.pc + 1);
            return &extOpcodePtrs[extOpcode];
        case 0xFD:
            extOpcode = memReadFunc(z80.pc + 1);
            if (extOpcode != 0xCB) {      
                return &iyOpcodePtrs[extOpcode];         
            } else {
                extBitOpcode = memReadFunc(z80.pc + 3);     
                return &iyBitOpcodePtrs[extBitOpcode];
            }        
        default:
            return &opcodePtrs[opcode];
    }    
}

static inline void z80_inc_r() {
    z80.r = (z80.r & 0x80) | ((z80.r + 1) & 0x7f);
}

Opcode* z80_step() {
    Opcode* opcodePtr;
    
    #if DEBUG_LEVEL == DEBUG_LEVEL_FULL
    uint16_t oldPC = z80.pc;
    z80_printState();
    #endif

    opcodePtr = z80_fetchAndDecode();
    z80.pc += opcodePtr->numBytes;
    z80_inc_r();

    if (opcodePtr->numCyclesNotMet == 0) {
        opcodePtr->ptr();
        numCycles = opcodePtr->numCycles;
    } else {
        bool condition = opcodePtr->ptrCC();
        numCycles = condition ? opcodePtr -> numCycles : opcodePtr->numCyclesNotMet;
    }

    #if DEBUG_LEVEL == DEBUG_LEVEL_FULL
    z80_printOpcode(opcodePtr, oldPC, 0);
    #endif

    return opcodePtr;
}

uint8_t z80_update() {
    numCycles = 0;

    #if DEBUG_LEVEL == DEBUG_LEVEL_USER
    if (dbg_requested) {
        dbg_requested = false;
        puts("");
        dbg_readCommand();
    }
    #endif

    if (!z80._halt) {
        #if DEBUG_LEVEL == DEBUG_LEVEL_USER
        if (dbg_hasBreakPoint(z80.pc)) {
            printf("Stopped at PC = 0x%04x...\n", z80.pc);
            dbg_readCommand();
        }
        #endif

        opcodePtr = z80_step();

        #if DEBUG_LEVEL == DEBUG_LEVEL_USER
        if (numSteps != -1) {
            if (--numSteps == 0) {
                numSteps = -1;
                dbg_readCommand();
            }
        }
        #endif
    } else {
        z80_inc_r();
    }

    if (z80._int) {
        renderFunc();

        if (z80._iff1) {
            z80._int = false;
            z80._halt = false;
            z80._iff1 = false;
            z80._iff2 = false;
            
            z80_inc_r();
            push(z80.pc);
            switch(z80.imode) {
                case 1:
                    #if DEBUG_LEVEL == DEBUG_LEVEL_FULL
                    printf("\n*************** INT 1! PC = 0x%02x -> 0x0038\n\n", z80.pc);
                    #endif
                    z80.pc = 0x0038;
                    break;
                case 2:
                    uint16_t ivtAddress = z80.i << 8;
                    #if DEBUG_LEVEL == DEBUG_LEVEL_FULL
                    printf("\n*************** INT 2! PC = 0x%02x -> 0x%04x\n\n", z80.pc, memReadFunc(ivtAddress) + (memReadFunc(ivtAddress + 1) << 8));
                    #endif
                    z80.pc = memReadFunc(ivtAddress) + (memReadFunc(ivtAddress + 1) << 8);
                    break;
            }               
        } else {
            z80._int = false;
        }
    }

    return numCycles;
}

#if DEBUG_LEVEL == DEBUG_LEVEL_USER
void z80_debug() {
    dbg_requested = true;
}
#endif

void z80_setInt() {
    z80._int = true;
}

bool z80_isHalted() {
    return z80._halt;
}

void z80_printState() {
    printf("PC = 0x%04x (%05u) SP = 0x%04x (%05u) IX = 0x%04x (%05u) IY = 0x%04x (%05u)\n", z80.pc, z80.pc, z80.sp, z80.sp, z80.ix, z80.ix, z80.iy, z80.iy);
    printf("A  =   0x%02x   (%03hu) F  =   0x%02x   (%03hu) AF = 0x%04x (%05u) I =    0x%02x   (%03hu)\n", z80.a, z80.a, z80.f, z80.f, z80.af, z80.af, z80.i, z80.i);
    printf("B  =   0x%02x   (%03hu) C  =   0x%02x   (%03hu) BC = 0x%04x (%05u) R =    0x%02x   (%03hu)\n", z80.b, z80.b, z80.c, z80.c, z80.bc, z80.bc, z80.r, z80.r);
    printf("D  =   0x%02x   (%03hu) E  =   0x%02x   (%03hu) DE = 0x%04x (%05u) IMODE = %i (%s)\n", z80.d, z80.d, z80.e, z80.e, z80.de, z80.de, z80.imode, z80._iff1 == 0 ? "OFF" : "ON");
    printf("H  =   0x%02x   (%03hu) L  =   0x%02x   (%03hu) HL = 0x%04x (%05u)\n", z80.h, z80.h, z80.l, z80.l, z80.hl, z80.hl);
    puts(  "FLAGS: S   Z   Y   H   X   PV  N   C");
    printf("       %u   %u   %u   %u   %u   %u   %u   %u\n", z80.flags.s, z80.flags.z, z80.flags.y, z80.flags.h, z80.flags.x, z80.flags.pv, z80.flags.n, z80.flags.c);   
}

void z80_printOpcode(Opcode* opcodePtr, uint16_t pc, uint8_t numCycles) {
    puts("-------------------------------------------------------------------------------");
    printf("OPCODE: %s = ", opcodePtr->mnemonic);

    if (numCycles) {
        printf(" -> %d cycles \n-------------------------------------------------------------------------------\n", numCycles);
    } else {
        printf(" -> %d / %d cycles \n-------------------------------------------------------------------------------\n", opcodePtr->numCycles, opcodePtr->numCyclesNotMet);
    }
}