#include "opcodes_iy.h"
#include "z80.h"

    /* ================================================================ */
    /*                      IY INSTRUCTIONS (0xDD)                      */
    /* ================================================================ */

Opcode iyOpcodePtrs[256] = {
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(inc_b, 2, 8, 0),		
    OC(dec_b, 2, 8, 0),		
    OC(ld_b_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(add_iy_bc, 2, 15, 0),		
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
    OC(add_iy_de, 2, 15, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(inc_e, 2, 8, 0),		
    OC(dec_e, 2, 8, 0),		
    OC(ld_e_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(ld_iy_nn, 4, 14, 0),		
    OC(ld_nni_iy, 4, 20, 0),		
    OC(inc_iy, 2, 10, 0),		
    OC(inc_iyh, 2, 8, 0),		
    OC(dec_iyh, 2, 8, 0),		
    OC(ld_iyh_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(add_iy_iy, 2, 15, 0),		
    OC(ld_iy_nni, 4, 20, 0),		
    OC(dec_iy, 2, 10, 0),		
    OC(inc_iyl, 2, 8, 0),		
    OC(dec_iyl, 2, 8, 0),		
    OC(ld_iyl_n, 3, 11, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(inc_iyd, 3, 23, 0),		
    OC(dec_iyd, 3, 23, 0),		
    OC(ld_iyd_n, 4, 19, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(add_iy_sp, 2, 15, 0),		
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
    OC(ld_b_iyh, 2, 8, 0),		
    OC(ld_b_iyl, 2, 8, 0),		
    OC(ld_b_iyd, 3, 19, 0),		
    OC(ld_b_a, 2, 8, 0),		
    OC(ld_c_b, 2, 8, 0),		
    OC(ld_c_c, 2, 8, 0),		
    OC(ld_c_d, 2, 8, 0),		
    OC(ld_c_e, 2, 8, 0),		
    OC(ld_c_iyh, 2, 8, 0),		
    OC(ld_c_iyl, 2, 8, 0),		
    OC(ld_c_iyd, 3, 19, 0),		
    OC(ld_c_a, 2, 8, 0),		
    OC(ld_d_b, 2, 8, 0),		
    OC(ld_d_c, 2, 8, 0),		
    OC(ld_d_d, 2, 8, 0),		
    OC(ld_d_e, 2, 8, 0),		
    OC(ld_d_iyh, 2, 8, 0),		
    OC(ld_d_iyl, 2, 8, 0),		
    OC(ld_d_iyd, 3, 19, 0),		
    OC(ld_d_a, 2, 8, 0),		
    OC(ld_e_b, 2, 8, 0),		
    OC(ld_e_c, 2, 8, 0),		
    OC(ld_e_d, 2, 8, 0),		
    OC(ld_e_e, 2, 8, 0),		
    OC(ld_e_iyh, 2, 8, 0),		
    OC(ld_e_iyl, 2, 8, 0),		
    OC(ld_e_iyd, 3, 19, 0),		
    OC(ld_e_a, 2, 8, 0),		
    OC(ld_iyh_b, 2, 8, 0),		
    OC(ld_iyh_c, 2, 8, 0),		
    OC(ld_iyh_d, 2, 8, 0),		
    OC(ld_iyh_e, 2, 8, 0),		
    OC(ld_iyh_iyh, 2, 8, 0),		
    OC(ld_iyh_iyl, 2, 8, 0),		
    OC(ld_h_iyd, 3, 19, 0),		
    OC(ld_iyh_a, 2, 8, 0),		
    OC(ld_iyl_b, 2, 8, 0),		
    OC(ld_iyl_c, 2, 8, 0),		
    OC(ld_iyl_d, 2, 8, 0),		
    OC(ld_iyl_e, 2, 8, 0),		
    OC(ld_iyl_iyh, 2, 8, 0),		
    OC(ld_iyl_iyl, 2, 8, 0),		
    OC(ld_l_iyd, 3, 19, 0),		
    OC(ld_iyl_a, 2, 8, 0),		
    OC(ld_iyd_b, 3, 19, 0),		
    OC(ld_iyd_c, 3, 19, 0),		
    OC(ld_iyd_d, 3, 19, 0),		
    OC(ld_iyd_e, 3, 19, 0),		
    OC(ld_iyd_h, 3, 19, 0),		
    OC(ld_iyd_l, 3, 19, 0),		
    OC_LITE(not_imp),		
    OC(ld_iyd_a, 3, 19, 0),		
    OC(ld_a_b, 2, 8, 0),		
    OC(ld_a_c, 2, 8, 0),		
    OC(ld_a_d, 2, 8, 0),		
    OC(ld_a_e, 2, 8, 0),		
    OC(ld_a_iyh, 2, 8, 0),		
    OC(ld_a_iyl, 2, 8, 0),		
    OC(ld_a_iyd, 3, 19, 0),		
    OC(ld_a_a, 2, 8, 0),		
    OC(add_a_b, 2, 8, 0),		
    OC(add_a_c, 2, 8, 0),		
    OC(add_a_d, 2, 8, 0),		
    OC(add_a_e, 2, 8, 0),		
    OC(add_a_iyh, 2, 8, 0),		
    OC(add_a_iyl, 2, 8, 0),		
    OC(add_a_iyd, 3, 19, 0),		
    OC(add_a_a, 2, 8, 0),		
    OC(adc_a_b, 2, 8, 0),		
    OC(adc_a_c, 2, 8, 0),		
    OC(adc_a_d, 2, 8, 0),		
    OC(adc_a_e, 2, 8, 0),		
    OC(adc_a_iyh, 2, 8, 0),		
    OC(adc_a_iyl, 2, 8, 0),		
    OC(adc_a_iyd, 3, 19, 0),		
    OC(adc_a_a, 2, 8, 0),		
    OC(sub_b, 2, 8, 0),		
    OC(sub_c, 2, 8, 0),		
    OC(sub_d, 2, 8, 0),		
    OC(sub_e, 2, 8, 0),		
    OC(sub_iyh, 2, 8, 0),		
    OC(sub_iyl, 2, 8, 0),		
    OC(sub_iyd, 3, 19, 0),		
    OC(sub_a, 2, 8, 0),		
    OC(sbc_a_b, 2, 8, 0),		
    OC(sbc_a_c, 2, 8, 0),		
    OC(sbc_a_d, 2, 8, 0),		
    OC(sbc_a_e, 2, 8, 0),		
    OC(sbc_a_iyh, 2, 8, 0),		
    OC(sbc_a_iyl, 2, 8, 0),		
    OC(sbc_a_iyd, 3, 19, 0),		
    OC(sbc_a_a, 2, 8, 0),		
    OC(and_b, 2, 8, 0),		
    OC(and_c, 2, 8, 0),		
    OC(and_d, 2, 8, 0),		
    OC(and_e, 2, 8, 0),		
    OC(and_iyh, 2, 8, 0),		
    OC(and_iyl, 2, 8, 0),		
    OC(and_iyd, 3, 19, 0),		
    OC(and_a, 2, 8, 0),		
    OC(xor_b, 2, 8, 0),		
    OC(xor_c, 2, 8, 0),		
    OC(xor_d, 2, 8, 0),		
    OC(xor_e, 2, 8, 0),		
    OC(xor_iyh, 2, 8, 0),		
    OC(xor_iyl, 2, 8, 0),		
    OC(xor_iyd, 3, 19, 0),		
    OC(xor_a, 2, 8, 0),		
    OC(or_b, 2, 8, 0),		
    OC(or_c, 2, 8, 0),		
    OC(or_d, 2, 8, 0),		
    OC(or_e, 2, 8, 0),		
    OC(or_iyh, 2, 8, 0),		
    OC(or_iyl, 2, 8, 0),		
    OC(or_iyd, 3, 19, 0),		
    OC(or_a, 2, 8, 0),		
    OC(cp_b, 2, 8, 0),		
    OC(cp_c, 2, 8, 0),		
    OC(cp_d, 2, 8, 0),		
    OC(cp_e, 2, 8, 0),		
    OC(cp_iyh, 2, 8, 0),		
    OC(cp_iyl, 2, 8, 0),		
    OC(cp_iyd, 3, 19, 0),		
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
    OC(pop_iy, 2, 14, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(push_iy, 2, 15, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC(jp_iy, 2, 8, 0),		
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
    OC(ld_sp_iy, 2, 10, 0),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp),		
    OC_LITE(not_imp)
};

Opcode iyBitOpcodePtrs[256] = {
    // 00 - 0F
    OC(rlc_iyd_b, 4, 23, 0),		
    OC(rlc_iyd_c, 4, 23, 0),		
    OC(rlc_iyd_d, 4, 23, 0),		
    OC(rlc_iyd_e, 4, 23, 0),		
    OC(rlc_iyd_h, 4, 23, 0),		
    OC(rlc_iyd_l, 4, 23, 0),		
    OC(rlc_iyd, 4, 23, 0),		
    OC(rlc_iyd_a, 4, 23, 0),		
    OC(rrc_iyd_b, 4, 23, 0),		
    OC(rrc_iyd_c, 4, 23, 0),		
    OC(rrc_iyd_d, 4, 23, 0),		
    OC(rrc_iyd_e, 4, 23, 0),		
    OC(rrc_iyd_h, 4, 23, 0),		
    OC(rrc_iyd_l, 4, 23, 0),		
    OC(rrc_iyd, 4, 23, 0),		
    OC(rrc_iyd_a, 4, 23, 0),		

    // 10 - 1F
    OC(rl_iyd_b, 4, 23, 0),		
    OC(rl_iyd_c, 4, 23, 0),		
    OC(rl_iyd_d, 4, 23, 0),		
    OC(rl_iyd_e, 4, 23, 0),		
    OC(rl_iyd_h, 4, 23, 0),		
    OC(rl_iyd_l, 4, 23, 0),		
    OC(rl_iyd, 4, 23, 0),		
    OC(rl_iyd_a, 4, 23, 0),		
    OC(rr_iyd_b, 4, 23, 0),		
    OC(rr_iyd_c, 4, 23, 0),		
    OC(rr_iyd_d, 4, 23, 0),		
    OC(rr_iyd_e, 4, 23, 0),		
    OC(rr_iyd_h, 4, 23, 0),		
    OC(rr_iyd_l, 4, 23, 0),		
    OC(rr_iyd, 4, 23, 0),		
    OC(rr_iyd_a, 4, 23, 0),

    // 20 - 2F		
    OC(sla_iyd_b, 4, 23, 0),		
    OC(sla_iyd_c, 4, 23, 0),		
    OC(sla_iyd_d, 4, 23, 0),		
    OC(sla_iyd_e, 4, 23, 0),		
    OC(sla_iyd_h, 4, 23, 0),		
    OC(sla_iyd_l, 4, 23, 0),		
    OC(sla_iyd, 4, 23, 0),		
    OC(sla_iyd_a, 4, 23, 0),		
    OC(sra_iyd_b, 4, 23, 0),		
    OC(sra_iyd_c, 4, 23, 0),		
    OC(sra_iyd_d, 4, 23, 0),		
    OC(sra_iyd_e, 4, 23, 0),		
    OC(sra_iyd_h, 4, 23, 0),		
    OC(sra_iyd_l, 4, 23, 0),		
    OC(sra_iyd, 4, 23, 0),		
    OC(sra_iyd_a, 4, 23, 0),	

    // 30 - 3F	
    OC(sll_iyd_b, 4, 23, 0),		
    OC(sll_iyd_c, 4, 23, 0),		
    OC(sll_iyd_d, 4, 23, 0),		
    OC(sll_iyd_e, 4, 23, 0),		
    OC(sll_iyd_h, 4, 23, 0),		
    OC(sll_iyd_l, 4, 23, 0),		
    OC(sll_iyd, 4, 23, 0),		
    OC(sll_iyd_a, 4, 23, 0),		
    OC(srl_iyd_b, 4, 23, 0),		
    OC(srl_iyd_c, 4, 23, 0),		
    OC(srl_iyd_d, 4, 23, 0),		
    OC(srl_iyd_e, 4, 23, 0),		
    OC(srl_iyd_h, 4, 23, 0),		
    OC(srl_iyd_l, 4, 23, 0),		
    OC(srl_iyd, 4, 23, 0),		
    OC(srl_iyd_a, 4, 23, 0),

    // 40 - 4F		
    OC(bit_0_iyd, 4, 20, 0),		
    OC(bit_0_iyd, 4, 20, 0),		
    OC(bit_0_iyd, 4, 20, 0),		
    OC(bit_0_iyd, 4, 20, 0),		
    OC(bit_0_iyd, 4, 20, 0),		
    OC(bit_0_iyd, 4, 20, 0),		
    OC(bit_0_iyd, 4, 20, 0),		
    OC(bit_0_iyd, 4, 20, 0),		
    OC(bit_1_iyd, 4, 20, 0),		
    OC(bit_1_iyd, 4, 20, 0),		
    OC(bit_1_iyd, 4, 20, 0),		
    OC(bit_1_iyd, 4, 20, 0),		
    OC(bit_1_iyd, 4, 20, 0),		
    OC(bit_1_iyd, 4, 20, 0),		
    OC(bit_1_iyd, 4, 20, 0),		
    OC(bit_1_iyd, 4, 20, 0),

    // 50 - 5F		
    OC(bit_2_iyd, 4, 20, 0),		
    OC(bit_2_iyd, 4, 20, 0),		
    OC(bit_2_iyd, 4, 20, 0),		
    OC(bit_2_iyd, 4, 20, 0),		
    OC(bit_2_iyd, 4, 20, 0),		
    OC(bit_2_iyd, 4, 20, 0),		
    OC(bit_2_iyd, 4, 20, 0),		
    OC(bit_2_iyd, 4, 20, 0),		
    OC(bit_3_iyd, 4, 20, 0),		
    OC(bit_3_iyd, 4, 20, 0),		
    OC(bit_3_iyd, 4, 20, 0),		
    OC(bit_3_iyd, 4, 20, 0),		
    OC(bit_3_iyd, 4, 20, 0),		
    OC(bit_3_iyd, 4, 20, 0),		
    OC(bit_3_iyd, 4, 20, 0),		
    OC(bit_3_iyd, 4, 20, 0),

    // 60 - 6F		
    OC(bit_4_iyd, 4, 20, 0),		
    OC(bit_4_iyd, 4, 20, 0),		
    OC(bit_4_iyd, 4, 20, 0),		
    OC(bit_4_iyd, 4, 20, 0),		
    OC(bit_4_iyd, 4, 20, 0),		
    OC(bit_4_iyd, 4, 20, 0),		
    OC(bit_4_iyd, 4, 20, 0),		
    OC(bit_4_iyd, 4, 20, 0),		
    OC(bit_5_iyd, 4, 20, 0),		
    OC(bit_5_iyd, 4, 20, 0),		
    OC(bit_5_iyd, 4, 20, 0),		
    OC(bit_5_iyd, 4, 20, 0),		
    OC(bit_5_iyd, 4, 20, 0),		
    OC(bit_5_iyd, 4, 20, 0),		
    OC(bit_5_iyd, 4, 20, 0),		
    OC(bit_5_iyd, 4, 20, 0),

    // 70 - 7F		
    OC(bit_6_iyd, 4, 20, 0),		
    OC(bit_6_iyd, 4, 20, 0),		
    OC(bit_6_iyd, 4, 20, 0),		
    OC(bit_6_iyd, 4, 20, 0),		
    OC(bit_6_iyd, 4, 20, 0),		
    OC(bit_6_iyd, 4, 20, 0),		
    OC(bit_6_iyd, 4, 20, 0),		
    OC(bit_6_iyd, 4, 20, 0),		
    OC(bit_7_iyd, 4, 20, 0),		
    OC(bit_7_iyd, 4, 20, 0),		
    OC(bit_7_iyd, 4, 20, 0),		
    OC(bit_7_iyd, 4, 20, 0),		
    OC(bit_7_iyd, 4, 20, 0),		
    OC(bit_7_iyd, 4, 20, 0),		
    OC(bit_7_iyd, 4, 20, 0),		
    OC(bit_7_iyd, 4, 20, 0),

    // 80 - 8F		
    OC(res_0_iyd_b, 4, 23, 0),		
    OC(res_0_iyd_c, 4, 23, 0),		
    OC(res_0_iyd_d, 4, 23, 0),		
    OC(res_0_iyd_e, 4, 23, 0),		
    OC(res_0_iyd_h, 4, 23, 0),		
    OC(res_0_iyd_l, 4, 23, 0),		
    OC(res_0_iyd, 4, 23, 0),		
    OC(res_0_iyd_a, 4, 23, 0),		
    OC(res_1_iyd_b, 4, 23, 0),		
    OC(res_1_iyd_c, 4, 23, 0),		
    OC(res_1_iyd_d, 4, 23, 0),		
    OC(res_1_iyd_e, 4, 23, 0),		
    OC(res_1_iyd_h, 4, 23, 0),		
    OC(res_1_iyd_l, 4, 23, 0),		
    OC(res_1_iyd, 4, 23, 0),		
    OC(res_1_iyd_a, 4, 23, 0),		

    // 90 - 9F
    OC(res_2_iyd_b, 4, 23, 0),		
    OC(res_2_iyd_c, 4, 23, 0),		
    OC(res_2_iyd_d, 4, 23, 0),		
    OC(res_2_iyd_e, 4, 23, 0),		
    OC(res_2_iyd_h, 4, 23, 0),		
    OC(res_2_iyd_l, 4, 23, 0),		
    OC(res_2_iyd, 4, 23, 0),		
    OC(res_2_iyd_a, 4, 23, 0),		
    OC(res_3_iyd_b, 4, 23, 0),		
    OC(res_3_iyd_c, 4, 23, 0),		
    OC(res_3_iyd_d, 4, 23, 0),		
    OC(res_3_iyd_e, 4, 23, 0),		
    OC(res_3_iyd_h, 4, 23, 0),		
    OC(res_3_iyd_l, 4, 23, 0),		
    OC(res_3_iyd, 4, 23, 0),		
    OC(res_3_iyd_a, 4, 23, 0),		

    // A0 - AF
    OC(res_4_iyd_b, 4, 23, 0),		
    OC(res_4_iyd_c, 4, 23, 0),		
    OC(res_4_iyd_d, 4, 23, 0),		
    OC(res_4_iyd_e, 4, 23, 0),		
    OC(res_4_iyd_h, 4, 23, 0),		
    OC(res_4_iyd_l, 4, 23, 0),		
    OC(res_4_iyd, 4, 23, 0),		
    OC(res_4_iyd_a, 4, 23, 0),		
    OC(res_5_iyd_b, 4, 23, 0),		
    OC(res_5_iyd_c, 4, 23, 0),		
    OC(res_5_iyd_d, 4, 23, 0),		
    OC(res_5_iyd_e, 4, 23, 0),		
    OC(res_5_iyd_h, 4, 23, 0),		
    OC(res_5_iyd_l, 4, 23, 0),		
    OC(res_5_iyd, 4, 23, 0),		
    OC(res_5_iyd_a, 4, 23, 0),	

    // B0 - BF	
    OC(res_6_iyd_b, 4, 23, 0),		
    OC(res_6_iyd_c, 4, 23, 0),		
    OC(res_6_iyd_d, 4, 23, 0),		
    OC(res_6_iyd_e, 4, 23, 0),		
    OC(res_6_iyd_h, 4, 23, 0),		
    OC(res_6_iyd_l, 4, 23, 0),		
    OC(res_6_iyd, 4, 23, 0),		
    OC(res_6_iyd_a, 4, 23, 0),		
    OC(res_7_iyd_b, 4, 23, 0),		
    OC(res_7_iyd_c, 4, 23, 0),		
    OC(res_7_iyd_d, 4, 23, 0),		
    OC(res_7_iyd_e, 4, 23, 0),		
    OC(res_7_iyd_h, 4, 23, 0),		
    OC(res_7_iyd_l, 4, 23, 0),		
    OC(res_7_iyd, 4, 23, 0),		
    OC(res_7_iyd_a, 4, 23, 0),	

    // C0 - CF	
    OC(set_0_iyd_b, 4, 23, 0),		
    OC(set_0_iyd_c, 4, 23, 0),		
    OC(set_0_iyd_d, 4, 23, 0),		
    OC(set_0_iyd_e, 4, 23, 0),		
    OC(set_0_iyd_h, 4, 23, 0),		
    OC(set_0_iyd_l, 4, 23, 0),		
    OC(set_0_iyd, 4, 23, 0),		
    OC(set_0_iyd_a, 4, 23, 0),		
    OC(set_1_iyd_b, 4, 23, 0),		
    OC(set_1_iyd_c, 4, 23, 0),		
    OC(set_1_iyd_d, 4, 23, 0),		
    OC(set_1_iyd_e, 4, 23, 0),		
    OC(set_1_iyd_h, 4, 23, 0),		
    OC(set_1_iyd_l, 4, 23, 0),		
    OC(set_1_iyd, 4, 23, 0),		
    OC(set_1_iyd_a, 4, 23, 0),		

    // D0 - DF
    OC(set_2_iyd_b, 4, 23, 0),		
    OC(set_2_iyd_c, 4, 23, 0),		
    OC(set_2_iyd_d, 4, 23, 0),		
    OC(set_2_iyd_e, 4, 23, 0),		
    OC(set_2_iyd_h, 4, 23, 0),		
    OC(set_2_iyd_l, 4, 23, 0),		
    OC(set_2_iyd, 4, 23, 0),		
    OC(set_2_iyd_a, 4, 23, 0),		
    OC(set_3_iyd_b, 4, 23, 0),		
    OC(set_3_iyd_c, 4, 23, 0),		
    OC(set_3_iyd_d, 4, 23, 0),		
    OC(set_3_iyd_e, 4, 23, 0),		
    OC(set_3_iyd_h, 4, 23, 0),		
    OC(set_3_iyd_l, 4, 23, 0),		
    OC(set_3_iyd, 4, 23, 0),		
    OC(set_3_iyd_a, 4, 23, 0),

    // E0 - EF		
    OC(set_4_iyd_b, 4, 23, 0),		
    OC(set_4_iyd_c, 4, 23, 0),		
    OC(set_4_iyd_d, 4, 23, 0),		
    OC(set_4_iyd_e, 4, 23, 0),		
    OC(set_4_iyd_h, 4, 23, 0),		
    OC(set_4_iyd_l, 4, 23, 0),		
    OC(set_4_iyd, 4, 23, 0),		
    OC(set_4_iyd_a, 4, 23, 0),		
    OC(set_5_iyd_b, 4, 23, 0),		
    OC(set_5_iyd_c, 4, 23, 0),		
    OC(set_5_iyd_d, 4, 23, 0),		
    OC(set_5_iyd_e, 4, 23, 0),		
    OC(set_5_iyd_h, 4, 23, 0),		
    OC(set_5_iyd_l, 4, 23, 0),		
    OC(set_5_iyd, 4, 23, 0),		
    OC(set_5_iyd_a, 4, 23, 0),		

    // F0 - FF
    OC(set_6_iyd_b, 4, 23, 0),		
    OC(set_6_iyd_c, 4, 23, 0),		
    OC(set_6_iyd_d, 4, 23, 0),		
    OC(set_6_iyd_e, 4, 23, 0),		
    OC(set_6_iyd_h, 4, 23, 0),		
    OC(set_6_iyd_l, 4, 23, 0),		
    OC(set_6_iyd, 4, 23, 0),		
    OC(set_6_iyd_a, 4, 23, 0),		
    OC(set_7_iyd_b, 4, 23, 0),		
    OC(set_7_iyd_c, 4, 23, 0),		
    OC(set_7_iyd_d, 4, 23, 0),		
    OC(set_7_iyd_e, 4, 23, 0),		
    OC(set_7_iyd_h, 4, 23, 0),		
    OC(set_7_iyd_l, 4, 23, 0),		
    OC(set_7_iyd, 4, 23, 0),		
    OC(set_7_iyd_a, 4, 23, 0)	
};

void add_iy_bc() {
    execute16BitAdd(z80.bc, &z80.iy, false);
}

void add_iy_de() {
    execute16BitAdd(z80.de, &z80.iy, false);    
}

void add_iy_iy() {
    execute16BitAdd(z80.iy, &z80.iy, false);    
}

void add_iy_sp() {
    execute16BitAdd(z80.sp, &z80.iy, false);    
}

void ld_iy_nn() {
    z80.iy = memReadFunc(z80.pc - 2);
    z80.iy += memReadFunc(z80.pc - 1) << 8;   
}

void ld_nni_iy() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    memWriteFunc(address, z80.iy & 0x00FF);
    memWriteFunc(address + 1, (z80.iy >> 8) & 0x00FF);
}

void inc_iy() {
    z80.iy++;
}

void inc_iyh() {
    uint8_t old = z80.iyh++;

    // carry flag unaffected
    z80.flags.n     = 0;
    z80.flags.pv    = old == 0x7F;
    z80.flags.h     = (old & 0x0F) == 0x0F;   
    z80.flags.z     = z80.iyh == 0x00;
    z80.flags.s     = (z80.iyh & 0x80) != 0;    
}

void dec_iyh() {
    uint8_t old = z80.iyh--;

    // carry flag unaffected
    z80.flags.n     = 1;
    z80.flags.pv    = old == 0x80;
    z80.flags.h     = (old & 0x0F) == 0x00;   
    z80.flags.z     = z80.iyh == 0x00;
    z80.flags.s     = (z80.iyh & 0x80) != 0;
}

void dec_iy() {
    z80.iy--;
}

void inc_iyl() {
    uint8_t old = z80.iyl++;

    // carry flag unaffected
    z80.flags.n     = 0;
    z80.flags.pv    = old == 0x7F;
    z80.flags.h     = (old & 0x0F) == 0x0F;   
    z80.flags.z     = z80.iyl == 0x00;
    z80.flags.s     = (z80.iyl & 0x80) != 0;    
}

void dec_iyl() {
    uint8_t old = z80.iyl--;

    // carry flag unaffected
    z80.flags.n     = 1;
    z80.flags.pv    = old == 0x80;
    z80.flags.h     = (old & 0x0F) == 0x00;   
    z80.flags.z     = z80.iyl == 0x00;
    z80.flags.s     = (z80.iyl & 0x80) != 0;
}

void ld_iyh_n() {
    uint8_t n = memReadFunc(z80.pc - 1);
   z80.iyh = n;    
}

void ld_iy_nni() {
    uint16_t address = memReadFunc(z80.pc - 2) + (memReadFunc(z80.pc - 1) << 8);
    z80.iy = memReadFunc(address) + (memReadFunc(address + 1) << 8);    
}

void ld_iyl_n() {
    uint8_t n = memReadFunc(z80.pc - 1);
    z80.iyl = n;   
}

void inc_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.iy + d);
    executeInc(&n);
    memWriteFunc(z80.iy + d, n);
}

void dec_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.iy + d);
    executeDec(&n);
    memWriteFunc(z80.iy + d, n);
}

void ld_iyd_n() {
    int8_t d = memReadFunc(z80.pc - 2);
    int8_t n = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.iy + d, n);
}

void ld_b_iyh() {
    z80.b = z80.iyh;
}

void ld_b_iyl() {
    z80.b = z80.iyl;    
}

void ld_b_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.b = memReadFunc(z80.iy + d);
}

void ld_c_iyh() {
    z80.c = z80.iyh;
}

void ld_c_iyl() {
    z80.c = z80.iyl;    
}

void ld_c_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.c = memReadFunc(z80.iy + d);
}

void ld_d_iyh() {
    z80.d = z80.iyh;
}

void ld_d_iyl() {
    z80.d = z80.iyl;    
}

void ld_d_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.d = memReadFunc(z80.iy + d);
}

void ld_e_iyh() {
    z80.e = z80.iyh;
}

void ld_e_iyl() {
    z80.e = z80.iyl;    
}

void ld_e_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.e = memReadFunc(z80.iy + d);
}

void ld_iyd_b() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.iy + d, z80.b);
}

void ld_iyd_c() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.iy + d, z80.c);
}

void ld_iyd_d() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.iy + d, z80.d);
}

void ld_iyd_e() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.iy + d, z80.e);
}

void ld_iyd_h() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.iy + d, z80.h);
}

void ld_iyd_l() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.iy + d, z80.l);
}

void ld_iyd_a() {
    int8_t d = memReadFunc(z80.pc - 1);
    memWriteFunc(z80.iy + d, z80.a);
}

void ld_iyh_b() {
    z80.iyh = z80.b;
}

void ld_iyh_c() {
    z80.iyh = z80.c;	
}

void ld_iyh_d() {
    z80.iyh = z80.d;		
}

void ld_iyh_e() {
    z80.iyh = z80.e;		
}

void ld_iyh_iyh() {
    z80.iyh = z80.iyh;		
}

void ld_iyh_iyl() {
    z80.iyh = z80.iyl;		
}

void ld_h_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.h = memReadFunc(z80.iy + d);
}

void ld_iyh_a() {
    z80.iyh = z80.a;		
}

void ld_iyl_b() {
    z80.iyl = z80.b;		
}

void ld_iyl_c() {
    z80.iyl = z80.c;		
}

void ld_iyl_d() {
    z80.iyl = z80.d;		
}

void ld_iyl_e() {
    z80.iyl = z80.e;		
}

void ld_iyl_iyh() {
    z80.iyl = z80.iyh;		
}

void ld_iyl_iyl() {
    z80.iyl = z80.iyl;		
}

void ld_l_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.l = memReadFunc(z80.iy + d);
}

void ld_iyl_a() {
    z80.iyl = z80.a;		
}

void ld_a_iyh() {
    z80.a = z80.iyh;		
}

void ld_a_iyl() {
    z80.a = z80.iyl;
}

void ld_a_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    z80.a = memReadFunc(z80.iy + d);
}

void add_a_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.iy + d);
    execute8BitAdd(n, 0);
}

void adc_a_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.iy + d);
    execute8BitAdd(n, z80.flags.c);
}

void sub_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.iy + d);
    execute8BitSub(n, 0, 1);
}

void sbc_a_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.iy + d);
    execute8BitSub(n, z80.flags.c, 1);
}

void and_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.iy + d);
    executeLogical(n, AND);
}

void xor_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.iy + d);
    executeLogical(n, XOR);
}

void or_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.iy + d);
    executeLogical(n, OR);
}

void cp_iyd() {
    int8_t d = memReadFunc(z80.pc - 1);
    uint8_t n = memReadFunc(z80.iy + d);
    execute8BitSub(n, 0, 0);
}

void add_a_iyh() {
    execute8BitAdd(z80.iyh, 0);
}

void add_a_iyl() {
    execute8BitAdd(z80.iyl, 0);
}

void adc_a_iyh() {
    execute8BitAdd(z80.iyh, z80.flags.c);
}

void adc_a_iyl() {
    execute8BitAdd(z80.iyl, z80.flags.c);
}

void sub_iyh() {
    execute8BitSub(z80.iyh, 0, true);
}

void sub_iyl() {
    execute8BitSub(z80.iyl, 0, true);
}

void sbc_a_iyh() {
    execute8BitSub(z80.iyh, z80.flags.c, true);
}

void sbc_a_iyl() {
    execute8BitSub(z80.iyl, z80.flags.c, true);
}

void and_iyh() {
    executeLogical(z80.iyh, AND);
}

void and_iyl() {
    executeLogical(z80.iyl, AND);
}

void xor_iyh() {
    executeLogical(z80.iyh, XOR);
}

void xor_iyl() {
    executeLogical(z80.iyl, XOR);
}

void or_iyh() {
    executeLogical(z80.iyh, OR);
}

void or_iyl() {
    executeLogical(z80.iyl, OR);
}

void cp_iyh() {
    execute8BitSub(z80.iyh, 0, 0);
}

void cp_iyl() {
    execute8BitSub(z80.iyl, 0, 0);
}

void pop_iy() {
    z80.iy = pop();
}

void push_iy() {
    push(z80.iy);
}

void jp_iy() {
    z80.pc = z80.iy;
}

void ld_sp_iy() {
    z80.sp = z80.iy;
}

    /* ================================================================ */
    /*             IY BIT INSTRUCTIONS (0xDD 0xCB)                      */
    /* ================================================================ */

void rlc_iyd_b() {
    executeXYRotateLeft(z80.iy, &z80.b, true);
}

void rlc_iyd_c() {
    executeXYRotateLeft(z80.iy, &z80.c, true);
}

void rlc_iyd_d() {
    executeXYRotateLeft(z80.iy, &z80.d, true);
}

void rlc_iyd_e() {
    executeXYRotateLeft(z80.iy, &z80.e, true);
}

void rlc_iyd_h() {
    executeXYRotateLeft(z80.iy, &z80.h, true);
}

void rlc_iyd_l() {
    executeXYRotateLeft(z80.iy, &z80.l, true);
}

void rlc_iyd() {
    executeXYRotateLeft(z80.iy, NULL, true);
}

void rlc_iyd_a() {
    executeXYRotateLeft(z80.iy, &z80.a, true);
}

void rrc_iyd_b() {
    executeXYRotateRight(z80.iy, &z80.b, true);
}

void rrc_iyd_c() {
    executeXYRotateRight(z80.iy, &z80.c, true);
}
void rrc_iyd_d() {
    executeXYRotateRight(z80.iy, &z80.d, true);
}

void rrc_iyd_e() {
    executeXYRotateRight(z80.iy, &z80.e, true);
}

void rrc_iyd_h() {
    executeXYRotateRight(z80.iy, &z80.h, true);
}

void rrc_iyd_l() {
    executeXYRotateRight(z80.iy, &z80.l, true);
}

void rrc_iyd() {
    executeXYRotateRight(z80.iy, NULL, true);
}

void rrc_iyd_a() {
    executeXYRotateRight(z80.iy, &z80.a, true);
}

void rl_iyd_b() {
    executeXYRotateLeft(z80.iy, &z80.b, false);
}

void rl_iyd_c() {
    executeXYRotateLeft(z80.iy, &z80.c, false);
}

void rl_iyd_d() {
    executeXYRotateLeft(z80.iy, &z80.d, false);
}

void rl_iyd_e() {
    executeXYRotateLeft(z80.iy, &z80.e, false);
}

void rl_iyd_h() {
    executeXYRotateLeft(z80.iy, &z80.h, false);
}
void rl_iyd_l() {
    executeXYRotateLeft(z80.iy, &z80.l, false);
}
void rl_iyd() {
    executeXYRotateLeft(z80.iy, NULL, false);
}
void rl_iyd_a() {
    executeXYRotateLeft(z80.iy, &z80.a, false);
}

void rr_iyd_b() {
    executeXYRotateRight(z80.iy, &z80.b, false);
}

void rr_iyd_c() {
    executeXYRotateRight(z80.iy, &z80.c, false);
}
void rr_iyd_d() {
    executeXYRotateRight(z80.iy, &z80.d, false);
}

void rr_iyd_e() {
    executeXYRotateRight(z80.iy, &z80.e, false);
}

void rr_iyd_h() {
    executeXYRotateRight(z80.iy, &z80.h, false);
}

void rr_iyd_l() {
    executeXYRotateRight(z80.iy, &z80.l, false);
}

void rr_iyd() {
    executeXYRotateRight(z80.iy, NULL, false);
}

void rr_iyd_a() {
    executeXYRotateRight(z80.iy, &z80.a, false);
}

void sla_iyd_b() {
    executeXYShiftLeft(z80.iy, &z80.b, true);
}

void sla_iyd_c() {
    executeXYShiftLeft(z80.iy, &z80.c, true);
}

void sla_iyd_d() {
    executeXYShiftLeft(z80.iy, &z80.d, true);
}

void sla_iyd_e() {
    executeXYShiftLeft(z80.iy, &z80.e, true);
}

void sla_iyd_h() {
    executeXYShiftLeft(z80.iy, &z80.h, true);
}

void sla_iyd_l() {
    executeXYShiftLeft(z80.iy, &z80.l, true);
}
void sla_iyd() {
    executeXYShiftLeft(z80.iy, NULL, true);
}
void sla_iyd_a() {
    executeXYShiftLeft(z80.iy, &z80.a, true);
}

void sra_iyd_b() {
    executeXYShiftRight(z80.iy, &z80.b, true);
}

void sra_iyd_c() {
    executeXYShiftRight(z80.iy, &z80.c, true);
}

void sra_iyd_d() {
    executeXYShiftRight(z80.iy, &z80.d, true);
}

void sra_iyd_e() {
    executeXYShiftRight(z80.iy, &z80.e, true);
}

void sra_iyd_h() {
    executeXYShiftRight(z80.iy, &z80.h, true);
}

void sra_iyd_l() {
    executeXYShiftRight(z80.iy, &z80.l, true);
}

void sra_iyd() {
    executeXYShiftRight(z80.iy, NULL, true);
}

void sra_iyd_a() {
    executeXYShiftRight(z80.iy, &z80.a, true);
}

void sll_iyd_b() {
    executeXYShiftLeft(z80.iy, &z80.b, false);
}

void sll_iyd_c() {
    executeXYShiftLeft(z80.iy, &z80.c, false);
}

void sll_iyd_d() {
    executeXYShiftLeft(z80.iy, &z80.d, false);
}

void sll_iyd_e() {
    executeXYShiftLeft(z80.iy, &z80.e, false);
}

void sll_iyd_h() {
    executeXYShiftLeft(z80.iy, &z80.h, false);
}

void sll_iyd_l() {
    executeXYShiftLeft(z80.iy, &z80.l, false);
}
void sll_iyd() {
    executeXYShiftLeft(z80.iy, NULL, false);
}
void sll_iyd_a() {
    executeXYShiftLeft(z80.iy, &z80.a, false);
}

void srl_iyd_b() {
    executeXYShiftRight(z80.iy, &z80.b, false);
}

void srl_iyd_c() {
    executeXYShiftRight(z80.iy, &z80.c, false);
}

void srl_iyd_d() {
    executeXYShiftRight(z80.iy, &z80.d, false);
}

void srl_iyd_e() {
    executeXYShiftRight(z80.iy, &z80.e, false);
}

void srl_iyd_h() {
    executeXYShiftRight(z80.iy, &z80.h, false);
}

void srl_iyd_l() {
    executeXYShiftRight(z80.iy, &z80.l, false);
}

void srl_iyd() {
    executeXYShiftRight(z80.iy, NULL, false);
}

void srl_iyd_a() {
    executeXYShiftRight(z80.iy, &z80.a, false);
}

void bit_0_iyd() {
    executeXYBit(z80.iy, 0);
}

void bit_1_iyd() {
    executeXYBit(z80.iy, 1);
}

void bit_2_iyd() {
    executeXYBit(z80.iy, 2);
}

void bit_3_iyd() {
    executeXYBit(z80.iy, 3);
}

void bit_4_iyd() {
    executeXYBit(z80.iy, 4);
}

void bit_5_iyd() {
    executeXYBit(z80.iy, 5);
}

void bit_6_iyd() {
    executeXYBit(z80.iy, 6);
}

void bit_7_iyd() {
    executeXYBit(z80.iy, 7);
}

void res_0_iyd_b() {
	executeXYReset(z80.iy, 0, &z80.b);
}
void res_0_iyd_c() {
	executeXYReset(z80.iy, 0, &z80.c);
}
void res_0_iyd_d() {
	executeXYReset(z80.iy, 0, &z80.d);
}
void res_0_iyd_e() {
	executeXYReset(z80.iy, 0, &z80.e);
}
void res_0_iyd_h() {
	executeXYReset(z80.iy, 0, &z80.h);
}
void res_0_iyd_l() {
	executeXYReset(z80.iy, 0, &z80.l);
}
void res_0_iyd() {
	executeXYReset(z80.iy, 0, NULL);
}
void res_0_iyd_a() {
	executeXYReset(z80.iy, 0, &z80.a);
}
void res_1_iyd_b() {
	executeXYReset(z80.iy, 1, &z80.b);
}
void res_1_iyd_c() {
	executeXYReset(z80.iy, 1, &z80.c);
}
void res_1_iyd_d() {
	executeXYReset(z80.iy, 1, &z80.d);
}
void res_1_iyd_e() {
	executeXYReset(z80.iy, 1, &z80.e);
}
void res_1_iyd_h() {
	executeXYReset(z80.iy, 1, &z80.h);
}
void res_1_iyd_l() {
	executeXYReset(z80.iy, 1, &z80.l);
}
void res_1_iyd() {
	executeXYReset(z80.iy, 1, NULL);
}
void res_1_iyd_a() {
	executeXYReset(z80.iy, 1, &z80.a);
}
void res_2_iyd_b() {
	executeXYReset(z80.iy, 2, &z80.b);
}
void res_2_iyd_c() {
	executeXYReset(z80.iy, 2, &z80.c);
}
void res_2_iyd_d() {
	executeXYReset(z80.iy, 2, &z80.d);
}
void res_2_iyd_e() {
	executeXYReset(z80.iy, 2, &z80.e);
}
void res_2_iyd_h() {
	executeXYReset(z80.iy, 2, &z80.h);
}
void res_2_iyd_l() {
	executeXYReset(z80.iy, 2, &z80.l);
}
void res_2_iyd() {
	executeXYReset(z80.iy, 2, NULL);
}
void res_2_iyd_a() {
	executeXYReset(z80.iy, 2, &z80.a);
}
void res_3_iyd_b() {
	executeXYReset(z80.iy, 3, &z80.b);
}
void res_3_iyd_c() {
	executeXYReset(z80.iy, 3, &z80.c);
}
void res_3_iyd_d() {
	executeXYReset(z80.iy, 3, &z80.d);
}
void res_3_iyd_e() {
	executeXYReset(z80.iy, 3, &z80.e);
}
void res_3_iyd_h() {
	executeXYReset(z80.iy, 3, &z80.h);
}
void res_3_iyd_l() {
	executeXYReset(z80.iy, 3, &z80.l);
}
void res_3_iyd() {
	executeXYReset(z80.iy, 3, NULL);
}
void res_3_iyd_a() {
	executeXYReset(z80.iy, 3, &z80.a);
}
void res_4_iyd_b() {
	executeXYReset(z80.iy, 4, &z80.b);
}
void res_4_iyd_c() {
	executeXYReset(z80.iy, 4, &z80.c);
}
void res_4_iyd_d() {
	executeXYReset(z80.iy, 4, &z80.d);
}
void res_4_iyd_e() {
	executeXYReset(z80.iy, 4, &z80.e);
}
void res_4_iyd_h() {
	executeXYReset(z80.iy, 4, &z80.h);
}
void res_4_iyd_l() {
	executeXYReset(z80.iy, 4, &z80.l);
}
void res_4_iyd() {
	executeXYReset(z80.iy, 4, NULL);
}
void res_4_iyd_a() {
	executeXYReset(z80.iy, 4, &z80.a);
}
void res_5_iyd_b() {
	executeXYReset(z80.iy, 5, &z80.b);
}
void res_5_iyd_c() {
	executeXYReset(z80.iy, 5, &z80.c);
}
void res_5_iyd_d() {
	executeXYReset(z80.iy, 5, &z80.d);
}
void res_5_iyd_e() {
	executeXYReset(z80.iy, 5, &z80.e);
}
void res_5_iyd_h() {
	executeXYReset(z80.iy, 5, &z80.h);
}
void res_5_iyd_l() {
	executeXYReset(z80.iy, 5, &z80.l);
}
void res_5_iyd() {
	executeXYReset(z80.iy, 5, NULL);
}
void res_5_iyd_a() {
	executeXYReset(z80.iy, 5, &z80.a);
}
void res_6_iyd_b() {
	executeXYReset(z80.iy, 6, &z80.b);
}
void res_6_iyd_c() {
	executeXYReset(z80.iy, 6, &z80.c);
}
void res_6_iyd_d() {
	executeXYReset(z80.iy, 6, &z80.d);
}
void res_6_iyd_e() {
	executeXYReset(z80.iy, 6, &z80.e);
}
void res_6_iyd_h() {
	executeXYReset(z80.iy, 6, &z80.h);
}
void res_6_iyd_l() {
	executeXYReset(z80.iy, 6, &z80.l);
}
void res_6_iyd() {
	executeXYReset(z80.iy, 6, NULL);
}
void res_6_iyd_a() {
	executeXYReset(z80.iy, 6, &z80.a);
}
void res_7_iyd_b() {
	executeXYReset(z80.iy, 7, &z80.b);
}
void res_7_iyd_c() {
	executeXYReset(z80.iy, 7, &z80.c);
}
void res_7_iyd_d() {
	executeXYReset(z80.iy, 7, &z80.d);
}
void res_7_iyd_e() {
	executeXYReset(z80.iy, 7, &z80.e);
}
void res_7_iyd_h() {
	executeXYReset(z80.iy, 7, &z80.h);
}
void res_7_iyd_l() {
	executeXYReset(z80.iy, 7, &z80.l);
}
void res_7_iyd() {
	executeXYReset(z80.iy, 7, NULL);
}
void res_7_iyd_a() {
	executeXYReset(z80.iy, 7, &z80.a);
}

void set_0_iyd_b() {
	executeXYSet(z80.iy, 0, &z80.b);
}
void set_0_iyd_c() {
	executeXYSet(z80.iy, 0, &z80.c);
}
void set_0_iyd_d() {
	executeXYSet(z80.iy, 0, &z80.d);
}
void set_0_iyd_e() {
	executeXYSet(z80.iy, 0, &z80.e);
}
void set_0_iyd_h() {
	executeXYSet(z80.iy, 0, &z80.h);
}
void set_0_iyd_l() {
	executeXYSet(z80.iy, 0, &z80.l);
}
void set_0_iyd() {
	executeXYSet(z80.iy, 0, NULL);
}
void set_0_iyd_a() {
	executeXYSet(z80.iy, 0, &z80.a);
}
void set_1_iyd_b() {
	executeXYSet(z80.iy, 1, &z80.b);
}
void set_1_iyd_c() {
	executeXYSet(z80.iy, 1, &z80.c);
}
void set_1_iyd_d() {
	executeXYSet(z80.iy, 1, &z80.d);
}
void set_1_iyd_e() {
	executeXYSet(z80.iy, 1, &z80.e);
}
void set_1_iyd_h() {
	executeXYSet(z80.iy, 1, &z80.h);
}
void set_1_iyd_l() {
	executeXYSet(z80.iy, 1, &z80.l);
}
void set_1_iyd() {
	executeXYSet(z80.iy, 1, NULL);
}
void set_1_iyd_a() {
	executeXYSet(z80.iy, 1, &z80.a);
}
void set_2_iyd_b() {
	executeXYSet(z80.iy, 2, &z80.b);
}
void set_2_iyd_c() {
	executeXYSet(z80.iy, 2, &z80.c);
}
void set_2_iyd_d() {
	executeXYSet(z80.iy, 2, &z80.d);
}
void set_2_iyd_e() {
	executeXYSet(z80.iy, 2, &z80.e);
}
void set_2_iyd_h() {
	executeXYSet(z80.iy, 2, &z80.h);
}
void set_2_iyd_l() {
	executeXYSet(z80.iy, 2, &z80.l);
}
void set_2_iyd() {
	executeXYSet(z80.iy, 2, NULL);
}
void set_2_iyd_a() {
	executeXYSet(z80.iy, 2, &z80.a);
}
void set_3_iyd_b() {
	executeXYSet(z80.iy, 3, &z80.b);
}
void set_3_iyd_c() {
	executeXYSet(z80.iy, 3, &z80.c);
}
void set_3_iyd_d() {
	executeXYSet(z80.iy, 3, &z80.d);
}
void set_3_iyd_e() {
	executeXYSet(z80.iy, 3, &z80.e);
}
void set_3_iyd_h() {
	executeXYSet(z80.iy, 3, &z80.h);
}
void set_3_iyd_l() {
	executeXYSet(z80.iy, 3, &z80.l);
}
void set_3_iyd() {
	executeXYSet(z80.iy, 3, NULL);
}
void set_3_iyd_a() {
	executeXYSet(z80.iy, 3, &z80.a);
}
void set_4_iyd_b() {
	executeXYSet(z80.iy, 4, &z80.b);
}
void set_4_iyd_c() {
	executeXYSet(z80.iy, 4, &z80.c);
}
void set_4_iyd_d() {
	executeXYSet(z80.iy, 4, &z80.d);
}
void set_4_iyd_e() {
	executeXYSet(z80.iy, 4, &z80.e);
}
void set_4_iyd_h() {
	executeXYSet(z80.iy, 4, &z80.h);
}
void set_4_iyd_l() {
	executeXYSet(z80.iy, 4, &z80.l);
}
void set_4_iyd() {
	executeXYSet(z80.iy, 4, NULL);
}
void set_4_iyd_a() {
	executeXYSet(z80.iy, 4, &z80.a);
}
void set_5_iyd_b() {
	executeXYSet(z80.iy, 5, &z80.b);
}
void set_5_iyd_c() {
	executeXYSet(z80.iy, 5, &z80.c);
}
void set_5_iyd_d() {
	executeXYSet(z80.iy, 5, &z80.d);
}
void set_5_iyd_e() {
	executeXYSet(z80.iy, 5, &z80.e);
}
void set_5_iyd_h() {
	executeXYSet(z80.iy, 5, &z80.h);
}
void set_5_iyd_l() {
	executeXYSet(z80.iy, 5, &z80.l);
}
void set_5_iyd() {
	executeXYSet(z80.iy, 5, NULL);
}
void set_5_iyd_a() {
	executeXYSet(z80.iy, 5, &z80.a);
}
void set_6_iyd_b() {
	executeXYSet(z80.iy, 6, &z80.b);
}
void set_6_iyd_c() {
	executeXYSet(z80.iy, 6, &z80.c);
}
void set_6_iyd_d() {
	executeXYSet(z80.iy, 6, &z80.d);
}
void set_6_iyd_e() {
	executeXYSet(z80.iy, 6, &z80.e);
}
void set_6_iyd_h() {
	executeXYSet(z80.iy, 6, &z80.h);
}
void set_6_iyd_l() {
	executeXYSet(z80.iy, 6, &z80.l);
}
void set_6_iyd() {
	executeXYSet(z80.iy, 6, NULL);
}
void set_6_iyd_a() {
	executeXYSet(z80.iy, 6, &z80.a);
}
void set_7_iyd_b() {
	executeXYSet(z80.iy, 7, &z80.b);
}
void set_7_iyd_c() {
	executeXYSet(z80.iy, 7, &z80.c);
}
void set_7_iyd_d() {
	executeXYSet(z80.iy, 7, &z80.d);
}
void set_7_iyd_e() {
	executeXYSet(z80.iy, 7, &z80.e);
}
void set_7_iyd_h() {
	executeXYSet(z80.iy, 7, &z80.h);
}
void set_7_iyd_l() {
	executeXYSet(z80.iy, 7, &z80.l);
}
void set_7_iyd() {
	executeXYSet(z80.iy, 7, NULL);
}
void set_7_iyd_a() {
	executeXYSet(z80.iy, 7, &z80.a);
}