/*
 * opcodes_ix.h - IX Register Instructions Interface
 *
 * Declares the opcode tables and function prototypes for 0xDD-prefixed IX operations.
 */

#ifndef OPCODES_IX_H
#define OPCODES_IX_H

#include "opcodes.h"

    /* ================================================================ */
    /*                      IX INSTRUCTIONS (0xDD)                      */
    /* ================================================================ */

extern Opcode ixOpcodePtrs[256];
extern Opcode ixBitOpcodePtrs[256];

void inc_b();
void dec_b();
void ld_b_n();
void add_ix_bc();
void inc_c();
void dec_c();
void ld_c_n();
void inc_d();
void dec_d();
void ld_d_n();
void add_ix_de();
void inc_e();
void dec_e();
void ld_e_n();
void ld_ix_nn();
void ld_nni_ix();
void inc_ix();
void inc_ixh();
void dec_ixh();
void ld_ixh_n();
void add_ix_ix();
void ld_ix_nni();
void dec_ix();
void inc_ixl();
void dec_ixl();
void ld_ixl_n();
void inc_ixd();
void dec_ixd();
void ld_ixd_n();
void add_ix_sp();
void inc_a();
void dec_a();
void ld_a_n();
void ld_b_b();
void ld_b_c();
void ld_b_d();
void ld_b_e();
void ld_b_ixh();
void ld_b_ixl();
void ld_b_ixd();
void ld_b_a();
void ld_c_b();
void ld_c_c();
void ld_c_d();
void ld_c_e();
void ld_c_ixh();
void ld_c_ixl();
void ld_c_ixd();
void ld_c_a();
void ld_d_b();
void ld_d_c();
void ld_d_d();
void ld_d_e();
void ld_d_ixh();
void ld_d_ixl();
void ld_d_ixd();
void ld_d_a();
void ld_e_b();
void ld_e_c();
void ld_e_d();
void ld_e_e();
void ld_e_ixh();
void ld_e_ixl();
void ld_e_ixd();
void ld_e_a();
void ld_ixh_b();
void ld_ixh_c();
void ld_ixh_d();
void ld_ixh_e();
void ld_ixh_ixh();
void ld_ixh_ixl();
void ld_h_ixd();
void ld_ixh_a();
void ld_ixl_b();
void ld_ixl_c();
void ld_ixl_d();
void ld_ixl_e();
void ld_ixl_ixh();
void ld_ixl_ixl();
void ld_l_ixd();
void ld_ixl_a();
void ld_ixd_b();
void ld_ixd_c();
void ld_ixd_d();
void ld_ixd_e();
void ld_ixd_h();
void ld_ixd_l();
void ld_ixd_a();
void ld_a_b();
void ld_a_c();
void ld_a_d();
void ld_a_e();
void ld_a_ixh();
void ld_a_ixl();
void ld_a_ixd();
void ld_a_a();
void add_a_b();
void add_a_c();
void add_a_d();
void add_a_e();
void add_a_ixh();
void add_a_ixl();
void add_a_ixd();
void add_a_a();
void adc_a_b();
void adc_a_c();
void adc_a_d();
void adc_a_e();
void adc_a_ixh();
void adc_a_ixl();
void adc_a_ixd();
void adc_a_a();
void sub_b();
void sub_c();
void sub_d();
void sub_e();
void sub_ixh();
void sub_ixl();
void sub_ixd();
void sub_a();
void sbc_a_b();
void sbc_a_c();
void sbc_a_d();
void sbc_a_e();
void sbc_a_ixh();
void sbc_a_ixl();
void sbc_a_ixd();
void sbc_a_a();
void and_b();
void and_c();
void and_d();
void and_e();
void and_ixh();
void and_ixl();
void and_ixd();
void and_a();
void xor_b();
void xor_c();
void xor_d();
void xor_e();
void xor_ixh();
void xor_ixl();
void xor_ixd();
void xor_a();
void or_b();
void or_c();
void or_d();
void or_e();
void or_ixh();
void or_ixl();
void or_ixd();
void or_a();
void cp_b();
void cp_c();
void cp_d();
void cp_e();
void cp_ixh();
void cp_ixl();
void cp_ixd();
void cp_a();
void pop_ix();
void push_ix();
void jp_ix();
void ld_sp_ix();

    /* ================================================================ */
    /*                   IX BIT INSTRUCTIONS (0xDDCB)                   */
    /* ================================================================ */

// 00 - 0F
void rlc_ixd_b();
void rlc_ixd_c();
void rlc_ixd_d();
void rlc_ixd_e();
void rlc_ixd_h();
void rlc_ixd_l();
void rlc_ixd();
void rlc_ixd_a();
void rrc_ixd_b();
void rrc_ixd_c();
void rrc_ixd_d();
void rrc_ixd_e();
void rrc_ixd_h();
void rrc_ixd_l();
void rrc_ixd();
void rrc_ixd_a();

// 10 - 1F
void rl_ixd_b();
void rl_ixd_c();
void rl_ixd_d();
void rl_ixd_e();
void rl_ixd_h();
void rl_ixd_l();
void rl_ixd();
void rl_ixd_a();
void rr_ixd_b();
void rr_ixd_c();
void rr_ixd_d();
void rr_ixd_e();
void rr_ixd_h();
void rr_ixd_l();
void rr_ixd();
void rr_ixd_a();

// 20 - 2F
void sla_ixd_b();
void sla_ixd_c();
void sla_ixd_d();
void sla_ixd_e();
void sla_ixd_h();
void sla_ixd_l();
void sla_ixd();
void sla_ixd_a();
void sra_ixd_b();
void sra_ixd_c();
void sra_ixd_d();
void sra_ixd_e();
void sra_ixd_h();
void sra_ixd_l();
void sra_ixd();
void sra_ixd_a();

// 30 - 3F
void sll_ixd_b();
void sll_ixd_c();
void sll_ixd_d();
void sll_ixd_e();
void sll_ixd_h();
void sll_ixd_l();
void sll_ixd();
void sll_ixd_a();
void srl_ixd_b();
void srl_ixd_c();
void srl_ixd_d();
void srl_ixd_e();
void srl_ixd_h();
void srl_ixd_l();
void srl_ixd();
void srl_ixd_a();

// 40 - 7F
void bit_0_ixd();
void bit_1_ixd();
void bit_2_ixd();
void bit_3_ixd();
void bit_4_ixd();
void bit_5_ixd();
void bit_6_ixd();
void bit_7_ixd();

// 80 - 8F
void res_0_ixd_b();
void res_0_ixd_c();
void res_0_ixd_d();
void res_0_ixd_e();
void res_0_ixd_h();
void res_0_ixd_l();
void res_0_ixd();
void res_0_ixd_a();
void res_1_ixd_b();
void res_1_ixd_c();
void res_1_ixd_d();
void res_1_ixd_e();
void res_1_ixd_h();
void res_1_ixd_l();
void res_1_ixd();
void res_1_ixd_a();

// 90 - 9F
void res_2_ixd_b();
void res_2_ixd_c();
void res_2_ixd_d();
void res_2_ixd_e();
void res_2_ixd_h();
void res_2_ixd_l();
void res_2_ixd();
void res_2_ixd_a();
void res_3_ixd_b();
void res_3_ixd_c();
void res_3_ixd_d();
void res_3_ixd_e();
void res_3_ixd_h();
void res_3_ixd_l();
void res_3_ixd();
void res_3_ixd_a();

// A0 - AF
void res_4_ixd_b();
void res_4_ixd_c();
void res_4_ixd_d();
void res_4_ixd_e();
void res_4_ixd_h();
void res_4_ixd_l();
void res_4_ixd();
void res_4_ixd_a();
void res_5_ixd_b();
void res_5_ixd_c();
void res_5_ixd_d();
void res_5_ixd_e();
void res_5_ixd_h();
void res_5_ixd_l();
void res_5_ixd();
void res_5_ixd_a();

// B0 - BF
void res_6_ixd_b();
void res_6_ixd_c();
void res_6_ixd_d();
void res_6_ixd_e();
void res_6_ixd_h();
void res_6_ixd_l();
void res_6_ixd();
void res_6_ixd_a();
void res_7_ixd_b();
void res_7_ixd_c();
void res_7_ixd_d();
void res_7_ixd_e();
void res_7_ixd_h();
void res_7_ixd_l();
void res_7_ixd();
void res_7_ixd_a();

// C0 - CF
void set_0_ixd_b();
void set_0_ixd_c();
void set_0_ixd_d();
void set_0_ixd_e();
void set_0_ixd_h();
void set_0_ixd_l();
void set_0_ixd();
void set_0_ixd_a();
void set_1_ixd_b();
void set_1_ixd_c();
void set_1_ixd_d();
void set_1_ixd_e();
void set_1_ixd_h();
void set_1_ixd_l();
void set_1_ixd();
void set_1_ixd_a();

// D0 - DF
void set_2_ixd_b();
void set_2_ixd_c();
void set_2_ixd_d();
void set_2_ixd_e();
void set_2_ixd_h();
void set_2_ixd_l();
void set_2_ixd();
void set_2_ixd_a();
void set_3_ixd_b();
void set_3_ixd_c();
void set_3_ixd_d();
void set_3_ixd_e();
void set_3_ixd_h();
void set_3_ixd_l();
void set_3_ixd();
void set_3_ixd_a();

// E0 - EF
void set_4_ixd_b();
void set_4_ixd_c();
void set_4_ixd_d();
void set_4_ixd_e();
void set_4_ixd_h();
void set_4_ixd_l();
void set_4_ixd();
void set_4_ixd_a();
void set_5_ixd_b();
void set_5_ixd_c();
void set_5_ixd_d();
void set_5_ixd_e();
void set_5_ixd_h();
void set_5_ixd_l();
void set_5_ixd();
void set_5_ixd_a();

// F0 - FF
void set_6_ixd_b();
void set_6_ixd_c();
void set_6_ixd_d();
void set_6_ixd_e();
void set_6_ixd_h();
void set_6_ixd_l();
void set_6_ixd();
void set_6_ixd_a();
void set_7_ixd_b();
void set_7_ixd_c();
void set_7_ixd_d();
void set_7_ixd_e();
void set_7_ixd_h();
void set_7_ixd_l();
void set_7_ixd();
void set_7_ixd_a();

#endif