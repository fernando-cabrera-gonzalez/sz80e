/*
 * opcodes_ix.c - IX Register Instructions (0xDD Prefix)
 *
 * This file defines the opcode table and handlers for the Z80 CPU's IX register
 * instructions, which are accessed via the 0xDD prefix.
 *
 * These include operations using the IX index register.
 */

#include "opcodes_ix.h"
#include "z80.h"

    /* ================================================================ */
    /*                      IX INSTRUCTIONS (0xDD)                      */
    /* ================================================================ */

Opcode ixOpcodePtrs[256] = {
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(inc_b, 2, 8, 0),		
    OC(dec_b, 2, 8, 0),		
    OC(ld_b_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(add_ix_bc, 2, 15, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(inc_c, 2, 8, 0),		
    OC(dec_c, 2, 8, 0),		
    OC(ld_c_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(inc_d, 2, 8, 0),		
    OC(dec_d, 2, 8, 0),		
    OC(ld_d_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(add_ix_de, 2, 15, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(inc_e, 2, 8, 0),		
    OC(dec_e, 2, 8, 0),		
    OC(ld_e_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(ld_ix_nn, 4, 14, 0),		
    OC(ld_nni_ix, 4, 20, 0),		
    OC(inc_ix, 2, 10, 0),		
    OC(inc_ixh, 2, 8, 0),		
    OC(dec_ixh, 2, 8, 0),		
    OC(ld_ixh_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(add_ix_ix, 2, 15, 0),		
    OC(ld_ix_nni, 4, 20, 0),		
    OC(dec_ix, 2, 10, 0),		
    OC(inc_ixl, 2, 8, 0),		
    OC(dec_ixl, 2, 8, 0),		
    OC(ld_ixl_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(inc_ixd, 3, 23, 0),		
    OC(dec_ixd, 3, 23, 0),		
    OC(ld_ixd_n, 4, 19, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(add_ix_sp, 2, 15, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(inc_a, 2, 8, 0),		
    OC(dec_a, 2, 8, 0),		
    OC(ld_a_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC(ld_b_b, 2, 8, 0),		
    OC(ld_b_c, 2, 8, 0),		
    OC(ld_b_d, 2, 8, 0),		
    OC(ld_b_e, 2, 8, 0),		
    OC(ld_b_ixh, 2, 8, 0),		
    OC(ld_b_ixl, 2, 8, 0),		
    OC(ld_b_ixd, 3, 19, 0),		
    OC(ld_b_a, 2, 8, 0),		
    OC(ld_c_b, 2, 8, 0),		
    OC(ld_c_c, 2, 8, 0),		
    OC(ld_c_d, 2, 8, 0),		
    OC(ld_c_e, 2, 8, 0),		
    OC(ld_c_ixh, 2, 8, 0),		
    OC(ld_c_ixl, 2, 8, 0),		
    OC(ld_c_ixd, 3, 19, 0),		
    OC(ld_c_a, 2, 8, 0),		
    OC(ld_d_b, 2, 8, 0),		
    OC(ld_d_c, 2, 8, 0),		
    OC(ld_d_d, 2, 8, 0),		
    OC(ld_d_e, 2, 8, 0),		
    OC(ld_d_ixh, 2, 8, 0),		
    OC(ld_d_ixl, 2, 8, 0),		
    OC(ld_d_ixd, 3, 19, 0),		
    OC(ld_d_a, 2, 8, 0),		
    OC(ld_e_b, 2, 8, 0),		
    OC(ld_e_c, 2, 8, 0),		
    OC(ld_e_d, 2, 8, 0),		
    OC(ld_e_e, 2, 8, 0),		
    OC(ld_e_ixh, 2, 8, 0),		
    OC(ld_e_ixl, 2, 8, 0),		
    OC(ld_e_ixd, 3, 19, 0),		
    OC(ld_e_a, 2, 8, 0),		
    OC(ld_ixh_b, 2, 8, 0),		
    OC(ld_ixh_c, 2, 8, 0),		
    OC(ld_ixh_d, 2, 8, 0),		
    OC(ld_ixh_e, 2, 8, 0),		
    OC(ld_ixh_ixh, 2, 8, 0),		
    OC(ld_ixh_ixl, 2, 8, 0),		
    OC(ld_h_ixd, 3, 19, 0),		
    OC(ld_ixh_a, 2, 8, 0),		
    OC(ld_ixl_b, 2, 8, 0),		
    OC(ld_ixl_c, 2, 8, 0),		
    OC(ld_ixl_d, 2, 8, 0),		
    OC(ld_ixl_e, 2, 8, 0),		
    OC(ld_ixl_ixh, 2, 8, 0),		
    OC(ld_ixl_ixl, 2, 8, 0),		
    OC(ld_l_ixd, 3, 19, 0),		
    OC(ld_ixl_a, 2, 8, 0),		
    OC(ld_ixd_b, 3, 19, 0),		
    OC(ld_ixd_c, 3, 19, 0),		
    OC(ld_ixd_d, 3, 19, 0),		
    OC(ld_ixd_e, 3, 19, 0),		
    OC(ld_ixd_h, 3, 19, 0),		
    OC(ld_ixd_l, 3, 19, 0),		
    OC_LITE(not_imp),		
    OC(ld_ixd_a, 3, 19, 0),		
    OC(ld_a_b, 2, 8, 0),		
    OC(ld_a_c, 2, 8, 0),		
    OC(ld_a_d, 2, 8, 0),		
    OC(ld_a_e, 2, 8, 0),		
    OC(ld_a_ixh, 2, 8, 0),		
    OC(ld_a_ixl, 2, 8, 0),		
    OC(ld_a_ixd, 3, 19, 0),		
    OC(ld_a_a, 2, 8, 0),		
    OC(add_a_b, 2, 8, 0),		
    OC(add_a_c, 2, 8, 0),		
    OC(add_a_d, 2, 8, 0),		
    OC(add_a_e, 2, 8, 0),		
    OC(add_a_ixh, 2, 8, 0),		
    OC(add_a_ixl, 2, 8, 0),		
    OC(add_a_ixd, 3, 19, 0),		
    OC(add_a_a, 2, 8, 0),		
    OC(adc_a_b, 2, 8, 0),		
    OC(adc_a_c, 2, 8, 0),		
    OC(adc_a_d, 2, 8, 0),		
    OC(adc_a_e, 2, 8, 0),		
    OC(adc_a_ixh, 2, 8, 0),		
    OC(adc_a_ixl, 2, 8, 0),		
    OC(adc_a_ixd, 3, 19, 0),		
    OC(adc_a_a, 2, 8, 0),		
    OC(sub_b, 2, 8, 0),		
    OC(sub_c, 2, 8, 0),		
    OC(sub_d, 2, 8, 0),		
    OC(sub_e, 2, 8, 0),		
    OC(sub_ixh, 2, 8, 0),		
    OC(sub_ixl, 2, 8, 0),		
    OC(sub_ixd, 3, 19, 0),		
    OC(sub_a, 2, 8, 0),		
    OC(sbc_a_b, 2, 8, 0),		
    OC(sbc_a_c, 2, 8, 0),		
    OC(sbc_a_d, 2, 8, 0),		
    OC(sbc_a_e, 2, 8, 0),		
    OC(sbc_a_ixh, 2, 8, 0),		
    OC(sbc_a_ixl, 2, 8, 0),		
    OC(sbc_a_ixd, 3, 19, 0),		
    OC(sbc_a_a, 2, 8, 0),		
    OC(and_b, 2, 8, 0),		
    OC(and_c, 2, 8, 0),		
    OC(and_d, 2, 8, 0),		
    OC(and_e, 2, 8, 0),		
    OC(and_ixh, 2, 8, 0),		
    OC(and_ixl, 2, 8, 0),		
    OC(and_ixd, 3, 19, 0),		
    OC(and_a, 2, 8, 0),		
    OC(xor_b, 2, 8, 0),		
    OC(xor_c, 2, 8, 0),		
    OC(xor_d, 2, 8, 0),		
    OC(xor_e, 2, 8, 0),		
    OC(xor_ixh, 2, 8, 0),		
    OC(xor_ixl, 2, 8, 0),		
    OC(xor_ixd, 3, 19, 0),		
    OC(xor_a, 2, 8, 0),		
    OC(or_b, 2, 8, 0),		
    OC(or_c, 2, 8, 0),		
    OC(or_d, 2, 8, 0),		
    OC(or_e, 2, 8, 0),		
    OC(or_ixh, 2, 8, 0),		
    OC(or_ixl, 2, 8, 0),		
    OC(or_ixd, 3, 19, 0),		
    OC(or_a, 2, 8, 0),		
    OC(cp_b, 2, 8, 0),		
    OC(cp_c, 2, 8, 0),		
    OC(cp_d, 2, 8, 0),		
    OC(cp_e, 2, 8, 0),		
    OC(cp_ixh, 2, 8, 0),		
    OC(cp_ixl, 2, 8, 0),		
    OC(cp_ixd, 3, 19, 0),		
    OC(cp_a, 2, 8, 0),		
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
    OC(pop_ix, 2, 14, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(push_ix, 2, 15, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(jp_ix, 2, 8, 0),		
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
    OC(ld_sp_ix, 2, 10, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp)
};

Opcode ixBitOpcodePtrs[256] = {
    // 00 - 0F
    OC(rlc_ixd_b, 4, 23, 0),		
    OC(rlc_ixd_c, 4, 23, 0),		
    OC(rlc_ixd_d, 4, 23, 0),		
    OC(rlc_ixd_e, 4, 23, 0),		
    OC(rlc_ixd_h, 4, 23, 0),		
    OC(rlc_ixd_l, 4, 23, 0),		
    OC(rlc_ixd, 4, 23, 0),		
    OC(rlc_ixd_a, 4, 23, 0),		
    OC(rrc_ixd_b, 4, 23, 0),		
    OC(rrc_ixd_c, 4, 23, 0),		
    OC(rrc_ixd_d, 4, 23, 0),		
    OC(rrc_ixd_e, 4, 23, 0),		
    OC(rrc_ixd_h, 4, 23, 0),		
    OC(rrc_ixd_l, 4, 23, 0),		
    OC(rrc_ixd, 4, 23, 0),		
    OC(rrc_ixd_a, 4, 23, 0),		

    // 10 - 1F
    OC(rl_ixd_b, 4, 23, 0),		
    OC(rl_ixd_c, 4, 23, 0),		
    OC(rl_ixd_d, 4, 23, 0),		
    OC(rl_ixd_e, 4, 23, 0),		
    OC(rl_ixd_h, 4, 23, 0),		
    OC(rl_ixd_l, 4, 23, 0),		
    OC(rl_ixd, 4, 23, 0),		
    OC(rl_ixd_a, 4, 23, 0),		
    OC(rr_ixd_b, 4, 23, 0),		
    OC(rr_ixd_c, 4, 23, 0),		
    OC(rr_ixd_d, 4, 23, 0),		
    OC(rr_ixd_e, 4, 23, 0),		
    OC(rr_ixd_h, 4, 23, 0),		
    OC(rr_ixd_l, 4, 23, 0),		
    OC(rr_ixd, 4, 23, 0),		
    OC(rr_ixd_a, 4, 23, 0),

    // 20 - 2F		
    OC(sla_ixd_b, 4, 23, 0),		
    OC(sla_ixd_c, 4, 23, 0),		
    OC(sla_ixd_d, 4, 23, 0),		
    OC(sla_ixd_e, 4, 23, 0),		
    OC(sla_ixd_h, 4, 23, 0),		
    OC(sla_ixd_l, 4, 23, 0),		
    OC(sla_ixd, 4, 23, 0),		
    OC(sla_ixd_a, 4, 23, 0),		
    OC(sra_ixd_b, 4, 23, 0),		
    OC(sra_ixd_c, 4, 23, 0),		
    OC(sra_ixd_d, 4, 23, 0),		
    OC(sra_ixd_e, 4, 23, 0),		
    OC(sra_ixd_h, 4, 23, 0),		
    OC(sra_ixd_l, 4, 23, 0),		
    OC(sra_ixd, 4, 23, 0),		
    OC(sra_ixd_a, 4, 23, 0),	

    // 30 - 3F	
    OC(sll_ixd_b, 4, 23, 0),		
    OC(sll_ixd_c, 4, 23, 0),		
    OC(sll_ixd_d, 4, 23, 0),		
    OC(sll_ixd_e, 4, 23, 0),		
    OC(sll_ixd_h, 4, 23, 0),		
    OC(sll_ixd_l, 4, 23, 0),		
    OC(sll_ixd, 4, 23, 0),		
    OC(sll_ixd_a, 4, 23, 0),		
    OC(srl_ixd_b, 4, 23, 0),		
    OC(srl_ixd_c, 4, 23, 0),		
    OC(srl_ixd_d, 4, 23, 0),		
    OC(srl_ixd_e, 4, 23, 0),		
    OC(srl_ixd_h, 4, 23, 0),		
    OC(srl_ixd_l, 4, 23, 0),		
    OC(srl_ixd, 4, 23, 0),		
    OC(srl_ixd_a, 4, 23, 0),

    // 40 - 4F		
    OC(bit_0_ixd, 4, 20, 0),		
    OC(bit_0_ixd, 4, 20, 0),		
    OC(bit_0_ixd, 4, 20, 0),		
    OC(bit_0_ixd, 4, 20, 0),		
    OC(bit_0_ixd, 4, 20, 0),		
    OC(bit_0_ixd, 4, 20, 0),		
    OC(bit_0_ixd, 4, 20, 0),		
    OC(bit_0_ixd, 4, 20, 0),		
    OC(bit_1_ixd, 4, 20, 0),		
    OC(bit_1_ixd, 4, 20, 0),		
    OC(bit_1_ixd, 4, 20, 0),		
    OC(bit_1_ixd, 4, 20, 0),		
    OC(bit_1_ixd, 4, 20, 0),		
    OC(bit_1_ixd, 4, 20, 0),		
    OC(bit_1_ixd, 4, 20, 0),		
    OC(bit_1_ixd, 4, 20, 0),

    // 50 - 5F		
    OC(bit_2_ixd, 4, 20, 0),		
    OC(bit_2_ixd, 4, 20, 0),		
    OC(bit_2_ixd, 4, 20, 0),		
    OC(bit_2_ixd, 4, 20, 0),		
    OC(bit_2_ixd, 4, 20, 0),		
    OC(bit_2_ixd, 4, 20, 0),		
    OC(bit_2_ixd, 4, 20, 0),		
    OC(bit_2_ixd, 4, 20, 0),		
    OC(bit_3_ixd, 4, 20, 0),		
    OC(bit_3_ixd, 4, 20, 0),		
    OC(bit_3_ixd, 4, 20, 0),		
    OC(bit_3_ixd, 4, 20, 0),		
    OC(bit_3_ixd, 4, 20, 0),		
    OC(bit_3_ixd, 4, 20, 0),		
    OC(bit_3_ixd, 4, 20, 0),		
    OC(bit_3_ixd, 4, 20, 0),

    // 60 - 6F		
    OC(bit_4_ixd, 4, 20, 0),		
    OC(bit_4_ixd, 4, 20, 0),		
    OC(bit_4_ixd, 4, 20, 0),		
    OC(bit_4_ixd, 4, 20, 0),		
    OC(bit_4_ixd, 4, 20, 0),		
    OC(bit_4_ixd, 4, 20, 0),		
    OC(bit_4_ixd, 4, 20, 0),		
    OC(bit_4_ixd, 4, 20, 0),		
    OC(bit_5_ixd, 4, 20, 0),		
    OC(bit_5_ixd, 4, 20, 0),		
    OC(bit_5_ixd, 4, 20, 0),		
    OC(bit_5_ixd, 4, 20, 0),		
    OC(bit_5_ixd, 4, 20, 0),		
    OC(bit_5_ixd, 4, 20, 0),		
    OC(bit_5_ixd, 4, 20, 0),		
    OC(bit_5_ixd, 4, 20, 0),

    // 70 - 7F		
    OC(bit_6_ixd, 4, 20, 0),		
    OC(bit_6_ixd, 4, 20, 0),		
    OC(bit_6_ixd, 4, 20, 0),		
    OC(bit_6_ixd, 4, 20, 0),		
    OC(bit_6_ixd, 4, 20, 0),		
    OC(bit_6_ixd, 4, 20, 0),		
    OC(bit_6_ixd, 4, 20, 0),		
    OC(bit_6_ixd, 4, 20, 0),		
    OC(bit_7_ixd, 4, 20, 0),		
    OC(bit_7_ixd, 4, 20, 0),		
    OC(bit_7_ixd, 4, 20, 0),		
    OC(bit_7_ixd, 4, 20, 0),		
    OC(bit_7_ixd, 4, 20, 0),		
    OC(bit_7_ixd, 4, 20, 0),		
    OC(bit_7_ixd, 4, 20, 0),		
    OC(bit_7_ixd, 4, 20, 0),

    // 80 - 8F		
    OC(res_0_ixd_b, 4, 23, 0),		
    OC(res_0_ixd_c, 4, 23, 0),		
    OC(res_0_ixd_d, 4, 23, 0),		
    OC(res_0_ixd_e, 4, 23, 0),		
    OC(res_0_ixd_h, 4, 23, 0),		
    OC(res_0_ixd_l, 4, 23, 0),		
    OC(res_0_ixd, 4, 23, 0),		
    OC(res_0_ixd_a, 4, 23, 0),		
    OC(res_1_ixd_b, 4, 23, 0),		
    OC(res_1_ixd_c, 4, 23, 0),		
    OC(res_1_ixd_d, 4, 23, 0),		
    OC(res_1_ixd_e, 4, 23, 0),		
    OC(res_1_ixd_h, 4, 23, 0),		
    OC(res_1_ixd_l, 4, 23, 0),		
    OC(res_1_ixd, 4, 23, 0),		
    OC(res_1_ixd_a, 4, 23, 0),		

    // 90 - 9F
    OC(res_2_ixd_b, 4, 23, 0),		
    OC(res_2_ixd_c, 4, 23, 0),		
    OC(res_2_ixd_d, 4, 23, 0),		
    OC(res_2_ixd_e, 4, 23, 0),		
    OC(res_2_ixd_h, 4, 23, 0),		
    OC(res_2_ixd_l, 4, 23, 0),		
    OC(res_2_ixd, 4, 23, 0),		
    OC(res_2_ixd_a, 4, 23, 0),		
    OC(res_3_ixd_b, 4, 23, 0),		
    OC(res_3_ixd_c, 4, 23, 0),		
    OC(res_3_ixd_d, 4, 23, 0),		
    OC(res_3_ixd_e, 4, 23, 0),		
    OC(res_3_ixd_h, 4, 23, 0),		
    OC(res_3_ixd_l, 4, 23, 0),		
    OC(res_3_ixd, 4, 23, 0),		
    OC(res_3_ixd_a, 4, 23, 0),		

    // A0 - AF
    OC(res_4_ixd_b, 4, 23, 0),		
    OC(res_4_ixd_c, 4, 23, 0),		
    OC(res_4_ixd_d, 4, 23, 0),		
    OC(res_4_ixd_e, 4, 23, 0),		
    OC(res_4_ixd_h, 4, 23, 0),		
    OC(res_4_ixd_l, 4, 23, 0),		
    OC(res_4_ixd, 4, 23, 0),		
    OC(res_4_ixd_a, 4, 23, 0),		
    OC(res_5_ixd_b, 4, 23, 0),		
    OC(res_5_ixd_c, 4, 23, 0),		
    OC(res_5_ixd_d, 4, 23, 0),		
    OC(res_5_ixd_e, 4, 23, 0),		
    OC(res_5_ixd_h, 4, 23, 0),		
    OC(res_5_ixd_l, 4, 23, 0),		
    OC(res_5_ixd, 4, 23, 0),		
    OC(res_5_ixd_a, 4, 23, 0),	

    // B0 - BF	
    OC(res_6_ixd_b, 4, 23, 0),		
    OC(res_6_ixd_c, 4, 23, 0),		
    OC(res_6_ixd_d, 4, 23, 0),		
    OC(res_6_ixd_e, 4, 23, 0),		
    OC(res_6_ixd_h, 4, 23, 0),		
    OC(res_6_ixd_l, 4, 23, 0),		
    OC(res_6_ixd, 4, 23, 0),		
    OC(res_6_ixd_a, 4, 23, 0),		
    OC(res_7_ixd_b, 4, 23, 0),		
    OC(res_7_ixd_c, 4, 23, 0),		
    OC(res_7_ixd_d, 4, 23, 0),		
    OC(res_7_ixd_e, 4, 23, 0),		
    OC(res_7_ixd_h, 4, 23, 0),		
    OC(res_7_ixd_l, 4, 23, 0),		
    OC(res_7_ixd, 4, 23, 0),		
    OC(res_7_ixd_a, 4, 23, 0),	

    // C0 - CF	
    OC(set_0_ixd_b, 4, 23, 0),		
    OC(set_0_ixd_c, 4, 23, 0),		
    OC(set_0_ixd_d, 4, 23, 0),		
    OC(set_0_ixd_e, 4, 23, 0),		
    OC(set_0_ixd_h, 4, 23, 0),		
    OC(set_0_ixd_l, 4, 23, 0),		
    OC(set_0_ixd, 4, 23, 0),		
    OC(set_0_ixd_a, 4, 23, 0),		
    OC(set_1_ixd_b, 4, 23, 0),		
    OC(set_1_ixd_c, 4, 23, 0),		
    OC(set_1_ixd_d, 4, 23, 0),		
    OC(set_1_ixd_e, 4, 23, 0),		
    OC(set_1_ixd_h, 4, 23, 0),		
    OC(set_1_ixd_l, 4, 23, 0),		
    OC(set_1_ixd, 4, 23, 0),		
    OC(set_1_ixd_a, 4, 23, 0),		

    // D0 - DF
    OC(set_2_ixd_b, 4, 23, 0),		
    OC(set_2_ixd_c, 4, 23, 0),		
    OC(set_2_ixd_d, 4, 23, 0),		
    OC(set_2_ixd_e, 4, 23, 0),		
    OC(set_2_ixd_h, 4, 23, 0),		
    OC(set_2_ixd_l, 4, 23, 0),		
    OC(set_2_ixd, 4, 23, 0),		
    OC(set_2_ixd_a, 4, 23, 0),		
    OC(set_3_ixd_b, 4, 23, 0),		
    OC(set_3_ixd_c, 4, 23, 0),		
    OC(set_3_ixd_d, 4, 23, 0),		
    OC(set_3_ixd_e, 4, 23, 0),		
    OC(set_3_ixd_h, 4, 23, 0),		
    OC(set_3_ixd_l, 4, 23, 0),		
    OC(set_3_ixd, 4, 23, 0),		
    OC(set_3_ixd_a, 4, 23, 0),

    // E0 - EF		
    OC(set_4_ixd_b, 4, 23, 0),		
    OC(set_4_ixd_c, 4, 23, 0),		
    OC(set_4_ixd_d, 4, 23, 0),		
    OC(set_4_ixd_e, 4, 23, 0),		
    OC(set_4_ixd_h, 4, 23, 0),		
    OC(set_4_ixd_l, 4, 23, 0),		
    OC(set_4_ixd, 4, 23, 0),		
    OC(set_4_ixd_a, 4, 23, 0),		
    OC(set_5_ixd_b, 4, 23, 0),		
    OC(set_5_ixd_c, 4, 23, 0),		
    OC(set_5_ixd_d, 4, 23, 0),		
    OC(set_5_ixd_e, 4, 23, 0),		
    OC(set_5_ixd_h, 4, 23, 0),		
    OC(set_5_ixd_l, 4, 23, 0),		
    OC(set_5_ixd, 4, 23, 0),		
    OC(set_5_ixd_a, 4, 23, 0),		

    // F0 - FF
    OC(set_6_ixd_b, 4, 23, 0),		
    OC(set_6_ixd_c, 4, 23, 0),		
    OC(set_6_ixd_d, 4, 23, 0),		
    OC(set_6_ixd_e, 4, 23, 0),		
    OC(set_6_ixd_h, 4, 23, 0),		
    OC(set_6_ixd_l, 4, 23, 0),		
    OC(set_6_ixd, 4, 23, 0),		
    OC(set_6_ixd_a, 4, 23, 0),		
    OC(set_7_ixd_b, 4, 23, 0),		
    OC(set_7_ixd_c, 4, 23, 0),		
    OC(set_7_ixd_d, 4, 23, 0),		
    OC(set_7_ixd_e, 4, 23, 0),		
    OC(set_7_ixd_h, 4, 23, 0),		
    OC(set_7_ixd_l, 4, 23, 0),		
    OC(set_7_ixd, 4, 23, 0),		
    OC(set_7_ixd_a, 4, 23, 0)	
};

void add_ix_bc() {
    execute16BitAdd(z80.bc, &z80.ix, false);
}

void add_ix_de() {
    execute16BitAdd(z80.de, &z80.ix, false);    
}

void add_ix_ix() {
    execute16BitAdd(z80.ix, &z80.ix, false);    
}

void add_ix_sp() {
    execute16BitAdd(z80.sp, &z80.ix, false);    
}

void ld_ix_nn() {
    z80.ix = memReadFunc(z80.pc - 2);
    z80.ix += memReadFunc(z80.pc - 1) << 8;   
}

void ld_nni_ix() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    memWriteFunc(address, z80.ix & 0x00FF);
    memWriteFunc(address + 1, (z80.ix >> 8) & 0x00FF);
}

void inc_ix() {
    z80.ix++;
}

void inc_ixh() {
    uint8_t old = z80.ixh++;

    // carry flag unaffected
    z80.flags.n     = 0;
    z80.flags.pv    = old == 0x7F;
    z80.flags.h     = (old & 0x0F) == 0x0F;   
    z80.flags.z     = z80.ixh == 0x00;
    z80.flags.s     = (z80.ixh & 0x80) != 0;    
}

void dec_ixh() {
    uint8_t old = z80.ixh--;

    // carry flag unaffected
    z80.flags.n     = 1;
    z80.flags.pv    = old == 0x80;
    z80.flags.h     = (old & 0x0F) == 0x00;   
    z80.flags.z     = z80.ixh == 0x00;
    z80.flags.s     = (z80.ixh & 0x80) != 0;
}

void dec_ix() {
    z80.ix--;
}

void inc_ixl() {
    uint8_t old = z80.ixl++;

    // carry flag unaffected
    z80.flags.n     = 0;
    z80.flags.pv    = old == 0x7F;
    z80.flags.h     = (old & 0x0F) == 0x0F;   
    z80.flags.z     = z80.ixl == 0x00;
    z80.flags.s     = (z80.ixl & 0x80) != 0;    
}

void dec_ixl() {
    uint8_t old = z80.ixl--;

    // carry flag unaffected
    z80.flags.n     = 1;
    z80.flags.pv    = old == 0x80;
    z80.flags.h     = (old & 0x0F) == 0x00;   
    z80.flags.z     = z80.ixl == 0x00;
    z80.flags.s     = (z80.ixl & 0x80) != 0;
}

void ld_ixh_n() {
    uint8_t n = memReadFunc(z80.pc - 1);
   z80.ixh = n;    
}

void ld_ix_nni() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    z80.ix = memReadFunc(address) + (memReadFunc(address + 1) << 8);    
}

void ld_ixl_n() {
    uint8_t n = memReadFunc(z80.pc - 1);
    z80.ixl = n;   
}

void inc_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.ix + d);
    executeInc(&n);
    memWriteFunc(z80.ix + d, n);
}

void dec_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.ix + d);
    executeDec(&n);
    memWriteFunc(z80.ix + d, n);
}

void ld_ixd_n() {
    int8_t d = memReadFunc(z80.pc - 2);
    int8_t n = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.ix + d, n);
}

void ld_b_ixh() {
    z80.b = z80.ixh;
}

void ld_b_ixl() {
    z80.b = z80.ixl;    
}

void ld_b_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.b = memReadFunc(z80.ix + d);
}

void ld_c_ixh() {
    z80.c = z80.ixh;
}

void ld_c_ixl() {
    z80.c = z80.ixl;    
}

void ld_c_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.c = memReadFunc(z80.ix + d);
}

void ld_d_ixh() {
    z80.d = z80.ixh;
}

void ld_d_ixl() {
    z80.d = z80.ixl;    
}

void ld_d_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.d = memReadFunc(z80.ix + d);
}

void ld_e_ixh() {
    z80.e = z80.ixh;
}

void ld_e_ixl() {
    z80.e = z80.ixl;    
}

void ld_e_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.e = memReadFunc(z80.ix + d);
}

void ld_ixd_b() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.ix + d, z80.b);
}

void ld_ixd_c() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.ix + d, z80.c);
}

void ld_ixd_d() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.ix + d, z80.d);
}

void ld_ixd_e() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.ix + d, z80.e);
}

void ld_ixd_h() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.ix + d, z80.h);
}

void ld_ixd_l() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.ix + d, z80.l);
}

void ld_ixd_a() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.ix + d, z80.a);
}

void ld_ixh_b() {
    z80.ixh = z80.b;
}

void ld_ixh_c() {
    z80.ixh = z80.c;	
}

void ld_ixh_d() {
    z80.ixh = z80.d;		
}

void ld_ixh_e() {
    z80.ixh = z80.e;		
}

void ld_ixh_ixh() {
    z80.ixh = z80.ixh;		
}

void ld_ixh_ixl() {
    z80.ixh = z80.ixl;		
}

void ld_h_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.h = memReadFunc(z80.ix + d);
}

void ld_ixh_a() {
    z80.ixh = z80.a;		
}

void ld_ixl_b() {
    z80.ixl = z80.b;		
}

void ld_ixl_c() {
    z80.ixl = z80.c;		
}

void ld_ixl_d() {
    z80.ixl = z80.d;		
}

void ld_ixl_e() {
    z80.ixl = z80.e;		
}

void ld_ixl_ixh() {
    z80.ixl = z80.ixh;		
}

void ld_ixl_ixl() {
    z80.ixl = z80.ixl;		
}

void ld_l_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.l = memReadFunc(z80.ix + d);
}

void ld_ixl_a() {
    z80.ixl = z80.a;		
}

void ld_a_ixh() {
    z80.a = z80.ixh;		
}

void ld_a_ixl() {
    z80.a = z80.ixl;
}

void ld_a_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.a = memReadFunc(z80.ix + d);
}

void add_a_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.ix + d);
    execute8BitAdd(n, 0);
}

void adc_a_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.ix + d);
    execute8BitAdd(n, z80.flags.c);
}

void sub_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.ix + d);
    execute8BitSub(n, 0, 1);
}

void sbc_a_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.ix + d);
    execute8BitSub(n, z80.flags.c, 1);
}

void and_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.ix + d);
    executeLogical(n, AND);
}

void xor_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.ix + d);
    executeLogical(n, XOR);
}

void or_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.ix + d);
    executeLogical(n, OR);
}

void cp_ixd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.ix + d);
    execute8BitSub(n, 0, 0);
}

void add_a_ixh() {
    execute8BitAdd(z80.ixh, 0);
}

void add_a_ixl() {
    execute8BitAdd(z80.ixl, 0);
}

void adc_a_ixh() {
    execute8BitAdd(z80.ixh, z80.flags.c);
}

void adc_a_ixl() {
    execute8BitAdd(z80.ixl, z80.flags.c);
}

void sub_ixh() {
    execute8BitSub(z80.ixh, 0, true);
}

void sub_ixl() {
    execute8BitSub(z80.ixl, 0, true);
}

void sbc_a_ixh() {
    execute8BitSub(z80.ixh, z80.flags.c, true);
}

void sbc_a_ixl() {
    execute8BitSub(z80.ixl, z80.flags.c, true);
}

void and_ixh() {
    executeLogical(z80.ixh, AND);
}

void and_ixl() {
    executeLogical(z80.ixl, AND);
}

void xor_ixh() {
    executeLogical(z80.ixh, XOR);
}

void xor_ixl() {
    executeLogical(z80.ixl, XOR);
}

void or_ixh() {
    executeLogical(z80.ixh, OR);
}

void or_ixl() {
    executeLogical(z80.ixl, OR);
}

void cp_ixh() {
    execute8BitSub(z80.ixh, 0, 0);
}

void cp_ixl() {
    execute8BitSub(z80.ixl, 0, 0);
}

void pop_ix() {
    z80.ix = pop();
}

void push_ix() {
    push(z80.ix);
}

void jp_ix() {
    z80.pc = z80.ix;
}

void ld_sp_ix() {
    z80.sp = z80.ix;
}

    /* ================================================================ */
    /*             IX BIT INSTRUCTIONS (0xDD 0xCB)                      */
    /* ================================================================ */

void rlc_ixd_b() {
    executeXYRotateLeft(z80.ix, &z80.b, true);
}

void rlc_ixd_c() {
    executeXYRotateLeft(z80.ix, &z80.c, true);
}

void rlc_ixd_d() {
    executeXYRotateLeft(z80.ix, &z80.d, true);
}

void rlc_ixd_e() {
    executeXYRotateLeft(z80.ix, &z80.e, true);
}

void rlc_ixd_h() {
    executeXYRotateLeft(z80.ix, &z80.h, true);
}

void rlc_ixd_l() {
    executeXYRotateLeft(z80.ix, &z80.l, true);
}

void rlc_ixd() {
    executeXYRotateLeft(z80.ix, NULL, true);
}

void rlc_ixd_a() {
    executeXYRotateLeft(z80.ix, &z80.a, true);
}

void rrc_ixd_b() {
    executeXYRotateRight(z80.ix, &z80.b, true);
}

void rrc_ixd_c() {
    executeXYRotateRight(z80.ix, &z80.c, true);
}
void rrc_ixd_d() {
    executeXYRotateRight(z80.ix, &z80.d, true);
}

void rrc_ixd_e() {
    executeXYRotateRight(z80.ix, &z80.e, true);
}

void rrc_ixd_h() {
    executeXYRotateRight(z80.ix, &z80.h, true);
}

void rrc_ixd_l() {
    executeXYRotateRight(z80.ix, &z80.l, true);
}

void rrc_ixd() {
    executeXYRotateRight(z80.ix, NULL, true);
}

void rrc_ixd_a() {
    executeXYRotateRight(z80.ix, &z80.a, true);
}

void rl_ixd_b() {
    executeXYRotateLeft(z80.ix, &z80.b, false);
}

void rl_ixd_c() {
    executeXYRotateLeft(z80.ix, &z80.c, false);
}

void rl_ixd_d() {
    executeXYRotateLeft(z80.ix, &z80.d, false);
}

void rl_ixd_e() {
    executeXYRotateLeft(z80.ix, &z80.e, false);
}

void rl_ixd_h() {
    executeXYRotateLeft(z80.ix, &z80.h, false);
}
void rl_ixd_l() {
    executeXYRotateLeft(z80.ix, &z80.l, false);
}
void rl_ixd() {
    executeXYRotateLeft(z80.ix, NULL, false);
}
void rl_ixd_a() {
    executeXYRotateLeft(z80.ix, &z80.a, false);
}

void rr_ixd_b() {
    executeXYRotateRight(z80.ix, &z80.b, false);
}

void rr_ixd_c() {
    executeXYRotateRight(z80.ix, &z80.c, false);
}
void rr_ixd_d() {
    executeXYRotateRight(z80.ix, &z80.d, false);
}

void rr_ixd_e() {
    executeXYRotateRight(z80.ix, &z80.e, false);
}

void rr_ixd_h() {
    executeXYRotateRight(z80.ix, &z80.h, false);
}

void rr_ixd_l() {
    executeXYRotateRight(z80.ix, &z80.l, false);
}

void rr_ixd() {
    executeXYRotateRight(z80.ix, NULL, false);
}

void rr_ixd_a() {
    executeXYRotateRight(z80.ix, &z80.a, false);
}

void sla_ixd_b() {
    executeXYShiftLeft(z80.ix, &z80.b, true);
}

void sla_ixd_c() {
    executeXYShiftLeft(z80.ix, &z80.c, true);
}

void sla_ixd_d() {
    executeXYShiftLeft(z80.ix, &z80.d, true);
}

void sla_ixd_e() {
    executeXYShiftLeft(z80.ix, &z80.e, true);
}

void sla_ixd_h() {
    executeXYShiftLeft(z80.ix, &z80.h, true);
}

void sla_ixd_l() {
    executeXYShiftLeft(z80.ix, &z80.l, true);
}
void sla_ixd() {
    executeXYShiftLeft(z80.ix, NULL, true);
}
void sla_ixd_a() {
    executeXYShiftLeft(z80.ix, &z80.a, true);
}

void sra_ixd_b() {
    executeXYShiftRight(z80.ix, &z80.b, true);
}

void sra_ixd_c() {
    executeXYShiftRight(z80.ix, &z80.c, true);
}

void sra_ixd_d() {
    executeXYShiftRight(z80.ix, &z80.d, true);
}

void sra_ixd_e() {
    executeXYShiftRight(z80.ix, &z80.e, true);
}

void sra_ixd_h() {
    executeXYShiftRight(z80.ix, &z80.h, true);
}

void sra_ixd_l() {
    executeXYShiftRight(z80.ix, &z80.l, true);
}

void sra_ixd() {
    executeXYShiftRight(z80.ix, NULL, true);
}

void sra_ixd_a() {
    executeXYShiftRight(z80.ix, &z80.a, true);
}

void sll_ixd_b() {
    executeXYShiftLeft(z80.ix, &z80.b, false);
}

void sll_ixd_c() {
    executeXYShiftLeft(z80.ix, &z80.c, false);
}

void sll_ixd_d() {
    executeXYShiftLeft(z80.ix, &z80.d, false);
}

void sll_ixd_e() {
    executeXYShiftLeft(z80.ix, &z80.e, false);
}

void sll_ixd_h() {
    executeXYShiftLeft(z80.ix, &z80.h, false);
}

void sll_ixd_l() {
    executeXYShiftLeft(z80.ix, &z80.l, false);
}
void sll_ixd() {
    executeXYShiftLeft(z80.ix, NULL, false);
}
void sll_ixd_a() {
    executeXYShiftLeft(z80.ix, &z80.a, false);
}

void srl_ixd_b() {
    executeXYShiftRight(z80.ix, &z80.b, false);
}

void srl_ixd_c() {
    executeXYShiftRight(z80.ix, &z80.c, false);
}

void srl_ixd_d() {
    executeXYShiftRight(z80.ix, &z80.d, false);
}

void srl_ixd_e() {
    executeXYShiftRight(z80.ix, &z80.e, false);
}

void srl_ixd_h() {
    executeXYShiftRight(z80.ix, &z80.h, false);
}

void srl_ixd_l() {
    executeXYShiftRight(z80.ix, &z80.l, false);
}

void srl_ixd() {
    executeXYShiftRight(z80.ix, NULL, false);
}

void srl_ixd_a() {
    executeXYShiftRight(z80.ix, &z80.a, false);
}

void bit_0_ixd() {
    executeXYBit(z80.ix, 0);
}

void bit_1_ixd() {
    executeXYBit(z80.ix, 1);
}

void bit_2_ixd() {
    executeXYBit(z80.ix, 2);
}

void bit_3_ixd() {
    executeXYBit(z80.ix, 3);
}

void bit_4_ixd() {
    executeXYBit(z80.ix, 4);
}

void bit_5_ixd() {
    executeXYBit(z80.ix, 5);
}

void bit_6_ixd() {
    executeXYBit(z80.ix, 6);
}

void bit_7_ixd() {
    executeXYBit(z80.ix, 7);
}

void res_0_ixd_b() {
	executeXYReset(z80.ix, 0, &z80.b);
}
void res_0_ixd_c() {
	executeXYReset(z80.ix, 0, &z80.c);
}
void res_0_ixd_d() {
	executeXYReset(z80.ix, 0, &z80.d);
}
void res_0_ixd_e() {
	executeXYReset(z80.ix, 0, &z80.e);
}
void res_0_ixd_h() {
	executeXYReset(z80.ix, 0, &z80.h);
}
void res_0_ixd_l() {
	executeXYReset(z80.ix, 0, &z80.l);
}
void res_0_ixd() {
	executeXYReset(z80.ix, 0, NULL);
}
void res_0_ixd_a() {
	executeXYReset(z80.ix, 0, &z80.a);
}
void res_1_ixd_b() {
	executeXYReset(z80.ix, 1, &z80.b);
}
void res_1_ixd_c() {
	executeXYReset(z80.ix, 1, &z80.c);
}
void res_1_ixd_d() {
	executeXYReset(z80.ix, 1, &z80.d);
}
void res_1_ixd_e() {
	executeXYReset(z80.ix, 1, &z80.e);
}
void res_1_ixd_h() {
	executeXYReset(z80.ix, 1, &z80.h);
}
void res_1_ixd_l() {
	executeXYReset(z80.ix, 1, &z80.l);
}
void res_1_ixd() {
	executeXYReset(z80.ix, 1, NULL);
}
void res_1_ixd_a() {
	executeXYReset(z80.ix, 1, &z80.a);
}
void res_2_ixd_b() {
	executeXYReset(z80.ix, 2, &z80.b);
}
void res_2_ixd_c() {
	executeXYReset(z80.ix, 2, &z80.c);
}
void res_2_ixd_d() {
	executeXYReset(z80.ix, 2, &z80.d);
}
void res_2_ixd_e() {
	executeXYReset(z80.ix, 2, &z80.e);
}
void res_2_ixd_h() {
	executeXYReset(z80.ix, 2, &z80.h);
}
void res_2_ixd_l() {
	executeXYReset(z80.ix, 2, &z80.l);
}
void res_2_ixd() {
	executeXYReset(z80.ix, 2, NULL);
}
void res_2_ixd_a() {
	executeXYReset(z80.ix, 2, &z80.a);
}
void res_3_ixd_b() {
	executeXYReset(z80.ix, 3, &z80.b);
}
void res_3_ixd_c() {
	executeXYReset(z80.ix, 3, &z80.c);
}
void res_3_ixd_d() {
	executeXYReset(z80.ix, 3, &z80.d);
}
void res_3_ixd_e() {
	executeXYReset(z80.ix, 3, &z80.e);
}
void res_3_ixd_h() {
	executeXYReset(z80.ix, 3, &z80.h);
}
void res_3_ixd_l() {
	executeXYReset(z80.ix, 3, &z80.l);
}
void res_3_ixd() {
	executeXYReset(z80.ix, 3, NULL);
}
void res_3_ixd_a() {
	executeXYReset(z80.ix, 3, &z80.a);
}
void res_4_ixd_b() {
	executeXYReset(z80.ix, 4, &z80.b);
}
void res_4_ixd_c() {
	executeXYReset(z80.ix, 4, &z80.c);
}
void res_4_ixd_d() {
	executeXYReset(z80.ix, 4, &z80.d);
}
void res_4_ixd_e() {
	executeXYReset(z80.ix, 4, &z80.e);
}
void res_4_ixd_h() {
	executeXYReset(z80.ix, 4, &z80.h);
}
void res_4_ixd_l() {
	executeXYReset(z80.ix, 4, &z80.l);
}
void res_4_ixd() {
	executeXYReset(z80.ix, 4, NULL);
}
void res_4_ixd_a() {
	executeXYReset(z80.ix, 4, &z80.a);
}
void res_5_ixd_b() {
	executeXYReset(z80.ix, 5, &z80.b);
}
void res_5_ixd_c() {
	executeXYReset(z80.ix, 5, &z80.c);
}
void res_5_ixd_d() {
	executeXYReset(z80.ix, 5, &z80.d);
}
void res_5_ixd_e() {
	executeXYReset(z80.ix, 5, &z80.e);
}
void res_5_ixd_h() {
	executeXYReset(z80.ix, 5, &z80.h);
}
void res_5_ixd_l() {
	executeXYReset(z80.ix, 5, &z80.l);
}
void res_5_ixd() {
	executeXYReset(z80.ix, 5, NULL);
}
void res_5_ixd_a() {
	executeXYReset(z80.ix, 5, &z80.a);
}
void res_6_ixd_b() {
	executeXYReset(z80.ix, 6, &z80.b);
}
void res_6_ixd_c() {
	executeXYReset(z80.ix, 6, &z80.c);
}
void res_6_ixd_d() {
	executeXYReset(z80.ix, 6, &z80.d);
}
void res_6_ixd_e() {
	executeXYReset(z80.ix, 6, &z80.e);
}
void res_6_ixd_h() {
	executeXYReset(z80.ix, 6, &z80.h);
}
void res_6_ixd_l() {
	executeXYReset(z80.ix, 6, &z80.l);
}
void res_6_ixd() {
	executeXYReset(z80.ix, 6, NULL);
}
void res_6_ixd_a() {
	executeXYReset(z80.ix, 6, &z80.a);
}
void res_7_ixd_b() {
	executeXYReset(z80.ix, 7, &z80.b);
}
void res_7_ixd_c() {
	executeXYReset(z80.ix, 7, &z80.c);
}
void res_7_ixd_d() {
	executeXYReset(z80.ix, 7, &z80.d);
}
void res_7_ixd_e() {
	executeXYReset(z80.ix, 7, &z80.e);
}
void res_7_ixd_h() {
	executeXYReset(z80.ix, 7, &z80.h);
}
void res_7_ixd_l() {
	executeXYReset(z80.ix, 7, &z80.l);
}
void res_7_ixd() {
	executeXYReset(z80.ix, 7, NULL);
}
void res_7_ixd_a() {
	executeXYReset(z80.ix, 7, &z80.a);
}

void set_0_ixd_b() {
	executeXYSet(z80.ix, 0, &z80.b);
}
void set_0_ixd_c() {
	executeXYSet(z80.ix, 0, &z80.c);
}
void set_0_ixd_d() {
	executeXYSet(z80.ix, 0, &z80.d);
}
void set_0_ixd_e() {
	executeXYSet(z80.ix, 0, &z80.e);
}
void set_0_ixd_h() {
	executeXYSet(z80.ix, 0, &z80.h);
}
void set_0_ixd_l() {
	executeXYSet(z80.ix, 0, &z80.l);
}
void set_0_ixd() {
	executeXYSet(z80.ix, 0, NULL);
}
void set_0_ixd_a() {
	executeXYSet(z80.ix, 0, &z80.a);
}
void set_1_ixd_b() {
	executeXYSet(z80.ix, 1, &z80.b);
}
void set_1_ixd_c() {
	executeXYSet(z80.ix, 1, &z80.c);
}
void set_1_ixd_d() {
	executeXYSet(z80.ix, 1, &z80.d);
}
void set_1_ixd_e() {
	executeXYSet(z80.ix, 1, &z80.e);
}
void set_1_ixd_h() {
	executeXYSet(z80.ix, 1, &z80.h);
}
void set_1_ixd_l() {
	executeXYSet(z80.ix, 1, &z80.l);
}
void set_1_ixd() {
	executeXYSet(z80.ix, 1, NULL);
}
void set_1_ixd_a() {
	executeXYSet(z80.ix, 1, &z80.a);
}
void set_2_ixd_b() {
	executeXYSet(z80.ix, 2, &z80.b);
}
void set_2_ixd_c() {
	executeXYSet(z80.ix, 2, &z80.c);
}
void set_2_ixd_d() {
	executeXYSet(z80.ix, 2, &z80.d);
}
void set_2_ixd_e() {
	executeXYSet(z80.ix, 2, &z80.e);
}
void set_2_ixd_h() {
	executeXYSet(z80.ix, 2, &z80.h);
}
void set_2_ixd_l() {
	executeXYSet(z80.ix, 2, &z80.l);
}
void set_2_ixd() {
	executeXYSet(z80.ix, 2, NULL);
}
void set_2_ixd_a() {
	executeXYSet(z80.ix, 2, &z80.a);
}
void set_3_ixd_b() {
	executeXYSet(z80.ix, 3, &z80.b);
}
void set_3_ixd_c() {
	executeXYSet(z80.ix, 3, &z80.c);
}
void set_3_ixd_d() {
	executeXYSet(z80.ix, 3, &z80.d);
}
void set_3_ixd_e() {
	executeXYSet(z80.ix, 3, &z80.e);
}
void set_3_ixd_h() {
	executeXYSet(z80.ix, 3, &z80.h);
}
void set_3_ixd_l() {
	executeXYSet(z80.ix, 3, &z80.l);
}
void set_3_ixd() {
	executeXYSet(z80.ix, 3, NULL);
}
void set_3_ixd_a() {
	executeXYSet(z80.ix, 3, &z80.a);
}
void set_4_ixd_b() {
	executeXYSet(z80.ix, 4, &z80.b);
}
void set_4_ixd_c() {
	executeXYSet(z80.ix, 4, &z80.c);
}
void set_4_ixd_d() {
	executeXYSet(z80.ix, 4, &z80.d);
}
void set_4_ixd_e() {
	executeXYSet(z80.ix, 4, &z80.e);
}
void set_4_ixd_h() {
	executeXYSet(z80.ix, 4, &z80.h);
}
void set_4_ixd_l() {
	executeXYSet(z80.ix, 4, &z80.l);
}
void set_4_ixd() {
	executeXYSet(z80.ix, 4, NULL);
}
void set_4_ixd_a() {
	executeXYSet(z80.ix, 4, &z80.a);
}
void set_5_ixd_b() {
	executeXYSet(z80.ix, 5, &z80.b);
}
void set_5_ixd_c() {
	executeXYSet(z80.ix, 5, &z80.c);
}
void set_5_ixd_d() {
	executeXYSet(z80.ix, 5, &z80.d);
}
void set_5_ixd_e() {
	executeXYSet(z80.ix, 5, &z80.e);
}
void set_5_ixd_h() {
	executeXYSet(z80.ix, 5, &z80.h);
}
void set_5_ixd_l() {
	executeXYSet(z80.ix, 5, &z80.l);
}
void set_5_ixd() {
	executeXYSet(z80.ix, 5, NULL);
}
void set_5_ixd_a() {
	executeXYSet(z80.ix, 5, &z80.a);
}
void set_6_ixd_b() {
	executeXYSet(z80.ix, 6, &z80.b);
}
void set_6_ixd_c() {
	executeXYSet(z80.ix, 6, &z80.c);
}
void set_6_ixd_d() {
	executeXYSet(z80.ix, 6, &z80.d);
}
void set_6_ixd_e() {
	executeXYSet(z80.ix, 6, &z80.e);
}
void set_6_ixd_h() {
	executeXYSet(z80.ix, 6, &z80.h);
}
void set_6_ixd_l() {
	executeXYSet(z80.ix, 6, &z80.l);
}
void set_6_ixd() {
	executeXYSet(z80.ix, 6, NULL);
}
void set_6_ixd_a() {
	executeXYSet(z80.ix, 6, &z80.a);
}
void set_7_ixd_b() {
	executeXYSet(z80.ix, 7, &z80.b);
}
void set_7_ixd_c() {
	executeXYSet(z80.ix, 7, &z80.c);
}
void set_7_ixd_d() {
	executeXYSet(z80.ix, 7, &z80.d);
}
void set_7_ixd_e() {
	executeXYSet(z80.ix, 7, &z80.e);
}
void set_7_ixd_h() {
	executeXYSet(z80.ix, 7, &z80.h);
}
void set_7_ixd_l() {
	executeXYSet(z80.ix, 7, &z80.l);
}
void set_7_ixd() {
	executeXYSet(z80.ix, 7, NULL);
}
void set_7_ixd_a() {
	executeXYSet(z80.ix, 7, &z80.a);
}