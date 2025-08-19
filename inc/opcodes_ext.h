/*
 * opcodes_ext.h - Extended Instructions Interface
 *
 * Declares the opcode table and function prototypes for 0xED-prefixed instructions.
 */

#ifndef OPCODES_EXT_H
#define OPCODES_EXT_H

#include "opcodes.h"

    /* ================================================================ */
    /*                    EXT INSTRUCTIONS (0xED)                       */
    /* ================================================================ */

extern Opcode extOpcodePtrs[256];

void sbc_hl_bc();
void ld_nni_bc();
void neg();
void im_0();
void ld_i_a();
void adc_hl_bc();
void ld_bc_nni();
void reti();
void ld_r_a();
void sbc_hl_de();
void ld_nni_de();
void im_1();
void adc_hl_de();
void ld_de_nni();
void im_2();
void ld_a_r();
void sbc_hl_hl();
void rrd();
void adc_hl_hl();
void rld();
void sbc_hl_sp();
void ld_nni_sp();
void adc_hl_sp();
void ld_sp_nni();
void ldi();
void cpi();
void ldd();
void cpd();
bool ldir();
bool cpir();
bool lddr();
bool cpdr();

void in_b_ci();
void in_c_ci();
void in_d_ci();
void in_e_ci();
void in_h_ci();
void in_l_ci();
void in_a_ci();

void out_ci_b();
void out_ci_c();
void out_ci_d();
void out_ci_e();
void out_ci_h();
void out_ci_l();
void out_ci_a();

#endif