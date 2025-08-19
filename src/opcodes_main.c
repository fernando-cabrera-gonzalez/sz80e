/*
 * opcodes_main.c - Main Opcode Table (0x00-0xFF)
 *
 * This file defines the main opcode table and handlers for the Z80 CPU's
 * standard instructions (no prefix, 0x00-0xFF).
 *
 * Each entry maps an opcode to its handler, instruction length, and cycle count.
 */

#include "opcodes_main.h"
#include "z80.h"

    /* ================================================================ */
    /*                 MAIN INSTRUCTIONS (0x00 - 0xFF)                  */
    /* ================================================================ */

Opcode opcodePtrs[256] = {
    // 00 - 0F
    OC(nop, 1, 4, 0),		
    OC(ld_bc_nn, 3, 10, 0),		
    OC(ld_bci_a, 1, 7, 0),		
    OC(inc_bc, 1, 6, 0),		
    OC(inc_b, 1, 4, 0),		
    OC(dec_b, 1, 4, 0),		
    OC(ld_b_n, 2, 7, 0),		
    OC(rlca, 1, 4, 0),		
    OC(ex_af_af2, 1, 4, 0),		
    OC(add_hl_bc, 1, 11, 0),		
    OC(ld_a_bci, 1, 7, 0),		
    OC(dec_bc, 1, 6, 0),		
    OC(inc_c, 1, 4, 0),		
    OC(dec_c, 1, 4, 0),		
    OC(ld_c_n, 2, 7, 0),		
    OC(rrca, 1, 4, 0),		

    // 10 - 1F
    OC_CC(djnz_d, 2, 13, 8),		
    OC(ld_de_nn, 3, 10, 0),		
    OC(ld_dei_a, 1, 7, 0),		
    OC(inc_de, 1, 6, 0),		
    OC(inc_d, 1, 4, 0),		
    OC(dec_d, 1, 4, 0),		
    OC(ld_d_n, 2, 7, 0),		
    OC(rla, 1, 4, 0),		
    OC(jr_d, 2, 12, 0),		
    OC(add_hl_de, 1, 11, 0),		
    OC(ld_a_dei, 1, 7, 0),		
    OC(dec_de, 1, 6, 0),		
    OC(inc_e, 1, 4, 0),		
    OC(dec_e, 1, 4, 0),		
    OC(ld_e_n, 2, 7, 0),		
    OC(rra, 1, 4, 0),		

    // 20 - 2F
    OC_CC(jr_nz_d, 2, 12, 7),		
    OC(ld_hl_nn, 3, 10, 0),		
    OC(ld_nni_hl, 3, 16, 0),		
    OC(inc_hl, 1, 6, 0),		
    OC(inc_h, 1, 4, 0),		
    OC(dec_h, 1, 4, 0),		
    OC(ld_h_n, 2, 7, 0),		
    OC(daa, 1, 4, 0),		
    OC_CC(jr_z_d, 2, 12, 7),		
    OC(add_hl_hl, 1, 11, 0),		
    OC(ld_hl_nni, 3, 16, 0),		
    OC(dec_hl, 1, 6, 0),		
    OC(inc_l, 1, 4, 0),		
    OC(dec_l, 1, 4, 0),		
    OC(ld_l_n, 2, 7, 0),		
    OC(cpl, 1, 4, 0),	

    // 30 - 3F
    OC_CC(jr_nc_d, 2, 12, 7),		
    OC(ld_sp_nn, 3, 10, 0),		
    OC(ld_nni_a, 3, 13, 0),		
    OC(inc_sp, 1, 6, 0),		
    OC(inc_hli, 1, 11, 0),		
    OC(dec_hli, 1, 11, 0),		
    OC(ld_hli_n, 2, 10, 0),		
    OC(scf, 1, 4, 0),		
    OC_CC(jr_c_d, 2, 12, 7),		
    OC(add_hl_sp, 1, 11, 0),		
    OC(ld_a_nni, 3, 13, 0),		
    OC(dec_sp, 1, 6, 0),		
    OC(inc_a, 1, 4, 0),		
    OC(dec_a, 1, 4, 0),		
    OC(ld_a_n, 2, 7, 0),		
    OC(ccf, 1, 4, 0),		

    // 40 - 4F
    OC(ld_b_b, 1, 4, 0),		
    OC(ld_b_c, 1, 4, 0),		
    OC(ld_b_d, 1, 4, 0),		
    OC(ld_b_e, 1, 4, 0),		
    OC(ld_b_h, 1, 4, 0),		
    OC(ld_b_l, 1, 4, 0),		
    OC(ld_b_hli, 1, 7, 0),		
    OC(ld_b_a, 1, 4, 0),		
    OC(ld_c_b, 1, 4, 0),		
    OC(ld_c_c, 1, 4, 0),		
    OC(ld_c_d, 1, 4, 0),		
    OC(ld_c_e, 1, 4, 0),		
    OC(ld_c_h, 1, 4, 0),		
    OC(ld_c_l, 1, 4, 0),		
    OC(ld_c_hli, 1, 7, 0),		
    OC(ld_c_a, 1, 4, 0),	

    // 50 - 5F
    OC(ld_d_b, 1, 4, 0),		
    OC(ld_d_c, 1, 4, 0),		
    OC(ld_d_d, 1, 4, 0),		
    OC(ld_d_e, 1, 4, 0),		
    OC(ld_d_h, 1, 4, 0),		
    OC(ld_d_l, 1, 4, 0),		
    OC(ld_d_hli, 1, 7, 0),		
    OC(ld_d_a, 1, 4, 0),		
    OC(ld_e_b, 1, 4, 0),		
    OC(ld_e_c, 1, 4, 0),		
    OC(ld_e_d, 1, 4, 0),		
    OC(ld_e_e, 1, 4, 0),		
    OC(ld_e_h, 1, 4, 0),		
    OC(ld_e_l, 1, 4, 0),		
    OC(ld_e_hli, 1, 7, 0),		

    // 60 - 6F
    OC(ld_e_a, 1, 4, 0),		
    OC(ld_h_b, 1, 4, 0),		
    OC(ld_h_c, 1, 4, 0),		
    OC(ld_h_d, 1, 4, 0),		
    OC(ld_h_e, 1, 4, 0),		
    OC(ld_h_h, 1, 4, 0),		
    OC(ld_h_l, 1, 4, 0),		
    OC(ld_h_hli, 1, 7, 0),		
    OC(ld_h_a, 1, 4, 0),		
    OC(ld_l_b, 1, 4, 0),		
    OC(ld_l_c, 1, 4, 0),		
    OC(ld_l_d, 1, 4, 0),		
    OC(ld_l_e, 1, 4, 0),		
    OC(ld_l_h, 1, 4, 0),		
    OC(ld_l_l, 1, 4, 0),		
    OC(ld_l_hli, 1, 7, 0),		
    OC(ld_l_a, 1, 4, 0),	

    // 70 - 7F
    OC(ld_hli_b, 1, 7, 0),		
    OC(ld_hli_c, 1, 7, 0),		
    OC(ld_hli_d, 1, 7, 0),		
    OC(ld_hli_e, 1, 7, 0),		
    OC(ld_hli_h, 1, 7, 0),		
    OC(ld_hli_l, 1, 7, 0),		
    OC(halt, 1, 4, 0),		
    OC(ld_hli_a, 1, 7, 0),		
    OC(ld_a_b, 1, 4, 0),		
    OC(ld_a_c, 1, 4, 0),		
    OC(ld_a_d, 1, 4, 0),		
    OC(ld_a_e, 1, 4, 0),		
    OC(ld_a_h, 1, 4, 0),		
    OC(ld_a_l, 1, 4, 0),		
    OC(ld_a_hli, 1, 7, 0),		
    OC(ld_a_a, 1, 4, 0),

    // 80 - 8F
    OC(add_a_b, 1, 4, 0),		
    OC(add_a_c, 1, 4, 0),		
    OC(add_a_d, 1, 4, 0),		
    OC(add_a_e, 1, 4, 0),		
    OC(add_a_h, 1, 4, 0),		
    OC(add_a_l, 1, 4, 0),		
    OC(add_a_hli, 1, 7, 0),		
    OC(add_a_a, 1, 4, 0),		
    OC(adc_a_b, 1, 4, 0),		
    OC(adc_a_c, 1, 4, 0),		
    OC(adc_a_d, 1, 4, 0),		
    OC(adc_a_e, 1, 4, 0),		
    OC(adc_a_h, 1, 4, 0),		
    OC(adc_a_l, 1, 4, 0),		
    OC(adc_a_hli, 1, 7, 0),		
    OC(adc_a_a, 1, 4, 0),	

    // 90 - 9F
    OC(sub_b, 1, 4, 0),		
    OC(sub_c, 1, 4, 0),		
    OC(sub_d, 1, 4, 0),		
    OC(sub_e, 1, 4, 0),		
    OC(sub_h, 1, 4, 0),		
    OC(sub_l, 1, 4, 0),		
    OC(sub_hli, 1, 7, 0),		
    OC(sub_a, 1, 4, 0),		
    OC(sbc_a_b, 1, 4, 0),		
    OC(sbc_a_c, 1, 4, 0),		
    OC(sbc_a_d, 1, 4, 0),		
    OC(sbc_a_e, 1, 4, 0),		
    OC(sbc_a_h, 1, 4, 0),		
    OC(sbc_a_l, 1, 4, 0),		
    OC(sbc_a_hli, 1, 7, 0),		
    OC(sbc_a_a, 1, 4, 0),		

    // A0 - AF
    OC(and_b, 1, 4, 0),		
    OC(and_c, 1, 4, 0),		
    OC(and_d, 1, 4, 0),		
    OC(and_e, 1, 4, 0),		
    OC(and_h, 1, 4, 0),		
    OC(and_l, 1, 4, 0),		
    OC(and_hli, 1, 7, 0),		
    OC(and_a, 1, 4, 0),		
    OC(xor_b, 1, 4, 0),		
    OC(xor_c, 1, 4, 0),		
    OC(xor_d, 1, 4, 0),		
    OC(xor_e, 1, 4, 0),		
    OC(xor_h, 1, 4, 0),		
    OC(xor_l, 1, 4, 0),		
    OC(xor_hli, 1, 7, 0),		
    OC(xor_a, 1, 4, 0),		

    // B0 - BF
    OC(or_b, 1, 4, 0),		
    OC(or_c, 1, 4, 0),		
    OC(or_d, 1, 4, 0),		
    OC(or_e, 1, 4, 0),		
    OC(or_h, 1, 4, 0),		
    OC(or_l, 1, 4, 0),		
    OC(or_hli, 1, 7, 0),		
    OC(or_a, 1, 4, 0),		
    OC(cp_b, 1, 4, 0),		
    OC(cp_c, 1, 4, 0),		
    OC(cp_d, 1, 4, 0),		
    OC(cp_e, 1, 4, 0),		
    OC(cp_h, 1, 4, 0),		
    OC(cp_l, 1, 4, 0),		
    OC(cp_hli, 1, 7, 0),		
    OC(cp_a, 1, 4, 0),		

    // C0 - CF
    OC_CC(ret_nz, 1, 11, 5),		
    OC(pop_bc, 1, 10, 0),		
    OC(jp_nz_nn, 3, 10, 0),		
    OC(jp_nn, 3, 10, 0),		
    OC_CC(call_nz_nn, 3, 17, 10),		
    OC(push_bc, 1, 11, 0),		
    OC(add_a_n, 2, 7, 0),		
    OC(rst_00h, 1, 11, 0),		
    OC_CC(ret_z, 1, 11, 5),		
    OC(ret, 1, 10, 0),		
    OC(jp_z_nn, 3, 10, 0),		
    OC_LITE(not_imp),		
    OC_CC(call_z_nn, 3, 17, 10),		
    OC(call_nn, 3, 17, 0),		
    OC(adc_a_n, 2, 7, 0),		
    OC(rst_08h, 1, 11, 0),		

    // D0 - DF
    OC_CC(ret_nc, 1, 11, 5),		
    OC(pop_de, 1, 10, 0),		
    OC(jp_nc_nn, 3, 10, 0),		
    OC(out_ni_a, 2, 11, 0),		
    OC_CC(call_nc_nn, 3, 17, 10),		
    OC(push_de, 1, 11, 0),		
    OC(sub_n, 2, 7, 0),		
    OC(rst_10h, 1, 11, 0),		
    OC_CC(ret_c, 1, 11, 5),		
    OC(exx, 1, 4, 0),		
    OC(jp_c_nn, 3, 10, 0),		
    OC(in_a_ni, 2, 11, 0),		
    OC_CC(call_c_nn, 3, 17, 10),		
    OC_LITE(not_imp),		
    OC(sbc_a_n, 2, 7, 0),		
    OC(rst_18h, 1, 11, 0),	

    // E0 - EF
    OC_CC(ret_po, 1, 11, 5),		
    OC(pop_hl, 1, 10, 0),		
    OC(jp_po_nn, 3, 10, 0),		
    OC(ex_spi_hl, 1, 19, 0),		
    OC_CC(call_po_nn, 3, 17, 10),		
    OC(push_hl, 1, 11, 0),		
    OC(and_n, 2, 7, 0),		
    OC(rst_20h, 1, 11, 0),		
    OC_CC(ret_pe, 1, 11, 5),		
    OC(jp_hli, 1, 4, 0),		
    OC(jp_pe_nn, 3, 10, 0),		
    OC(ex_de_hl, 1, 4, 0),		
    OC_CC(call_pe_nn, 3, 17, 10),		
    OC_LITE(not_imp),		
    OC(xor_n, 2, 7, 0),		
    OC(rst_28h, 1, 11, 0),	

    // F0 - FF
    OC_CC(ret_p, 1, 11, 5),		
    OC(pop_af, 1, 10, 0),		
    OC(jp_p_nn, 3, 10, 0),		
    OC(di, 1, 4, 0),		
    OC_CC(call_p_nn, 3, 17, 10),		
    OC(push_af, 1, 11, 0),		
    OC(or_n, 2, 7, 0),		
    OC(rst_30h, 1, 11, 0),		
    OC_CC(ret_m, 1, 11, 5),		
    OC(ld_sp_hl, 1, 6, 0),		
    OC(jp_m_nn, 3, 10, 0),		
    OC(ei, 1, 4, 0),		
    OC_CC(call_m_nn, 3, 17, 10),		
    OC_LITE(not_imp),		
    OC(cp_n, 2, 7, 0),		
    OC(rst_38h, 1, 11, 0)
};

void nop() {
}

void ld_bc_nn() {
    z80.c = memReadFunc(z80.pc - 2);
    z80.b = memReadFunc(z80.pc - 1);   
}

void ld_bci_a() {
    memWriteFunc(z80.bc, z80.a);
}

void inc_bc() {
    z80.bc++;
}

void inc_b() {
    executeInc(&z80.b);
}

void dec_b() {
    executeDec(&z80.b);
}

void ld_b_n() {
    z80.b = memReadFunc(z80.pc - 1);  
}

void rlca() {
    z80.flags.n = 0;
    z80.flags.h = 0;
    z80.flags.c = z80.a >> 7;
    z80.a = z80.a << 1 | z80.flags.c;
}

void ex_af_af2() {
    uint16_t temp = z80.af;
    z80.af = z80.af2;
    z80.af2 = temp;
}

void add_hl_bc() {
    execute16BitAdd(z80.bc, &z80.hl, false);
}

void ld_a_bci() {
    z80.a = memReadFunc(z80.bc);
}

void dec_bc() {
    z80.bc--;
}

void inc_c() {
    executeInc(&z80.c);
}

void dec_c() {
    executeDec(&z80.c);
}

void ld_c_n() {
    z80.c = memReadFunc(z80.pc - 1);
}

void rrca() {
    z80.flags.n = 0;
    z80.flags.h = 0;
    z80.flags.c = z80.a & 0x01;
    z80.a = z80.a >> 1 | z80.flags.c << 7;
}

// 10 - 1F

bool djnz_d() {
    return executeConditionalRelativeJump(--z80.b);
}

void ld_de_nn() {
    z80.e = memReadFunc(z80.pc - 2);
    z80.d = memReadFunc(z80.pc - 1);   
}

void ld_dei_a() {
    memWriteFunc(z80.de, z80.a);    
}

void inc_de() {
    z80.de++;
}

void inc_d() {
    executeInc(&z80.d);    
}

void dec_d() {
    executeDec(&z80.d);    
}

void ld_d_n() {
    z80.d = memReadFunc(z80.pc - 1);
}

void rla() {
    z80.flags.n = 0;
    z80.flags.h = 0;
    uint8_t oldCFlag = z80.flags.c;
    z80.flags.c = z80.a >> 7;
    z80.a = z80.a << 1 | oldCFlag;    
}

void jr_d() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.pc += d;
}

void add_hl_de() {
    execute16BitAdd(z80.de, &z80.hl, false);    
}

void ld_a_dei() {
    z80.a = memReadFunc(z80.de);
}

void dec_de() {
    z80.de--;
}

void inc_e() {
    executeInc(&z80.e);    
}

void dec_e() {
    executeDec(&z80.e);    
}

void ld_e_n() {
    z80.e = memReadFunc(z80.pc - 1);
}

void rra() {
    z80.flags.n = 0;
    z80.flags.h = 0;
    uint8_t oldCFlag = z80.flags.c;
    z80.flags.c = z80.a & 0x01;
    z80.a = z80.a >> 1 | oldCFlag << 7;       
}

// 20 - 2F

bool jr_nz_d() {
    return executeConditionalRelativeJump(!z80.flags.z);
}

void ld_hl_nn() {
    z80.l = memReadFunc(z80.pc - 2);
    z80.h = memReadFunc(z80.pc - 1);   
}

void ld_nni_hl() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    memWriteFunc(address, z80.l);
    memWriteFunc(address + 1, z80.h);
}

void inc_hl() {
    z80.hl++;
}

void inc_h() {
    executeInc(&z80.h);    
}

void dec_h() {
    executeDec(&z80.h);    
}

void ld_h_n() {
    z80.h = memReadFunc(z80.pc - 1);    
}

void daa() {
    // "When this instruction is executed, the A register is BCD corrected
    // using the  contents of the flags. The exact process is the following:
    // if the least significant four bits of A contain a non-BCD digit
    // (i. e. it is greater than 9) or the H flag is set, then $06 is
    // added to the register. Then the four most significant bits are
    // checked. If this more significant digit also happens to be greater
    // than 9 or the C flag is set, then $60 is added."
    // > http://z80-heaven.wikidot.com/instructions-set:daa
    uint8_t correction = 0;

    if ((z80.a & 0x0F) > 0x09 || z80.flags.h) {
        correction += 0x06;
    }

    if (z80.a > 0x99 || z80.flags.c) {
        correction += 0x60;
        z80.flags.c = 1;
    }

    const bool substraction = z80.flags.n;
    if (substraction) {
        z80.flags.h = z80.flags.h && (z80.a & 0x0F) < 0x06;
        z80.a -= correction;
    } else {
        z80.flags.h = (z80.a & 0x0F) > 0x09;
        z80.a += correction;
    }

    z80.flags.s = z80.a >> 7;
    z80.flags.z = z80.a == 0;
    z80.flags.pv = getParity(z80.a);
    // z80.flags.x = GET_BIT(3, z80.a);
    // z80.flags.y = GET_BIT(5, z80.a); 
}

bool jr_z_d() {
    return executeConditionalRelativeJump(z80.flags.z);
}

void add_hl_hl() {
    execute16BitAdd(z80.hl, &z80.hl, false);    
}

void ld_hl_nni() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    z80.l = memReadFunc(address);
    z80.h = memReadFunc(address + 1);
}

void dec_hl() {
    z80.hl--;
}

void inc_l() {
    executeInc(&z80.l);    
}

void dec_l() {
    executeDec(&z80.l);    
}

void ld_l_n() {
    z80.l = memReadFunc(z80.pc - 1);
}

void cpl() {
    z80.flags.n = 1;
    z80.flags.h = 1;
    z80.a = ~z80.a;
}

// 30 - 3F

bool jr_nc_d() {
    return executeConditionalRelativeJump(!z80.flags.c);
}

void ld_sp_nn() {
    z80.sp = memReadFunc(z80.pc - 2);
    z80.sp += memReadFunc(z80.pc - 1) << 8;   
}

void ld_nni_a() {
    uint16_t address = memReadFunc(z80.pc - 2);
    address += memReadFunc(z80.pc - 1) << 8;
    memWriteFunc(address, z80.a);
}

void inc_sp() {
    z80.sp++;
}

void inc_hli() {
    uint8_t n = memReadFunc(z80.hl);
    executeInc(&n);
    memWriteFunc(z80.hl, n);
}

void dec_hli() {
    uint8_t n = memReadFunc(z80.hl);
    executeDec(&n);
    memWriteFunc(z80.hl, n);
}

void ld_hli_n() {
    uint8_t n = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.hl, n);    
}

void scf() {
    z80.flags.c = 1;
    z80.flags.n = 0;
    z80.flags.h = 0;
}

bool jr_c_d() {
    return executeConditionalRelativeJump(z80.flags.c);
}

void add_hl_sp() {
    execute16BitAdd(z80.sp, &z80.hl, false);    
}

void ld_a_nni() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    z80.a = memReadFunc(address);
}

void dec_sp() {
    z80.sp--;
}

void inc_a() {
    executeInc(&z80.a);    
}

void dec_a() {
    executeDec(&z80.a);    
}

void ld_a_n() {
    z80.a = memReadFunc(z80.pc - 1);    
}

void ccf() {
    z80.flags.h = z80.flags.c; 
    z80.flags.c = ~z80.flags.c;
    z80.flags.n = 0;
}

// 40 - 4F

void ld_b_b() {
    z80.b = z80.b;    
}

void ld_b_c() {
    z80.b = z80.c;    
}

void ld_b_d() {
    z80.b = z80.d;        
}

void ld_b_e() {
    z80.b = z80.e;    
}

void ld_b_h() {
    z80.b = z80.h;    
}

void ld_b_l() {
    z80.b = z80.l;    
}

void ld_b_hli() {
    z80.b = memReadFunc(z80.hl);
}

void ld_b_a() {
    z80.b = z80.a;    
}

void ld_c_b() {
    z80.c = z80.b;    
}

void ld_c_c() {
    z80.c = z80.c;    
}

void ld_c_d() {
    z80.c = z80.d;    
}

void ld_c_e() {
    z80.c = z80.e;    
}

void ld_c_h() {
    z80.c = z80.h;    
}

void ld_c_l() {
    z80.c = z80.l;    
}

void ld_c_hli() {
    z80.c = memReadFunc(z80.hl);    
}

void ld_c_a() {
    z80.c = z80.a;    
}

// 50 - 5F

void ld_d_b() {
    z80.d = z80.b;    
}

void ld_d_c() {
    z80.d = z80.c;    
}

void ld_d_d() {
    z80.d = z80.d;    
}

void ld_d_e() {
    z80.d = z80.e;    
}

void ld_d_h() {
    z80.d = z80.h;    
}

void ld_d_l() {
    z80.d = z80.l;    
}

void ld_d_hli() {
    z80.d = memReadFunc(z80.hl);    
}

void ld_d_a() {
    z80.d = z80.a;    
}

void ld_e_b() {
    z80.e = z80.b;    
}

void ld_e_c() {
    z80.e = z80.c;    
}

void ld_e_d() {
    z80.e = z80.d;    
}

void ld_e_e() {
    z80.e = z80.e;    
}

void ld_e_h() {
    z80.e = z80.h;    
}

void ld_e_l() {
    z80.e = z80.l;    
}

void ld_e_hli() {
    z80.e = memReadFunc(z80.hl);    
}

void ld_e_a() {
    z80.e = z80.a;    
}

// 60 - 6F

void ld_h_b() {
    z80.h = z80.b;    
}

void ld_h_c() {
    z80.h = z80.c;    
}

void ld_h_d() {
    z80.h = z80.d;    
}

void ld_h_e() {
    z80.h = z80.e;    
}

void ld_h_h() {
    z80.h = z80.h;    
}

void ld_h_l() {
    z80.h = z80.l;    
}

void ld_h_hli() {
    z80.h = memReadFunc(z80.hl);    
}

void ld_h_a() {
    z80.h = z80.a;    
}

void ld_l_b() {
    z80.l = z80.b;    
}

void ld_l_c() {
    z80.l = z80.c;    
}

void ld_l_d() {
    z80.l = z80.d;    
}

void ld_l_e() {
    z80.l = z80.e;    
}

void ld_l_h() {
    z80.l = z80.h;    
}

void ld_l_l() {
    z80.l = z80.l;    
}

void ld_l_hli() {
    z80.l = memReadFunc(z80.hl);    
}

void ld_l_a() {
    z80.l = z80.a;    
}

// 70 - 7F

void ld_hli_b() {
    memWriteFunc(z80.hl, z80.b);
}

void ld_hli_c() {
    memWriteFunc(z80.hl, z80.c);
}

void ld_hli_d() {
    memWriteFunc(z80.hl, z80.d);
}

void ld_hli_e() {
    memWriteFunc(z80.hl, z80.e);
}

void ld_hli_h() {
    memWriteFunc(z80.hl, z80.h);
}

void ld_hli_l() {
    memWriteFunc(z80.hl, z80.l);
}

void halt() {
    z80._halt = true;
}

void ld_hli_a() {
    memWriteFunc(z80.hl, z80.a);
}

void ld_a_b() {
    z80.a = z80.b;    
}

void ld_a_c() {
    z80.a = z80.c;    
}

void ld_a_d() {
    z80.a = z80.d;    
}

void ld_a_e() {
    z80.a = z80.e;    
}

void ld_a_h() {
    z80.a = z80.h;    
}

void ld_a_l() {
    z80.a = z80.l;    
}

void ld_a_hli() {
    z80.a = memReadFunc(z80.hl);    
}

void ld_a_a() {
    z80.a = z80.a;    
}

// 80 - 8F

void add_a_b() {
    execute8BitAdd(z80.b, 0);    
}

void add_a_c() {
    execute8BitAdd(z80.c, 0);        
}

void add_a_d() {
    execute8BitAdd(z80.d, 0);
}

void add_a_e() {
    execute8BitAdd(z80.e, 0);    
}

void add_a_h() {
    execute8BitAdd(z80.h, 0);    
}

void add_a_l() {
    execute8BitAdd(z80.l, 0);    
}

void add_a_hli() {
    execute8BitAdd(memReadFunc(z80.hl), 0);    
}

void add_a_a() {
    execute8BitAdd(z80.a, 0);    
}

void adc_a_b() {
    execute8BitAdd(z80.b, z80.flags.c);
}

void adc_a_c() {
    execute8BitAdd(z80.c, z80.flags.c);    
}

void adc_a_d() {
    execute8BitAdd(z80.d, z80.flags.c);    
}

void adc_a_e() {
    execute8BitAdd(z80.e, z80.flags.c);    
}

void adc_a_h() {
    execute8BitAdd(z80.h, z80.flags.c);    
}

void adc_a_l() {
    execute8BitAdd(z80.l, z80.flags.c);    
}

void adc_a_hli() {
    execute8BitAdd(memReadFunc(z80.hl), z80.flags.c);    
}

void adc_a_a() {
    execute8BitAdd(z80.a, z80.flags.c);    
}

// 90 - 9F

void sub_b() {
    execute8BitSub(z80.b, 0, 1);
}

void sub_c() {
    execute8BitSub(z80.c, 0, 1);    
}

void sub_d() {
    execute8BitSub(z80.d, 0, 1);    
}

void sub_e() {
    execute8BitSub(z80.e, 0, 1);    
}

void sub_h() {
    execute8BitSub(z80.h, 0, 1);    
}

void sub_l() {
    execute8BitSub(z80.l, 0, 1);    
}

void sub_hli() {
    execute8BitSub(memReadFunc(z80.hl), 0, 1);    
}

void sub_a() {
    execute8BitSub(z80.a, 0, 1);    
}

void sbc_a_b() {
    execute8BitSub(z80.b, z80.flags.c, 1);    
}

void sbc_a_c() {
    execute8BitSub(z80.c, z80.flags.c, 1);        
}

void sbc_a_d() {
    execute8BitSub(z80.d, z80.flags.c, 1);    
}

void sbc_a_e() {
    execute8BitSub(z80.e, z80.flags.c, 1);    
}

void sbc_a_h() {
    execute8BitSub(z80.h, z80.flags.c, 1);    
}

void sbc_a_l() {
    execute8BitSub(z80.l, z80.flags.c, 1);    
}

void sbc_a_hli() {
    execute8BitSub(memReadFunc(z80.hl), z80.flags.c, 1);    
}

void sbc_a_a() {
    execute8BitSub(z80.a, z80.flags.c, 1);    
}

// A0 - AF

void and_b() {
    executeLogical(z80.b, AND);
}

void and_c() {
    executeLogical(z80.c, AND);    
}

void and_d() {
    executeLogical(z80.d, AND);    
}

void and_e() {
    executeLogical(z80.e, AND);    
}

void and_h() {
    executeLogical(z80.h, AND);    
}

void and_l() {
    executeLogical(z80.l, AND);    
}

void and_hli() {
    executeLogical(memReadFunc(z80.hl), AND);
}

void and_a() {
    executeLogical(z80.a, AND);    
}

void xor_b() {
    executeLogical(z80.b, XOR);    
}

void xor_c() {
    executeLogical(z80.c, XOR);    
}

void xor_d() {
    executeLogical(z80.d, XOR);    
}

void xor_e() {
    executeLogical(z80.e, XOR);    
}

void xor_h() {
    executeLogical(z80.h, XOR);    
}

void xor_l() {
    executeLogical(z80.l, XOR);    
}

void xor_hli() {
    executeLogical(memReadFunc(z80.hl), XOR);    
}

void xor_a() {
    executeLogical(z80.a, XOR);    
}

// B0 - BF

void or_b() {
    executeLogical(z80.b, OR);    
}

void or_c() {
    executeLogical(z80.c, OR);    
}

void or_d() {
    executeLogical(z80.d, OR);    
}

void or_e() {
    executeLogical(z80.e, OR);    
}

void or_h() {
    executeLogical(z80.h, OR);    
}

void or_l() {
    executeLogical(z80.l, OR);    
}

void or_hli() {
    executeLogical(memReadFunc(z80.hl), OR);    
}

void or_a() {
    executeLogical(z80.a, OR);    
}

void cp_b() {
    execute8BitSub(z80.b, 0, 0);
}

void cp_c() {
    execute8BitSub(z80.c, 0, 0);    
}

void cp_d() {
    execute8BitSub(z80.d, 0, 0);    
}

void cp_e() {
    execute8BitSub(z80.e, 0, 0);    
}

void cp_h() {
    execute8BitSub(z80.h, 0, 0);    
}

void cp_l() {
    execute8BitSub(z80.l, 0, 0);    
}

void cp_hli() {
    execute8BitSub(memReadFunc(z80.hl), 0, 0);    
}

void cp_a() {
    execute8BitSub(z80.a, 0, 0);    
}

// C0 - CF

bool ret_nz() {
    return executeConditionalReturn(!z80.flags.z);
}

void pop_bc() {
    z80.bc = pop();
}

void jp_nz_nn() {
    if (!z80.flags.z) {
        z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    }
}

void jp_nn() {
    z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);    
}

bool call_nz_nn() {
    return executeConditionalCall(!z80.flags.z);
}

void push_bc() {
    push(z80.bc);
}

void add_a_n() {
    execute8BitAdd(memReadFunc(z80.pc - 1), 0);
}

void rst_00h() {
    push(z80.pc);
    z80.pc = 0x0000;
}

bool ret_z() {
    return executeConditionalReturn(z80.flags.z);
}

void ret() {
    z80.pc = pop();    
}

void jp_z_nn() {
    if (z80.flags.z) {
        z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    }
}

bool call_z_nn() {
    return executeConditionalCall(z80.flags.z);
}

void call_nn() {  
    // calls to CP/M functions (must be replaced for ours)
    if (memReadFunc(z80.pc - 2) == 0x05 && memReadFunc(z80.pc - 1) == 0x00) {
        if (z80.c == 0x02) {
            // print a character
            printf("%c", z80.e);
        } else if (z80.c == 0x09) {
            // print a $ terminated string
            char msg[256] = "\0";
            uint16_t index = 0;
            while (memReadFunc(z80.de + index) != 0x24) {
                msg[index] = memReadFunc(z80.de + index);
                index++;
            };
            msg[index] = '\0';
            printf("%s", msg);
        }
    } else {
       push(z80.pc);
       z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);    
    }
}

void adc_a_n() {
    execute8BitAdd(memReadFunc(z80.pc - 1), z80.flags.c);
}

void rst_08h() {
    push(z80.pc);
    z80.pc = 0x0008;
}

// D0 - DF

bool ret_nc() {
    return executeConditionalReturn(!z80.flags.c);
}

void pop_de() {
    z80.de = pop();
}

void jp_nc_nn() {
    if (!z80.flags.c) {
        z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    }
}

void out_ni_a() {
    ioWriteFunc(memReadFunc(z80.pc - 1) + (z80.a << 8), z80.a);
}

bool call_nc_nn() {
    return executeConditionalCall(!z80.flags.c);
}

void push_de() {
    push(z80.de);    
}

void sub_n() {
    execute8BitSub(memReadFunc(z80.pc - 1), 0, 1);
}

void rst_10h() {
    push(z80.pc);
    z80.pc = 0x0010;    
}

bool ret_c() {
    return executeConditionalReturn(z80.flags.c);
}

void exx() {
    uint16_t aux;

    aux = z80.bc;
    z80.bc = z80.bc2;
    z80.bc2 = aux;

    aux = z80.de;
    z80.de = z80.de2;
    z80.de2 = aux;

    aux = z80.hl;
    z80.hl = z80.hl2;
    z80.hl2 = aux;
}

void jp_c_nn() {
    if (z80.flags.c) {
        z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    }
}

void in_a_ni() {
    z80.a = ioReadFunc(memReadFunc(z80.pc - 1) + (z80.a << 8));
}

bool call_c_nn() {
    return executeConditionalCall(z80.flags.c);
}

void sbc_a_n() {
    execute8BitSub(memReadFunc(z80.pc - 1) + z80.flags.c, 0, 1);    
}

void rst_18h() {
    push(z80.pc);
    z80.pc = 0x0018;    
}

// E0 - EF

bool ret_po() {
    return executeConditionalReturn(!z80.flags.pv);
}

void pop_hl() {
    z80.hl = pop();    
}

void jp_po_nn() {
    if (!z80.flags.pv) {
        z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    }
}

void ex_spi_hl() {
    uint8_t aux;

    aux = memReadFunc(z80.sp);
    memWriteFunc(z80.sp, z80.l);
    z80.l = aux;

    aux = memReadFunc(z80.sp + 1);
    memWriteFunc(z80.sp + 1, z80.h);
    z80.h = aux;
}

bool call_po_nn() {
    return executeConditionalCall(!z80.flags.pv);
}

void push_hl() {
    push(z80.hl);    
}

void and_n() {
    executeLogical(memReadFunc(z80.pc - 1), AND);
}

void rst_20h() {
    push(z80.pc);
    z80.pc = 0x0020;    
}

bool ret_pe() {
    return executeConditionalReturn(z80.flags.pv);
}

void jp_hli() {
    z80.pc = z80.hl;   
}

void jp_pe_nn() {
    if (z80.flags.pv) {
        z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    }
}

void ex_de_hl() {
    uint16_t aux;

    aux = z80.de;
    z80.de = z80.hl;
    z80.hl = aux;   
}

bool call_pe_nn() {
    return executeConditionalCall(z80.flags.pv);
}

void xor_n() {
executeLogical(memReadFunc(z80.pc - 1), XOR);    
}

void rst_28h() {
    push(z80.pc);
    z80.pc = 0x0028;    
}

// F0 - FF

bool ret_p() {
    return executeConditionalReturn(!z80.flags.s);
}

void pop_af() {
    z80.af = pop();    
}

void jp_p_nn() {
    if (!z80.flags.s) {
        z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    }
}

void di() {
    z80._iff1 = z80._iff2 = false;
}

bool call_p_nn() {
    return executeConditionalCall(!z80.flags.s);
}

void push_af() {
    push(z80.af);    
}

void or_n() {
    executeLogical(memReadFunc(z80.pc - 1), OR);    
}

void rst_30h() {
    push(z80.pc);
    z80.pc = 0x0030;    
}

bool ret_m() {
    return executeConditionalReturn(z80.flags.s);
}

void ld_sp_hl() {
    z80.sp = z80.hl;
}

void jp_m_nn() {
    if (z80.flags.s) {
        z80.pc = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    }
}

void ei() {
    z80._iff1 = z80._iff2 = true;
}

bool call_m_nn() {
    return executeConditionalCall(z80.flags.s);
}

void cp_n() {
    execute8BitSub(memReadFunc(z80.pc - 1), 0, 0);
}

void rst_38h() {
    push(z80.pc);
    z80.pc = 0x0038;
}
