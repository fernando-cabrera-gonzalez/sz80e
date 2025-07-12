#ifndef OPCODES_H
#define OPCODES_H

#include <stdbool.h>
#include <stdint.h>

#define OC_LITE(name) {#name, .ptr = &name}
#define OC(name, bytes, cycles, cyclesNotMet) {#name, .ptr = &name, bytes, cycles, cyclesNotMet}
#define OC_CC(name, bytes, cycles, cyclesNotMet) {#name, .ptrCC = &name, bytes, cycles, cyclesNotMet}

typedef void (*opcodeFuncPtr)();
typedef bool (*opcodeFuncPtrCC)();

typedef struct {
    char* mnemonic;
    union {
        opcodeFuncPtr ptr; 
        opcodeFuncPtrCC ptrCC;
    };
    uint8_t numBytes;
    uint8_t numCycles;
    uint8_t numCyclesNotMet;
} Opcode;


typedef enum {
    AND = 0, XOR = 1, OR = 2
} LOGICAL_OPERATOR;

    /* ================================================================ */
    /*                         OPCODE FUNCTIONS                         */
    /* ================================================================ */
    
void executeInc(uint8_t *value);
void executeDec(uint8_t *value);
void execute8BitAdd(uint8_t value, unsigned int carry);
void execute16BitAdd(uint16_t src, uint16_t *dst, bool isCarry);
void execute8BitSub(uint8_t value, unsigned int carry, bool storeResult);
void execute16BitSub(uint16_t src, uint16_t *dst);

void executeLogical(uint8_t value, LOGICAL_OPERATOR operator);

void executeRotateLeft(uint8_t *value, uint8_t *dst, bool isCircular);
void executeRotateRight(uint8_t *value, uint8_t *dst, bool isCircular);
void executeShiftLeft(uint8_t *value, uint8_t *dst, bool isArithmetic);
void executeShiftRight(uint8_t *value, uint8_t *dst, bool isArithmetic);
void executeBit(uint8_t value, uint8_t bit);
void executeReset(uint8_t bit, uint8_t *value);
void executeSet(uint8_t bit, uint8_t *value);

void executeXYRotateLeft(uint16_t src, uint8_t *dst, bool isCircular);
void executeXYRotateRight(uint16_t src, uint8_t *dst, bool isCircular);
void executeXYShiftLeft(uint16_t ireg, uint8_t *dst, bool isArithmetic);
void executeXYShiftRight(uint16_t ireg, uint8_t *dst, bool isArithmetic);
void executeXYBit(uint16_t ireg, uint8_t bit);
void executeXYReset(uint16_t ireg, uint8_t bit, uint8_t *dst);
void executeXYSet(uint16_t ireg, uint8_t bit, uint8_t *dst);

void executeExtIn(uint8_t* dst);

bool executeConditionalCall(bool condition);
bool executeConditionalReturn(bool condition);
bool executeConditionalRelativeJump(bool condition);
bool executeConditionalBlock(void (*atomicFuncPtr)(), bool (*conditionFuncPtr)());

void push(uint16_t value);
uint16_t pop();

void not_imp();

bool testBc();
bool testBcAndZ();

#endif