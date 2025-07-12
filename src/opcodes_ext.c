#include "opcodes_ext.h"
#include "z80.h"

    /* ================================================================ */
    /*                    EXT INSTRUCTIONS (0xED)                       */
    /* ================================================================ */
    
Opcode extOpcodePtrs[256] = {
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		

    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),

    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),	

    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),

    OC(in_b_ci, 2, 12, 0),		
    OC(out_ci_b, 2, 12, 0),		
    OC(sbc_hl_bc, 2, 15, 0),		
    OC(ld_nni_bc, 4, 20, 0),		
    OC(neg, 2, 8, 0),		
    OC_LITE(not_imp),
    OC(im_0, 2, 8, 0),
    OC(ld_i_a, 2, 9, 0),
    OC(in_c_ci, 2, 12, 0),
    OC(out_ci_c, 2, 12, 0),
    OC(adc_hl_bc, 2, 15, 0),		
    OC(ld_bc_nni, 4, 20, 0),		
    OC_LITE(not_imp),
    OC(reti, 2, 14, 0),
    OC_LITE(not_imp),		
    OC(ld_r_a, 2, 9, 0),

    OC(in_d_ci, 2, 12, 0),
    OC(out_ci_d, 2, 12, 0),
    OC(sbc_hl_de, 2, 15, 0),		
    OC(ld_nni_de, 4, 20, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(im_1, 2, 8, 0),
    OC_LITE(not_imp),
    OC(in_e_ci, 2, 12, 0),
    OC(out_ci_e, 2, 12, 0),
    OC(adc_hl_de, 2, 15, 0),		
    OC(ld_de_nni, 4, 20, 0),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC(im_2, 2, 8, 0),
    OC(ld_a_r, 2, 9, 0),

    OC(in_h_ci, 2, 12, 0),
    OC(out_ci_h, 2, 12, 0),
    OC(sbc_hl_hl, 2, 15, 0),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(rrd, 2, 18, 0),		
    OC(in_l_ci, 2, 12, 0),
    OC(out_ci_l, 2, 12, 0),
    OC(adc_hl_hl, 2, 15, 0),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(rld, 2, 18, 0),	

    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC(sbc_hl_sp, 2, 15, 0),		
    OC(ld_nni_sp, 4, 20, 0),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC(in_a_ci, 2, 12, 0),
    OC(out_ci_a, 2, 12, 0),
    OC(adc_hl_sp, 2, 15, 0),		
    OC(ld_sp_nni, 4, 20, 0),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),

    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),

    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),	
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),	
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),

    OC(ldi, 2, 16, 0),		
    OC(cpi, 2, 16, 0),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(ldd, 2, 16, 0),		
    OC(cpd, 2, 16, 0),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),

    OC_CC(ldir, 2, 21, 16),		
    OC_CC(cpir, 2, 21, 16),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_CC(lddr, 2, 21, 16),		
    OC_CC(cpdr, 2, 21, 16),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),

    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),

    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),

    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),

    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp)
};

void sbc_hl_bc() {
    execute16BitSub(z80.bc, &z80.hl);
}

void ld_nni_bc() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    memWriteFunc(address, z80.c);
    memWriteFunc(address + 1, z80.b);
}

void neg() {
    // HACEMOS 0 - A, VER SI SE PUEDE UNIFICAR CON execute8BitSub
    int16_t uDiff  = 0 - z80.a;
    int16_t  sDiff  = 0 - (char) z80.a;

    z80.flags.c     = uDiff < 0;
    z80.flags.n     = 1;
    z80.flags.pv    = (sDiff > 127) || (sDiff < -128);
    z80.flags.h     = (char) ((0 & 0x0F) - (z80.a & 0x0F)) < 0;
    z80.flags.z     = (uDiff & 0xFF) == 0x00;
    z80.flags.s     = (sDiff & 0x80) != 0;
    
    z80.a = uDiff;
}

void im_0() {
    z80.imode = 0;
}

void ld_i_a() {
    z80.i = z80.a;
}

void adc_hl_bc() {
    execute16BitAdd(z80.bc, &z80.hl, true);
}

void ld_bc_nni() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    z80.b = memReadFunc(address + 1);
    z80.c = memReadFunc(address);
}

void reti() {
    z80.pc = pop();    
}

void ld_r_a() {
    z80.r = z80.a;
}

void sbc_hl_de() {
    execute16BitSub(z80.de, &z80.hl);
}

void ld_nni_de() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    memWriteFunc(address, z80.e);
    memWriteFunc(address + 1, z80.d);
}

void im_1() {
    z80.imode = 1;
}

void adc_hl_de() {
    execute16BitAdd(z80.de, &z80.hl, true);
}

void ld_de_nni() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    z80.d = memReadFunc(address + 1);
    z80.e = memReadFunc(address);
}

void im_2() {
    z80.imode = 2;
}

void ld_a_r() {
    z80.a = z80.r;
    
    z80.flags.n     = 0;
    z80.flags.pv    = z80._iff2;
    z80.flags.h     = 0;
    z80.flags.z     = (z80.a & 0xFF) == 0x00;
    z80.flags.s     = (z80.a & 0x80) != 0;
}

void sbc_hl_hl() {
    execute16BitSub(z80.hl, &z80.hl);
}

void rrd() {
    uint8_t n = memReadFunc(z80.hl);
    uint8_t oldA = z80.a;
    uint8_t result = 0;
    
    z80.a &= 0xF0;
    
    z80.a |= n & 0x0F;
    result |= oldA << 4;    
    result |= n >> 4;
    memWriteFunc(z80.hl, result);

    z80.flags.n = 0;
    z80.flags.h = 0;
    z80.flags.pv = getParity(z80.a);
    z80.flags.z = z80.a == 0x00;
    z80.flags.s = (z80.a & 0x80) != 0;
}

void adc_hl_hl() {
    execute16BitAdd(z80.hl, &z80.hl, true);
}

void rld() {
    uint8_t n = memReadFunc(z80.hl);
    uint8_t oldA = z80.a;
    uint8_t result = 0;
    
    z80.a &= 0xF0;
    
    result |= n << 4;    
    z80.a |= (n & 0xF0) >> 4;
    result |= oldA & 0x0F;
    memWriteFunc(z80.hl, result);

    z80.flags.n = 0;
    z80.flags.h = 0;
    z80.flags.pv = getParity(z80.a);
    z80.flags.z = z80.a == 0x00;
    z80.flags.s = (z80.a & 0x80) != 0;
}

void sbc_hl_sp() {
    execute16BitSub(z80.sp, &z80.hl);
}

void adc_hl_sp() {
    execute16BitAdd(z80.sp, &z80.hl, true);
}

void ld_nni_sp() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    memWriteFunc(address, z80.sp & 0x00FF);
    memWriteFunc(address + 1, (z80.sp >> 8) & 0x00FF);
}

void ld_sp_nni() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    z80.sp = memReadFunc(address) + (memReadFunc(address + 1) << 8);
}

void ldi() {
    uint8_t n = memReadFunc(z80.hl++);
    memWriteFunc(z80.de++, n);
    z80.bc--;

    z80.flags.n = 0;
    z80.flags.pv = z80.bc != 0;
    z80.flags.h = 0;
}

void cpi() {
    uint8_t n = memReadFunc(z80.hl++);
    int8_t diff = z80.a - n;
    z80.bc--;

    z80.flags.n = 1;
    z80.flags.pv = z80.bc != 0;
    z80.flags.h = (char) ((z80.a & 0x0F) - (n & 0x0F)) < 0;
    z80.flags.z = diff == 0;
    z80.flags.s = (diff & 0x80) != 0;
}

void ldd() {
    int8_t n = memReadFunc(z80.hl--);
    memWriteFunc(z80.de--, n);
    z80.bc--;

    z80.flags.n = 0;
    z80.flags.pv = z80.bc != 0;
    z80.flags.h = 0;
}

void cpd() {
    uint8_t n = memReadFunc(z80.hl--);
    int8_t diff = z80.a - n;
    z80.bc--;

    z80.flags.n = 1;
    z80.flags.pv = z80.bc != 0;
    z80.flags.h = (char) ((z80.a & 0x0F) - (n & 0x0F)) < 0;
    z80.flags.z = diff == 0;
    z80.flags.s = (diff & 0x80) != 0;
}

bool ldir() {
    return executeConditionalBlock(&ldi, &testBc);        
}

bool cpir() {
    return executeConditionalBlock(&cpi, &testBcAndZ);        
}

bool lddr() {
    return executeConditionalBlock(&ldd, &testBc);        
}

bool cpdr() {
    return executeConditionalBlock(&cpd, testBcAndZ);        
}

void in_b_ci() {
    executeExtIn(&z80.b);
}

void in_c_ci() {
    executeExtIn(&z80.c);
}

void in_d_ci() {
    executeExtIn(&z80.d);
}

void in_e_ci() {
    executeExtIn(&z80.e);
}

void in_h_ci() {
    executeExtIn(&z80.h);
}

void in_l_ci() {
    executeExtIn(&z80.l);
}

void in_a_ci() {
    executeExtIn(&z80.a);
}

void out_ci_b() {
    ioWriteFunc(z80.bc, z80.b);
}

void out_ci_c() {
    ioWriteFunc(z80.bc, z80.c);
}

void out_ci_d() {
    ioWriteFunc(z80.bc, z80.d);
}

void out_ci_e() {
    ioWriteFunc(z80.bc, z80.e);
}

void out_ci_h() {
    ioWriteFunc(z80.bc, z80.h);
}

void out_ci_l() {
    ioWriteFunc(z80.bc, z80.l);
}

void out_ci_a() {
    ioWriteFunc(z80.bc, z80.a);
}


