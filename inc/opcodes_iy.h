/*
 * opcodes_iy.h - IY Register Instructions Interface
 *
 * Declares the opcode tables and function prototypes for 0xFD-prefixed IY operations.
 */

#ifndef OPCODES_IY_H
#define OPCODES_IY_H

#include "opcodes.h"

    /* ================================================================ */
    /*                      IY INSTRUCTIONS (0xFD)                      */
    /* ================================================================ */

extern Opcode iyOpcodePtrs[256];
extern Opcode iyBitOpcodePtrs[256];

void inc_b();
void dec_b();
void ld_b_n();
void add_iy_bc();
void inc_c();
void dec_c();
void ld_c_n();
void inc_d();
void dec_d();
void ld_d_n();
void add_iy_de();
void inc_e();
void dec_e();
void ld_e_n();
void ld_iy_nn();
void ld_nni_iy();
void inc_iy();
void inc_iyh();
void dec_iyh();
void ld_iyh_n();
void add_iy_iy();
void ld_iy_nni();
void dec_iy();
void inc_iyl();
void dec_iyl();
void ld_iyl_n();
void inc_iyd();
void dec_iyd();
void ld_iyd_n();
void add_iy_sp();
void inc_a();
void dec_a();
void ld_a_n();
void ld_b_b();
void ld_b_c();
void ld_b_d();
void ld_b_e();
void ld_b_iyh();
void ld_b_iyl();
void ld_b_iyd();
void ld_b_a();
void ld_c_b();
void ld_c_c();
void ld_c_d();
void ld_c_e();
void ld_c_iyh();
void ld_c_iyl();
void ld_c_iyd();
void ld_c_a();
void ld_d_b();
void ld_d_c();
void ld_d_d();
void ld_d_e();
void ld_d_iyh();
void ld_d_iyl();
void ld_d_iyd();
void ld_d_a();
void ld_e_b();
void ld_e_c();
void ld_e_d();
void ld_e_e();
void ld_e_iyh();
void ld_e_iyl();
void ld_e_iyd();
void ld_e_a();
void ld_iyh_b();
void ld_iyh_c();
void ld_iyh_d();
void ld_iyh_e();
void ld_iyh_iyh();
void ld_iyh_iyl();
void ld_h_iyd();
void ld_iyh_a();
void ld_iyl_b();
void ld_iyl_c();
void ld_iyl_d();
void ld_iyl_e();
void ld_iyl_iyh();
void ld_iyl_iyl();
void ld_l_iyd();
void ld_iyl_a();
void ld_iyd_b();
void ld_iyd_c();
void ld_iyd_d();
void ld_iyd_e();
void ld_iyd_h();
void ld_iyd_l();
void ld_iyd_a();
void ld_a_b();
void ld_a_c();
void ld_a_d();
void ld_a_e();
void ld_a_iyh();
void ld_a_iyl();
void ld_a_iyd();
void ld_a_a();
void add_a_b();
void add_a_c();
void add_a_d();
void add_a_e();
void add_a_iyh();
void add_a_iyl();
void add_a_iyd();
void add_a_a();
void adc_a_b();
void adc_a_c();
void adc_a_d();
void adc_a_e();
void adc_a_iyh();
void adc_a_iyl();
void adc_a_iyd();
void adc_a_a();
void sub_b();
void sub_c();
void sub_d();
void sub_e();
void sub_iyh();
void sub_iyl();
void sub_iyd();
void sub_a();
void sbc_a_b();
void sbc_a_c();
void sbc_a_d();
void sbc_a_e();
void sbc_a_iyh();
void sbc_a_iyl();
void sbc_a_iyd();
void sbc_a_a();
void and_b();
void and_c();
void and_d();
void and_e();
void and_iyh();
void and_iyl();
void and_iyd();
void and_a();
void xor_b();
void xor_c();
void xor_d();
void xor_e();
void xor_iyh();
void xor_iyl();
void xor_iyd();
void xor_a();
void or_b();
void or_c();
void or_d();
void or_e();
void or_iyh();
void or_iyl();
void or_iyd();
void or_a();
void cp_b();
void cp_c();
void cp_d();
void cp_e();
void cp_iyh();
void cp_iyl();
void cp_iyd();
void cp_a();
void pop_iy();
void push_iy();
void jp_iy();
void ld_sp_iy();

    /* ================================================================ */
    /*                   IY BIT INSTRUCTIONS (0xFDCB)                   */
    /* ================================================================ */

// 00 - 0F
void rlc_iyd_b();
void rlc_iyd_c();
void rlc_iyd_d();
void rlc_iyd_e();
void rlc_iyd_h();
void rlc_iyd_l();
void rlc_iyd();
void rlc_iyd_a();
void rrc_iyd_b();
void rrc_iyd_c();
void rrc_iyd_d();
void rrc_iyd_e();
void rrc_iyd_h();
void rrc_iyd_l();
void rrc_iyd();
void rrc_iyd_a();

// 10 - 1F
void rl_iyd_b();
void rl_iyd_c();
void rl_iyd_d();
void rl_iyd_e();
void rl_iyd_h();
void rl_iyd_l();
void rl_iyd();
void rl_iyd_a();
void rr_iyd_b();
void rr_iyd_c();
void rr_iyd_d();
void rr_iyd_e();
void rr_iyd_h();
void rr_iyd_l();
void rr_iyd();
void rr_iyd_a();

// 20 - 2F
void sla_iyd_b();
void sla_iyd_c();
void sla_iyd_d();
void sla_iyd_e();
void sla_iyd_h();
void sla_iyd_l();
void sla_iyd();
void sla_iyd_a();
void sra_iyd_b();
void sra_iyd_c();
void sra_iyd_d();
void sra_iyd_e();
void sra_iyd_h();
void sra_iyd_l();
void sra_iyd();
void sra_iyd_a();

// 30 - 3F
void sll_iyd_b();
void sll_iyd_c();
void sll_iyd_d();
void sll_iyd_e();
void sll_iyd_h();
void sll_iyd_l();
void sll_iyd();
void sll_iyd_a();
void srl_iyd_b();
void srl_iyd_c();
void srl_iyd_d();
void srl_iyd_e();
void srl_iyd_h();
void srl_iyd_l();
void srl_iyd();
void srl_iyd_a();

// 40 - 7F
void bit_0_iyd();
void bit_1_iyd();
void bit_2_iyd();
void bit_3_iyd();
void bit_4_iyd();
void bit_5_iyd();
void bit_6_iyd();
void bit_7_iyd();

// 80 - 8F
void res_0_iyd_b();
void res_0_iyd_c();
void res_0_iyd_d();
void res_0_iyd_e();
void res_0_iyd_h();
void res_0_iyd_l();
void res_0_iyd();
void res_0_iyd_a();
void res_1_iyd_b();
void res_1_iyd_c();
void res_1_iyd_d();
void res_1_iyd_e();
void res_1_iyd_h();
void res_1_iyd_l();
void res_1_iyd();
void res_1_iyd_a();

// 90 - 9F
void res_2_iyd_b();
void res_2_iyd_c();
void res_2_iyd_d();
void res_2_iyd_e();
void res_2_iyd_h();
void res_2_iyd_l();
void res_2_iyd();
void res_2_iyd_a();
void res_3_iyd_b();
void res_3_iyd_c();
void res_3_iyd_d();
void res_3_iyd_e();
void res_3_iyd_h();
void res_3_iyd_l();
void res_3_iyd();
void res_3_iyd_a();

// A0 - AF
void res_4_iyd_b();
void res_4_iyd_c();
void res_4_iyd_d();
void res_4_iyd_e();
void res_4_iyd_h();
void res_4_iyd_l();
void res_4_iyd();
void res_4_iyd_a();
void res_5_iyd_b();
void res_5_iyd_c();
void res_5_iyd_d();
void res_5_iyd_e();
void res_5_iyd_h();
void res_5_iyd_l();
void res_5_iyd();
void res_5_iyd_a();

// B0 - BF
void res_6_iyd_b();
void res_6_iyd_c();
void res_6_iyd_d();
void res_6_iyd_e();
void res_6_iyd_h();
void res_6_iyd_l();
void res_6_iyd();
void res_6_iyd_a();
void res_7_iyd_b();
void res_7_iyd_c();
void res_7_iyd_d();
void res_7_iyd_e();
void res_7_iyd_h();
void res_7_iyd_l();
void res_7_iyd();
void res_7_iyd_a();

// C0 - CF
void set_0_iyd_b();
void set_0_iyd_c();
void set_0_iyd_d();
void set_0_iyd_e();
void set_0_iyd_h();
void set_0_iyd_l();
void set_0_iyd();
void set_0_iyd_a();
void set_1_iyd_b();
void set_1_iyd_c();
void set_1_iyd_d();
void set_1_iyd_e();
void set_1_iyd_h();
void set_1_iyd_l();
void set_1_iyd();
void set_1_iyd_a();

// D0 - DF
void set_2_iyd_b();
void set_2_iyd_c();
void set_2_iyd_d();
void set_2_iyd_e();
void set_2_iyd_h();
void set_2_iyd_l();
void set_2_iyd();
void set_2_iyd_a();
void set_3_iyd_b();
void set_3_iyd_c();
void set_3_iyd_d();
void set_3_iyd_e();
void set_3_iyd_h();
void set_3_iyd_l();
void set_3_iyd();
void set_3_iyd_a();

// E0 - EF
void set_4_iyd_b();
void set_4_iyd_c();
void set_4_iyd_d();
void set_4_iyd_e();
void set_4_iyd_h();
void set_4_iyd_l();
void set_4_iyd();
void set_4_iyd_a();
void set_5_iyd_b();
void set_5_iyd_c();
void set_5_iyd_d();
void set_5_iyd_e();
void set_5_iyd_h();
void set_5_iyd_l();
void set_5_iyd();
void set_5_iyd_a();

// F0 - FF
void set_6_iyd_b();
void set_6_iyd_c();
void set_6_iyd_d();
void set_6_iyd_e();
void set_6_iyd_h();
void set_6_iyd_l();
void set_6_iyd();
void set_6_iyd_a();
void set_7_iyd_b();
void set_7_iyd_c();
void set_7_iyd_d();
void set_7_iyd_e();
void set_7_iyd_h();
void set_7_iyd_l();
void set_7_iyd();
void set_7_iyd_a();

#endif