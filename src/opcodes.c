#include <stdbool.h>

#include "z80.h"

    /* ================================================================ */
    /*                         OPCODE FUNCTIONS                         */
    /* ================================================================ */

void executeInc(uint8_t *value) {
    uint8_t old = (*value)++;

    // carry flag unaffected
    z80.flags.n     = 0;
    z80.flags.pv    = old == 0x7F;
    z80.flags.h     = (old & 0x0F) == 0x0F;   
    z80.flags.z     = *value == 0x00;
    z80.flags.s     = (*value & 0x80) != 0;
}

void executeDec(uint8_t *value) {
    uint8_t old = (*value)--;

    // carry flag unaffected
    z80.flags.n     = 1;
    z80.flags.pv    = old == 0x80;
    z80.flags.h     = (old & 0x0F) == 0x00;   
    z80.flags.z     = *value == 0x00;
    z80.flags.s     = (*value & 0x80) != 0;
}

void execute8BitAdd(uint8_t value, unsigned int carry) {
    uint16_t uSum   = z80.a + value + carry;
    int16_t  sSum   = (char) z80.a + (char) value + carry;

    z80.flags.c     = uSum > 255;
    z80.flags.n     = 0;
    z80.flags.pv    = (sSum > 127) || (sSum < -128);
    z80.flags.h     = ((z80.a & 0x0F) + (value & 0x0F) + carry) > 15;
    z80.flags.z     = (uSum & 0xFF) == 0x00;
    z80.flags.s     = (sSum & 0x80) == 0x80;

    z80.a = uSum;
}

void execute16BitAdd(uint16_t src, uint16_t *dst, bool isCarry) {
    unsigned int carry = isCarry ? z80.flags.c : 0;
    uint32_t uSum   = *dst + src + carry;
    int32_t  sSum   = (int16_t) *dst + (int16_t) src + carry;

    z80.flags.c     = uSum > 0xFFFF;
    z80.flags.n     = 0;
    z80.flags.h     = ((*dst & 0x0FFF) + (src & 0x0FFF) + carry) > 0xFFF;
    
    if (isCarry) {
        z80.flags.pv    = (sSum > 0x7FFF) || (sSum < -0x8000);
        z80.flags.z     = (uSum & 0xFFFF) == 0x0000;
        z80.flags.s     = (sSum & 0x8000) == 0x8000;
    }

    *dst = uSum;
}

void execute8BitSub(uint8_t value, unsigned int carry, bool storeResult) {
    int16_t uDiff  = z80.a - value - carry;
    int16_t  sDiff  = (char) z80.a - (char) value - carry;

    z80.flags.c     = uDiff < 0;
    z80.flags.n     = 1;
    z80.flags.pv    = (sDiff > 127) || (sDiff < -128);
    z80.flags.h     = (char) ((z80.a & 0x0F) - (value & 0x0F) - carry) < 0;
    z80.flags.z     = (uDiff & 0xFF) == 0x00;
    z80.flags.s     = (sDiff & 0x80) != 0;

    if (storeResult) {
        z80.a = uDiff;
    }
}

void execute16BitSub(uint16_t src, uint16_t *dst) {
    int32_t uDiff  = *dst - src - z80.flags.c;
    int32_t  sDiff  = (int16_t) *dst - (int16_t) src - z80.flags.c;

    z80.flags.c     = uDiff < 0;
    z80.flags.n     = 1;
    z80.flags.pv    = (sDiff > 0x07FFF) || (sDiff < -0x8000);
    z80.flags.h     = (int16_t) ((*dst & 0x0FFF) - (src & 0x0FFF) - z80.flags.c) < 0;
    z80.flags.z     = (uDiff & 0xFFFF) == 0x00;
    z80.flags.s     = (sDiff & 0x8000) != 0;

    *dst = uDiff;
}

void executeLogical(uint8_t value, LOGICAL_OPERATOR operator) {
    switch (operator)
    {
    case AND:
        z80.a &= value;
        z80.flags.h = 1;
        break;
    case XOR:
        z80.a ^= value;
        z80.flags.h = 0;
        break;
    case OR:
        z80.a |= value;
         z80.flags.h = 0;
        break;    
    }

    z80.flags.c     = 0;
    z80.flags.n     = 0;
    z80.flags.pv    = getParity(z80.a);
    z80.flags.z     = z80.a == 0x00;
    z80.flags.s     = (z80.a & 0x80) != 0;
}

void executeRotateLeft(uint8_t *value, uint8_t *dst, bool isCircular) {
    uint8_t oldCFlag = z80.flags.c;

    z80.flags.n = 0;
    z80.flags.h = 0;
    z80.flags.c = *value >> 7;
    
    *value <<=  1;
    if ((isCircular && z80.flags.c) || (!isCircular && oldCFlag)) {
        *value |= 0x01;
    } else {
        *value &= 0xFE;
    }
    
    z80.flags.pv = getParity(*value);
    z80.flags.z = *value == 0x00;
    z80.flags.s = (*value & 0x80) != 0;

    if (dst) {
        *dst = *value;
    }
}

void executeRotateRight(uint8_t *value, uint8_t *dst, bool isCircular) {
    uint8_t oldCFlag = z80.flags.c;

    z80.flags.n = 0;
    z80.flags.h = 0;
    z80.flags.c = *value & 0x01;
    
    *value >>=  1;
    if ((isCircular && z80.flags.c) || (!isCircular && oldCFlag)) {
        *value |= 0x80;
    } else {
        *value &= 0x7F;
    }
    
    z80.flags.pv = getParity(*value);
    z80.flags.z = *value == 0x00;
    z80.flags.s = (*value & 0x80) != 0;

    if (dst) {
        *dst = *value;
    }
}

void executeShiftLeft(uint8_t *value, uint8_t *dst, bool isArithmetic) {
    z80.flags.n = 0;
    z80.flags.h = 0;
    z80.flags.c = *value >> 7;
    
    *value <<=  1;
    if (isArithmetic) {
        *value &= 0xFE;
    } else {
        *value |= 0x01;
    }
    
    z80.flags.pv = getParity(*value);
    z80.flags.z = *value == 0x00;
    z80.flags.s = (*value & 0x80) != 0;

    if (dst) {
        *dst = *value;
    }
}

void executeShiftRight(uint8_t *value, uint8_t *dst, bool isArithmetic) {
    uint8_t oldBit7;


    oldBit7 = *value & 0x80;

    z80.flags.n = 0;
    z80.flags.h = 0;
    z80.flags.c = *value & 0x01;
    
    *value >>=  1;
    if (!isArithmetic) {
        *value &= 0x7F;
    } else {
        *value |= oldBit7;
    }
    
    z80.flags.pv = getParity(*value);
    z80.flags.z = *value == 0x00;
    z80.flags.s = (*value & 0x80) != 0;

    if (dst) {
        *dst = *value;
    }
}

void executeBit(uint8_t bit, uint8_t value) {
    z80.flags.n = 0;
    z80.flags.h = 1;
    z80.flags.z = ((value >> bit) & 0x01) == 0;
}

void executeReset(uint8_t bit, uint8_t *value) {
    *value &= ~(0x01 << bit);
}

void executeSet(uint8_t bit, uint8_t *value) {
    *value |= (0x01 << bit);
}

void executeXYRotateLeft(uint16_t ireg, uint8_t *dst, bool isCircular) {
    int8_t d = memReadFunc(z80.pc - 2);
    uint8_t n = memReadFunc(ireg + d);
    executeRotateLeft(&n, dst, isCircular);
    memWriteFunc(ireg + d, n);
}

void executeXYRotateRight(uint16_t ireg, uint8_t *dst, bool isCircular) {
    int8_t d = memReadFunc(z80.pc - 2);
    uint8_t n = memReadFunc(ireg + d);
    executeRotateRight(&n, dst, isCircular);
    memWriteFunc(ireg + d, n);
}

void executeXYShiftLeft(uint16_t ireg, uint8_t *dst, bool isArithmetic) {
    int8_t d = memReadFunc(z80.pc - 2);
    uint8_t n = memReadFunc(ireg + d);
    executeShiftLeft(&n, dst, isArithmetic);
    memWriteFunc(ireg + d, n);
}

void executeXYShiftRight(uint16_t ireg, uint8_t *dst, bool isArithmetic) {
    int8_t d = memReadFunc(z80.pc - 2);
    uint8_t n = memReadFunc(ireg + d);
    executeShiftRight(&n, dst, isArithmetic);
    memWriteFunc(ireg + d, n);
}

void executeXYBit(uint16_t ireg, uint8_t bit) {
    int8_t d = memReadFunc(z80.pc - 2);
    uint8_t n = memReadFunc(ireg + d);
    executeBit(bit, n);
}

void executeXYReset(uint16_t ireg, uint8_t bit, uint8_t *dst) {
    int8_t d = memReadFunc(z80.pc - 2);
    uint8_t n = memReadFunc(ireg + d);
    executeReset(bit, &n);
    memWriteFunc(ireg + d, n);

    if (dst) {
        *dst = n;
    }
}

void executeXYSet(uint16_t ireg, uint8_t bit, uint8_t *dst) {
    int8_t d = memReadFunc(z80.pc - 2);
    uint8_t n = memReadFunc(ireg + d);
    executeSet(bit, &n);
    memWriteFunc(ireg + d, n);
    
    if (dst) {
        *dst = n;
    }
}

void executeExtIn(uint8_t* dst) {
    *dst = ioReadFunc(z80.bc);
    
    z80.flags.n     = 0;
    z80.flags.h     = 0;
    z80.flags.pv    = getParity(*dst);
    z80.flags.z     = *dst == 0x00;
    z80.flags.s     = (*dst & 0x80) != 0;
}

bool executeConditionalCall(bool condition) {
    if (condition) {
       push(z80.pc);
       z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
       return true;
    }    
    return false;
}

bool executeConditionalReturn(bool condition) {
    if (condition) {
        z80.pc = pop();
        return true;
    }
    return false;
}

bool executeConditionalRelativeJump(bool condition) {
    if (condition) {
        int8_t d = memReadFunc(z80.pc - 1);
        z80.pc += d;
        return true;
    }
    return false;
}

bool executeConditionalBlock(void (*atomicFuncPtr)(), bool (*conditionFuncPtr)()) {
    atomicFuncPtr();
    if (conditionFuncPtr()) {
        z80.pc -= 2;
        return true;
    }
    return false;

}

void push(uint16_t value) {
    z80.sp--;
    memWriteFunc(z80.sp, (value & 0xFF00) >> 8);
    z80.sp--;
    memWriteFunc(z80.sp, value & 0x00FF);
}

uint16_t pop() {
    uint16_t value = memReadFunc(z80.sp);
    z80.sp++;
    value += memReadFunc(z80.sp) << 8;
    z80.sp++;

    return value;
}

bool testBc() {
    return z80.bc;
}

bool testBcAndZ() {
    return z80.bc && !z80.flags.z;
}