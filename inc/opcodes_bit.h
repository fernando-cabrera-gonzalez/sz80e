/*
 * opcodes_bit.h - Bit Instructions Interface
 *
 * Declares the opcode table and function prototypes for 0xCB-prefixed bit operations.
 */

#ifndef OPCODES_BIT_H
#define OPCODES_BIT_H

#include "opcodes.h"

    /* ================================================================ */
    /*                     BIT INSTRUCTIONS (0xCB)                      */
    /* ================================================================ */

extern Opcode bitOpcodePtrs[256];

// 00 - 0F
void rlc_b();		
void rlc_c();		
void rlc_d();		
void rlc_e();		
void rlc_h();		
void rlc_l();		
void rlc_hli();		
void rlc_a();		
void rrc_b();		
void rrc_c();		
void rrc_d();		
void rrc_e();		
void rrc_h();		
void rrc_l();		
void rrc_hli();		
void rrc_a();		

// 10 - 1F
void rl_b();		
void rl_c();		
void rl_d();		
void rl_e();		
void rl_h();		
void rl_l();		
void rl_hli();		
void rl_a();		
void rr_b();		
void rr_c();		
void rr_d();		
void rr_e();		
void rr_h();		
void rr_l();		
void rr_hli();		
void rr_a();		

// 20 - 2F
void sla_b();		
void sla_c();		
void sla_d();		
void sla_e();		
void sla_h();		
void sla_l();		
void sla_hli();		
void sla_a();		
void sra_b();		
void sra_c();		
void sra_d();		
void sra_e();		
void sra_h();		
void sra_l();		
void sra_hli();		
void sra_a();		

// 30 - 3F
void sll_b();		
void sll_c();		
void sll_d();		
void sll_e();		
void sll_h();		
void sll_l();		
void sll_hli();		
void sll_a();		
void srl_b();		
void srl_c();		
void srl_d();		
void srl_e();		
void srl_h();		
void srl_l();		
void srl_hli();		
void srl_a();		

// 40 - 4F
void bit_0_b();		
void bit_0_c();		
void bit_0_d();		
void bit_0_e();		
void bit_0_h();		
void bit_0_l();		
void bit_0_hli();		
void bit_0_a();		
void bit_1_b();		
void bit_1_c();		
void bit_1_d();		
void bit_1_e();		
void bit_1_h();		
void bit_1_l();		
void bit_1_hli();		
void bit_1_a();	

// 50 - 5F
void bit_2_b();		
void bit_2_c();		
void bit_2_d();		
void bit_2_e();		
void bit_2_h();		
void bit_2_l();		
void bit_2_hli();		
void bit_2_a();		
void bit_3_b();		
void bit_3_c();		
void bit_3_d();		
void bit_3_e();		
void bit_3_h();		
void bit_3_l();		
void bit_3_hli();		
void bit_3_a();	

// 60 - 6F
void bit_4_b();		
void bit_4_c();		
void bit_4_d();		
void bit_4_e();		
void bit_4_h();		
void bit_4_l();		
void bit_4_hli();		
void bit_4_a();		
void bit_5_b();		
void bit_5_c();		
void bit_5_d();		
void bit_5_e();		
void bit_5_h();		
void bit_5_l();		
void bit_5_hli();		
void bit_5_a();		

// 70 - 7F
void bit_6_b();		
void bit_6_c();		
void bit_6_d();		
void bit_6_e();		
void bit_6_h();		
void bit_6_l();		
void bit_6_hli();		
void bit_6_a();		
void bit_7_b();		
void bit_7_c();		
void bit_7_d();		
void bit_7_e();		
void bit_7_h();		
void bit_7_l();		
void bit_7_hli();		
void bit_7_a();		

// 80 - 8F
void res_0_b();		
void res_0_c();		
void res_0_d();		
void res_0_e();		
void res_0_h();		
void res_0_l();		
void res_0_hli();		
void res_0_a();		
void res_1_b();		
void res_1_c();		
void res_1_d();		
void res_1_e();		
void res_1_h();		
void res_1_l();		
void res_1_hli();		
void res_1_a();		

// 90 - 9F
void res_2_b();		
void res_2_c();		
void res_2_d();		
void res_2_e();		
void res_2_h();		
void res_2_l();		
void res_2_hli();		
void res_2_a();		
void res_3_b();		
void res_3_c();		
void res_3_d();		
void res_3_e();		
void res_3_h();		
void res_3_l();		
void res_3_hli();		
void res_3_a();

// A0 - AF
void res_4_b();		
void res_4_c();		
void res_4_d();		
void res_4_e();		
void res_4_h();		
void res_4_l();		
void res_4_hli();		
void res_4_a();		
void res_5_b();		
void res_5_c();		
void res_5_d();		
void res_5_e();		
void res_5_h();		
void res_5_l();		
void res_5_hli();		
void res_5_a();		

// B0 - BF
void res_6_b();		
void res_6_c();		
void res_6_d();		
void res_6_e();		
void res_6_h();		
void res_6_l();		
void res_6_hli();		
void res_6_a();		
void res_7_b();		
void res_7_c();		
void res_7_d();		
void res_7_e();		
void res_7_h();		
void res_7_l();		
void res_7_hli();		
void res_7_a();		

// C0 - CF
void set_0_b();		
void set_0_c();		
void set_0_d();		
void set_0_e();		
void set_0_h();		
void set_0_l();		
void set_0_hli();		
void set_0_a();		
void set_1_b();		
void set_1_c();		
void set_1_d();		
void set_1_e();		
void set_1_h();		
void set_1_l();		
void set_1_hli();		
void set_1_a();	

// D0 - DF
void set_2_b();		
void set_2_c();		
void set_2_d();		
void set_2_e();		
void set_2_h();		
void set_2_l();		
void set_2_hli();		
void set_2_a();		
void set_3_b();		
void set_3_c();		
void set_3_d();		
void set_3_e();		
void set_3_h();		
void set_3_l();		
void set_3_hli();		
void set_3_a();

// E0 - EF
void set_4_b();		
void set_4_c();		
void set_4_d();		
void set_4_e();		
void set_4_h();		
void set_4_l();		
void set_4_hli();		
void set_4_a();		
void set_5_b();		
void set_5_c();		
void set_5_d();		
void set_5_e();		
void set_5_h();		
void set_5_l();		
void set_5_hli();		
void set_5_a();	

// F0 - FF
void set_6_b();		
void set_6_c();		
void set_6_d();		
void set_6_e();		
void set_6_h();		
void set_6_l();		
void set_6_hli();		
void set_6_a();		
void set_7_b();		
void set_7_c();		
void set_7_d();		
void set_7_e();		
void set_7_h();		
void set_7_l();		
void set_7_hli();		
void set_7_a();

#endif