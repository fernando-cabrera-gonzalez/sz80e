#include "opcodes_bit.h"
#include "z80.h"

    /* ================================================================ */
    /*                     BIT INSTRUCTIONS (0xCB)                      */
    /* ================================================================ */

Opcode bitOpcodePtrs[256] = {
	// 00 - 0F
	OC(rlc_b, 2, 8, 0),		
	OC(rlc_c, 2, 8, 0),		
	OC(rlc_d, 2, 8, 0),		
	OC(rlc_e, 2, 8, 0),		
	OC(rlc_h, 2, 8, 0),		
	OC(rlc_l, 2, 8, 0),		
	OC(rlc_hli, 2, 15, 0),		
	OC(rlc_a, 2, 8, 0),		
	OC(rrc_b, 2, 8, 0),		
	OC(rrc_c, 2, 8, 0),		
	OC(rrc_d, 2, 8, 0),		
	OC(rrc_e, 2, 8, 0),		
	OC(rrc_h, 2, 8, 0),		
	OC(rrc_l, 2, 8, 0),		
	OC(rrc_hli, 2, 15, 0),		
	OC(rrc_a, 2, 8, 0),		

	// 10 - 1F

	OC(rl_b, 2, 8, 0),		
	OC(rl_c, 2, 8, 0),		
	OC(rl_d, 2, 8, 0),		
	OC(rl_e, 2, 8, 0),		
	OC(rl_h, 2, 8, 0),		
	OC(rl_l, 2, 8, 0),		
	OC(rl_hli, 2, 15, 0),		
	OC(rl_a, 2, 8, 0),		
	OC(rr_b, 2, 8, 0),		
	OC(rr_c, 2, 8, 0),		
	OC(rr_d, 2, 8, 0),		
	OC(rr_e, 2, 8, 0),		
	OC(rr_h, 2, 8, 0),		
	OC(rr_l, 2, 8, 0),		
	OC(rr_hli, 2, 15, 0),		
	OC(rr_a, 2, 8, 0),		

	// 20 - 2F

	OC(sla_b, 2, 8, 0),		
	OC(sla_c, 2, 8, 0),		
	OC(sla_d, 2, 8, 0),		
	OC(sla_e, 2, 8, 0),		
	OC(sla_h, 2, 8, 0),		
	OC(sla_l, 2, 8, 0),		
	OC(sla_hli, 2, 15, 0),		
	OC(sla_a, 2, 8, 0),		
	OC(sra_b, 2, 8, 0),		
	OC(sra_c, 2, 8, 0),		
	OC(sra_d, 2, 8, 0),		
	OC(sra_e, 2, 8, 0),		
	OC(sra_h, 2, 8, 0),		
	OC(sra_l, 2, 8, 0),		
	OC(sra_hli, 2, 15, 0),		
	OC(sra_a, 2, 8, 0),		

	// 30 - 3F

	OC(sll_b, 2, 8, 0),		
	OC(sll_c, 2, 8, 0),		
	OC(sll_d, 2, 8, 0),		
	OC(sll_e, 2, 8, 0),		
	OC(sll_h, 2, 8, 0),		
	OC(sll_l, 2, 8, 0),		
	OC(sll_hli, 2, 15, 0),		
	OC(sll_a, 2, 8, 0),		
	OC(srl_b, 2, 8, 0),		
	OC(srl_c, 2, 8, 0),		
	OC(srl_d, 2, 8, 0),		
	OC(srl_e, 2, 8, 0),		
	OC(srl_h, 2, 8, 0),		
	OC(srl_l, 2, 8, 0),		
	OC(srl_hli, 2, 15, 0),		
	OC(srl_a, 2, 8, 0),		

	// 40 - 4F

	OC(bit_0_b, 2, 8, 0),		
	OC(bit_0_c, 2, 8, 0),		
	OC(bit_0_d, 2, 8, 0),		
	OC(bit_0_e, 2, 8, 0),		
	OC(bit_0_h, 2, 8, 0),		
	OC(bit_0_l, 2, 8, 0),		
	OC(bit_0_hli, 2, 12, 0),		
	OC(bit_0_a, 2, 8, 0),		
	OC(bit_1_b, 2, 8, 0),		
	OC(bit_1_c, 2, 8, 0),		
	OC(bit_1_d, 2, 8, 0),		
	OC(bit_1_e, 2, 8, 0),		
	OC(bit_1_h, 2, 8, 0),		
	OC(bit_1_l, 2, 8, 0),		
	OC(bit_1_hli, 2, 12, 0),		
	OC(bit_1_a, 2, 8, 0),	

	// 50 - 5F

	OC(bit_2_b, 2, 8, 0),		
	OC(bit_2_c, 2, 8, 0),		
	OC(bit_2_d, 2, 8, 0),		
	OC(bit_2_e, 2, 8, 0),		
	OC(bit_2_h, 2, 8, 0),		
	OC(bit_2_l, 2, 8, 0),		
	OC(bit_2_hli, 2, 12, 0),		
	OC(bit_2_a, 2, 8, 0),		
	OC(bit_3_b, 2, 8, 0),		
	OC(bit_3_c, 2, 8, 0),		
	OC(bit_3_d, 2, 8, 0),		
	OC(bit_3_e, 2, 8, 0),		
	OC(bit_3_h, 2, 8, 0),		
	OC(bit_3_l, 2, 8, 0),		
	OC(bit_3_hli, 2, 12, 0),		
	OC(bit_3_a, 2, 8, 0),	

	// 60 - 6F

	OC(bit_4_b, 2, 8, 0),		
	OC(bit_4_c, 2, 8, 0),		
	OC(bit_4_d, 2, 8, 0),		
	OC(bit_4_e, 2, 8, 0),		
	OC(bit_4_h, 2, 8, 0),		
	OC(bit_4_l, 2, 8, 0),		
	OC(bit_4_hli, 2, 12, 0),		
	OC(bit_4_a, 2, 8, 0),		
	OC(bit_5_b, 2, 8, 0),		
	OC(bit_5_c, 2, 8, 0),		
	OC(bit_5_d, 2, 8, 0),		
	OC(bit_5_e, 2, 8, 0),		
	OC(bit_5_h, 2, 8, 0),		
	OC(bit_5_l, 2, 8, 0),		
	OC(bit_5_hli, 2, 12, 0),		
	OC(bit_5_a, 2, 8, 0),		

	// 70 - 7F

	OC(bit_6_b, 2, 8, 0),		
	OC(bit_6_c, 2, 8, 0),		
	OC(bit_6_d, 2, 8, 0),		
	OC(bit_6_e, 2, 8, 0),		
	OC(bit_6_h, 2, 8, 0),		
	OC(bit_6_l, 2, 8, 0),		
	OC(bit_6_hli, 2, 12, 0),		
	OC(bit_6_a, 2, 8, 0),		
	OC(bit_7_b, 2, 8, 0),		
	OC(bit_7_c, 2, 8, 0),		
	OC(bit_7_d, 2, 8, 0),		
	OC(bit_7_e, 2, 8, 0),		
	OC(bit_7_h, 2, 8, 0),		
	OC(bit_7_l, 2, 8, 0),		
	OC(bit_7_hli, 2, 12, 0),		
	OC(bit_7_a, 2, 8, 0),		

	// 80 - 8F

	OC(res_0_b, 2, 8, 0),		
	OC(res_0_c, 2, 8, 0),		
	OC(res_0_d, 2, 8, 0),		
	OC(res_0_e, 2, 8, 0),		
	OC(res_0_h, 2, 8, 0),		
	OC(res_0_l, 2, 8, 0),		
	OC(res_0_hli, 2, 15, 0),		
	OC(res_0_a, 2, 8, 0),		
	OC(res_1_b, 2, 8, 0),		
	OC(res_1_c, 2, 8, 0),		
	OC(res_1_d, 2, 8, 0),		
	OC(res_1_e, 2, 8, 0),		
	OC(res_1_h, 2, 8, 0),		
	OC(res_1_l, 2, 8, 0),		
	OC(res_1_hli, 2, 15, 0),		
	OC(res_1_a, 2, 8, 0),		

	// 90 - 9F

	OC(res_2_b, 2, 8, 0),		
	OC(res_2_c, 2, 8, 0),		
	OC(res_2_d, 2, 8, 0),		
	OC(res_2_e, 2, 8, 0),		
	OC(res_2_h, 2, 8, 0),		
	OC(res_2_l, 2, 8, 0),		
	OC(res_2_hli, 2, 15, 0),		
	OC(res_2_a, 2, 8, 0),		
	OC(res_3_b, 2, 8, 0),		
	OC(res_3_c, 2, 8, 0),		
	OC(res_3_d, 2, 8, 0),		
	OC(res_3_e, 2, 8, 0),		
	OC(res_3_h, 2, 8, 0),		
	OC(res_3_l, 2, 8, 0),		
	OC(res_3_hli, 2, 15, 0),		
	OC(res_3_a, 2, 8, 0),

	// A0 - AF

	OC(res_4_b, 2, 8, 0),		
	OC(res_4_c, 2, 8, 0),		
	OC(res_4_d, 2, 8, 0),		
	OC(res_4_e, 2, 8, 0),		
	OC(res_4_h, 2, 8, 0),		
	OC(res_4_l, 2, 8, 0),		
	OC(res_4_hli, 2, 15, 0),		
	OC(res_4_a, 2, 8, 0),		
	OC(res_5_b, 2, 8, 0),		
	OC(res_5_c, 2, 8, 0),		
	OC(res_5_d, 2, 8, 0),		
	OC(res_5_e, 2, 8, 0),		
	OC(res_5_h, 2, 8, 0),		
	OC(res_5_l, 2, 8, 0),		
	OC(res_5_hli, 2, 15, 0),		
	OC(res_5_a, 2, 8, 0),		

	// B0 - BF

	OC(res_6_b, 2, 8, 0),		
	OC(res_6_c, 2, 8, 0),		
	OC(res_6_d, 2, 8, 0),		
	OC(res_6_e, 2, 8, 0),		
	OC(res_6_h, 2, 8, 0),		
	OC(res_6_l, 2, 8, 0),		
	OC(res_6_hli, 2, 15, 0),		
	OC(res_6_a, 2, 8, 0),		
	OC(res_7_b, 2, 8, 0),		
	OC(res_7_c, 2, 8, 0),		
	OC(res_7_d, 2, 8, 0),		
	OC(res_7_e, 2, 8, 0),		
	OC(res_7_h, 2, 8, 0),		
	OC(res_7_l, 2, 8, 0),		
	OC(res_7_hli, 2, 15, 0),		
	OC(res_7_a, 2, 8, 0),		

	// C0 - CF

	OC(set_0_b, 2, 8, 0),		
	OC(set_0_c, 2, 8, 0),		
	OC(set_0_d, 2, 8, 0),		
	OC(set_0_e, 2, 8, 0),		
	OC(set_0_h, 2, 8, 0),		
	OC(set_0_l, 2, 8, 0),		
	OC(set_0_hli, 2, 15, 0),		
	OC(set_0_a, 2, 8, 0),		
	OC(set_1_b, 2, 8, 0),		
	OC(set_1_c, 2, 8, 0),		
	OC(set_1_d, 2, 8, 0),		
	OC(set_1_e, 2, 8, 0),		
	OC(set_1_h, 2, 8, 0),		
	OC(set_1_l, 2, 8, 0),		
	OC(set_1_hli, 2, 15, 0),		
	OC(set_1_a, 2, 8, 0),	

	// D0 - DF

	OC(set_2_b, 2, 8, 0),		
	OC(set_2_c, 2, 8, 0),		
	OC(set_2_d, 2, 8, 0),		
	OC(set_2_e, 2, 8, 0),		
	OC(set_2_h, 2, 8, 0),		
	OC(set_2_l, 2, 8, 0),		
	OC(set_2_hli, 2, 15, 0),		
	OC(set_2_a, 2, 8, 0),		
	OC(set_3_b, 2, 8, 0),		
	OC(set_3_c, 2, 8, 0),		
	OC(set_3_d, 2, 8, 0),		
	OC(set_3_e, 2, 8, 0),		
	OC(set_3_h, 2, 8, 0),		
	OC(set_3_l, 2, 8, 0),		
	OC(set_3_hli, 2, 15, 0),		
	OC(set_3_a, 2, 8, 0),

	// E0 - EF

	OC(set_4_b, 2, 8, 0),		
	OC(set_4_c, 2, 8, 0),		
	OC(set_4_d, 2, 8, 0),		
	OC(set_4_e, 2, 8, 0),		
	OC(set_4_h, 2, 8, 0),		
	OC(set_4_l, 2, 8, 0),		
	OC(set_4_hli, 2, 15, 0),		
	OC(set_4_a, 2, 8, 0),		
	OC(set_5_b, 2, 8, 0),		
	OC(set_5_c, 2, 8, 0),		
	OC(set_5_d, 2, 8, 0),		
	OC(set_5_e, 2, 8, 0),		
	OC(set_5_h, 2, 8, 0),		
	OC(set_5_l, 2, 8, 0),		
	OC(set_5_hli, 2, 15, 0),		
	OC(set_5_a, 2, 8, 0),	

	// F0 - FF

	OC(set_6_b, 2, 8, 0),		
	OC(set_6_c, 2, 8, 0),		
	OC(set_6_d, 2, 8, 0),		
	OC(set_6_e, 2, 8, 0),		
	OC(set_6_h, 2, 8, 0),		
	OC(set_6_l, 2, 8, 0),		
	OC(set_6_hli, 2, 15, 0),		
	OC(set_6_a, 2, 8, 0),		
	OC(set_7_b, 2, 8, 0),		
	OC(set_7_c, 2, 8, 0),		
	OC(set_7_d, 2, 8, 0),		
	OC(set_7_e, 2, 8, 0),		
	OC(set_7_h, 2, 8, 0),		
	OC(set_7_l, 2, 8, 0),		
	OC(set_7_hli, 2, 15, 0),		
	OC(set_7_a, 2, 8, 0)
};

void rlc_b() {
    executeRotateLeft(&z80.b, NULL, true);
}

void rlc_c() {
    executeRotateLeft(&z80.c, NULL, true);	
}

void rlc_d() {
    executeRotateLeft(&z80.d, NULL, true);	
}

void rlc_e() {
    executeRotateLeft(&z80.e, NULL, true);	
}

void rlc_h() {
    executeRotateLeft(&z80.h, NULL, true);	
}

void rlc_l() {
    executeRotateLeft(&z80.l, NULL, true);	
}

void rlc_hli() {
	uint8_t data = memReadFunc(z80.hl);
    executeRotateLeft(&data, NULL, true);	
	memWriteFunc(z80.hl, data);
}

void rlc_a() {
    executeRotateLeft(&z80.a, NULL, true);	
}

void rrc_b() {
    executeRotateRight(&z80.b, NULL, true);		
}

void rrc_c() {
    executeRotateRight(&z80.c, NULL, true);			
}

void rrc_d() {
    executeRotateRight(&z80.d, NULL, true);				
}

void rrc_e() {
    executeRotateRight(&z80.e, NULL, true);				
}

void rrc_h() {
    executeRotateRight(&z80.h, NULL, true);				
}

void rrc_l() {
    executeRotateRight(&z80.l, NULL, true);				
}

void rrc_hli() {
	uint8_t data = memReadFunc(z80.hl);
    executeRotateRight(&data, NULL, true);
	memWriteFunc(z80.hl, data);
}

void rrc_a() {
    executeRotateRight(&z80.a, NULL, true);				
}

void rl_b() {
	executeRotateLeft(&z80.b, NULL, false);
}

void rl_c() {
	executeRotateLeft(&z80.c, NULL, false);	
}

void rl_d() {
	executeRotateLeft(&z80.d, NULL, false);		
}

void rl_e() {
	executeRotateLeft(&z80.e, NULL, false);		
}

void rl_h() {
	executeRotateLeft(&z80.h, NULL, false);		
}

void rl_l() {
	executeRotateLeft(&z80.l, NULL, false);		
}

void rl_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeRotateLeft(&data, NULL, false);		
	memWriteFunc(z80.hl, data);
}

void rl_a() {
	executeRotateLeft(&z80.a, NULL, false);		
}

void rr_b() {
	executeRotateRight(&z80.b, NULL, false);			
}

void rr_c() {
	executeRotateRight(&z80.c, NULL, false);				
}

void rr_d() {
	executeRotateRight(&z80.d, NULL, false);				
}

void rr_e() {
	executeRotateRight(&z80.e, NULL, false);				
}

void rr_h() {
	executeRotateRight(&z80.h, NULL, false);				
}

void rr_l() {
	executeRotateRight(&z80.l, NULL, false);				
}

void rr_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeRotateRight(&data, NULL, false);				
	memWriteFunc(z80.hl, data);	
}

void rr_a() {
	executeRotateRight(&z80.a, NULL, false);				
}

void sla_b() {
    executeShiftLeft(&z80.b, NULL, true);
}

void sla_c() {
    executeShiftLeft(&z80.c, NULL, true);	
}

void sla_d() {
    executeShiftLeft(&z80.d, NULL, true);	
}

void sla_e() {
    executeShiftLeft(&z80.e, NULL, true);	
}

void sla_h() {
    executeShiftLeft(&z80.h, NULL, true);	
}

void sla_l() {
    executeShiftLeft(&z80.l, NULL, true);	
}

void sla_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeShiftLeft(&data, NULL, true);	
	memWriteFunc(z80.hl, data);
}

void sla_a() {
    executeShiftLeft(&z80.a, NULL, true);	
}

void sra_b() {
    executeShiftRight(&z80.b, NULL, true);	
}

void sra_c() {
    executeShiftRight(&z80.c, NULL, true);		
}

void sra_d() {
    executeShiftRight(&z80.d, NULL, true);		
}

void sra_e() {
    executeShiftRight(&z80.e, NULL, true);		
}

void sra_h() {
    executeShiftRight(&z80.h, NULL, true);		
}

void sra_l() {
    executeShiftRight(&z80.l, NULL, true);		
}

void sra_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeShiftRight(&data, NULL, true);		
	memWriteFunc(z80.hl, data);	
}

void sra_a() {
    executeShiftRight(&z80.a, NULL, true);		
}

void sll_b() {
    executeShiftLeft(&z80.b, NULL, false);	
}

void sll_c() {
    executeShiftLeft(&z80.c, NULL, false);		
}

void sll_d() {
    executeShiftLeft(&z80.d, NULL, false);		
}

void sll_e() {
    executeShiftLeft(&z80.e, NULL, false);		
}

void sll_h() {
    executeShiftLeft(&z80.h, NULL, false);		
}

void sll_l() {
    executeShiftLeft(&z80.l, NULL, false);		
}

void sll_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeShiftLeft(&data, NULL, false);
	memWriteFunc(z80.hl, data);				
}

void sll_a() {
    executeShiftLeft(&z80.a, NULL, false);		
}

void srl_b() {
    executeShiftRight(&z80.b, NULL, false);			
}

void srl_c() {
    executeShiftRight(&z80.c, NULL, false);				
}

void srl_d() {
    executeShiftRight(&z80.d, NULL, false);				
}

void srl_e() {
    executeShiftRight(&z80.e, NULL, false);				
}

void srl_h() {
    executeShiftRight(&z80.h, NULL, false);				
}

void srl_l() {
    executeShiftRight(&z80.l, NULL, false);				
}

void srl_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeShiftRight(&data, NULL, false);				
	memWriteFunc(z80.hl, data);		
}

void srl_a() {
    executeShiftRight(&z80.a, NULL, false);				
}

void bit_0_b() {
    executeBit(0, z80.b);
}

void bit_0_c() {
    executeBit(0, z80.c);
}

void bit_0_d() {
    executeBit(0, z80.d);
}

void bit_0_e() {
    executeBit(0, z80.e);
}

void bit_0_h() {
    executeBit(0, z80.h);
}

void bit_0_l() {
    executeBit(0, z80.l);
}

void bit_0_hli() {
    executeBit(0, memReadFunc(z80.hl));
}

void bit_0_a() {
    executeBit(0, z80.a);
}

void bit_1_b() {
    executeBit(1, z80.b);
}

void bit_1_c() {
    executeBit(1, z80.c);
}

void bit_1_d() {
    executeBit(1, z80.d);
}

void bit_1_e() {
    executeBit(1, z80.e);
}

void bit_1_h() {
    executeBit(1, z80.h);
}

void bit_1_l() {
    executeBit(1, z80.l);
}

void bit_1_hli() {
    executeBit(1, memReadFunc(z80.hl));
}

void bit_1_a() {
    executeBit(1, z80.a);
}

void bit_2_b() {
    executeBit(2, z80.b);
}

void bit_2_c() {
    executeBit(2, z80.c);
}

void bit_2_d() {
    executeBit(2, z80.d);
}

void bit_2_e() {
    executeBit(2, z80.e);
}

void bit_2_h() {
    executeBit(2, z80.h);
}

void bit_2_l() {
    executeBit(2, z80.l);
}

void bit_2_hli() {
    executeBit(2, memReadFunc(z80.hl));
}

void bit_2_a() {
    executeBit(2, z80.a);
}

void bit_3_b() {
    executeBit(3, z80.b);
}

void bit_3_c() {
    executeBit(3, z80.c);
}

void bit_3_d() {
    executeBit(3, z80.d);
}

void bit_3_e() {
    executeBit(3, z80.e);
}

void bit_3_h() {
    executeBit(3, z80.h);
}

void bit_3_l() {
    executeBit(3, z80.l);
}

void bit_3_hli() {
    executeBit(3, memReadFunc(z80.hl));
}

void bit_3_a() {
    executeBit(3, z80.a);
}

void bit_4_b() {
    executeBit(4, z80.b);
}

void bit_4_c() {
executeBit(4, z80.c);
}

void bit_4_d() {
    executeBit(4, z80.d);
}

void bit_4_e() {
    executeBit(4, z80.e);
}

void bit_4_h() {
    executeBit(4, z80.h);
}

void bit_4_l() {
    executeBit(4, z80.l);
}

void bit_4_hli() {
    executeBit(4, memReadFunc(z80.hl));
}

void bit_4_a() {
    executeBit(4, z80.a);
}

void bit_5_b() {
    executeBit(5, z80.b);
}

void bit_5_c() {
    executeBit(5, z80.c);
}

void bit_5_d() {
    executeBit(5, z80.d);
}

void bit_5_e() {
    executeBit(5, z80.e);
}

void bit_5_h() {
    executeBit(5, z80.h);
}

void bit_5_l() {
    executeBit(5, z80.l);
}

void bit_5_hli() {
    executeBit(5, memReadFunc(z80.hl));
}

void bit_5_a() {
    executeBit(5, z80.a);
}

void bit_6_b() {
    executeBit(6, z80.b);
}

void bit_6_c() {
    executeBit(6, z80.c);
}

void bit_6_d() {
    executeBit(6, z80.d);
}

void bit_6_e() {
    executeBit(6, z80.e);
}

void bit_6_h() {
    executeBit(6, z80.h);
}

void bit_6_l() {
    executeBit(6, z80.l);
}

void bit_6_hli() {
    executeBit(6, memReadFunc(z80.hl));
}

void bit_6_a() {
    executeBit(6, z80.a);
}

void bit_7_b() {
    executeBit(7, z80.b);
}

void bit_7_c() {
    executeBit(7, z80.c);
}

void bit_7_d() {
    executeBit(7, z80.d);
}

void bit_7_e() {
    executeBit(7, z80.e);
}

void bit_7_h() {
    executeBit(7, z80.h);
}

void bit_7_l() {
    executeBit(7, z80.l);
}

void bit_7_hli() {
    executeBit(7, memReadFunc(z80.hl));
}

void bit_7_a() {
    executeBit(7, z80.a);
}

void res_0_b() {
	executeReset(0, &z80.b);
}
void res_0_c() {
	executeReset(0, &z80.c);
}
void res_0_d() {
	executeReset(0, &z80.d);
}
void res_0_e() {
	executeReset(0, &z80.e);
}
void res_0_h() {
	executeReset(0, &z80.h);
}
void res_0_l() {
	executeReset(0, &z80.l);
}
void res_0_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeReset(0, &data);
	memWriteFunc(z80.hl, data);
}
void res_0_a() {
	executeReset(0, &z80.a);
}
void res_1_b() {
	executeReset(1, &z80.b);
}
void res_1_c() {
	executeReset(1, &z80.c);
}
void res_1_d() {
	executeReset(1, &z80.d);
}
void res_1_e() {
	executeReset(1, &z80.e);
}
void res_1_h() {
	executeReset(1, &z80.h);
}
void res_1_l() {
	executeReset(1, &z80.l);
}
void res_1_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeReset(1, &data);
	memWriteFunc(z80.hl, data);
}
void res_1_a() {
	executeReset(1, &z80.a);
}
void res_2_b() {
	executeReset(2, &z80.b);
}
void res_2_c() {
	executeReset(2, &z80.c);
}
void res_2_d() {
	executeReset(2, &z80.d);
}
void res_2_e() {
	executeReset(2, &z80.e);
}
void res_2_h() {
	executeReset(2, &z80.h);
}
void res_2_l() {
	executeReset(2, &z80.l);
}
void res_2_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeReset(2, &data);
	memWriteFunc(z80.hl, data);
}
void res_2_a() {
	executeReset(2, &z80.a);
}
void res_3_b() {
	executeReset(3, &z80.b);
}
void res_3_c() {
	executeReset(3, &z80.c);
}
void res_3_d() {
	executeReset(3, &z80.d);
}
void res_3_e() {
	executeReset(3, &z80.e);
}
void res_3_h() {
	executeReset(3, &z80.h);
}
void res_3_l() {
	executeReset(3, &z80.l);
}
void res_3_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeReset(3, &data);
	memWriteFunc(z80.hl, data);
}
void res_3_a() {
	executeReset(3, &z80.a);
}
void res_4_b() {
	executeReset(4, &z80.b);
}
void res_4_c() {
	executeReset(4, &z80.c);
}
void res_4_d() {
	executeReset(4, &z80.d);
}
void res_4_e() {
	executeReset(4, &z80.e);
}
void res_4_h() {
	executeReset(4, &z80.h);
}
void res_4_l() {
	executeReset(4, &z80.l);
}
void res_4_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeReset(4, &data);
	memWriteFunc(z80.hl, data);
}
void res_4_a() {
	executeReset(4, &z80.a);
}
void res_5_b() {
	executeReset(5, &z80.b);
}
void res_5_c() {
	executeReset(5, &z80.c);
}
void res_5_d() {
	executeReset(5, &z80.d);
}
void res_5_e() {
	executeReset(5, &z80.e);
}
void res_5_h() {
	executeReset(5, &z80.h);
}
void res_5_l() {
	executeReset(5, &z80.l);
}
void res_5_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeReset(5, &data);
	memWriteFunc(z80.hl, data);
}
void res_5_a() {
	executeReset(5, &z80.a);
}
void res_6_b() {
	executeReset(6, &z80.b);
}
void res_6_c() {
	executeReset(6, &z80.c);
}
void res_6_d() {
	executeReset(6, &z80.d);
}
void res_6_e() {
	executeReset(6, &z80.e);
}
void res_6_h() {
	executeReset(6, &z80.h);
}
void res_6_l() {
	executeReset(6, &z80.l);
}
void res_6_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeReset(6, &data);
	memWriteFunc(z80.hl, data);
}
void res_6_a() {
	executeReset(6, &z80.a);
}
void res_7_b() {
	executeReset(7, &z80.b);
}
void res_7_c() {
	executeReset(7, &z80.c);
}
void res_7_d() {
	executeReset(7, &z80.d);
}
void res_7_e() {
	executeReset(7, &z80.e);
}
void res_7_h() {
	executeReset(7, &z80.h);
}
void res_7_l() {
	executeReset(7, &z80.l);
}
void res_7_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeReset(7, &data);
	memWriteFunc(z80.hl, data);
}
void res_7_a() {
	executeReset(7, &z80.a);
}

void set_0_b() {
	executeSet(0, &z80.b);
}
void set_0_c() {
	executeSet(0, &z80.c);
}
void set_0_d() {
	executeSet(0, &z80.d);
}
void set_0_e() {
	executeSet(0, &z80.e);
}
void set_0_h() {
	executeSet(0, &z80.h);
}
void set_0_l() {
	executeSet(0, &z80.l);
}
void set_0_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeSet(0, &data);
	memWriteFunc(z80.hl, data);
}
void set_0_a() {
	executeSet(0, &z80.a);
}
void set_1_b() {
	executeSet(1, &z80.b);
}
void set_1_c() {
	executeSet(1, &z80.c);
}
void set_1_d() {
	executeSet(1, &z80.d);
}
void set_1_e() {
	executeSet(1, &z80.e);
}
void set_1_h() {
	executeSet(1, &z80.h);
}
void set_1_l() {
	executeSet(1, &z80.l);
}
void set_1_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeSet(1, &data);
	memWriteFunc(z80.hl, data);
}
void set_1_a() {
	executeSet(1, &z80.a);
}
void set_2_b() {
	executeSet(2, &z80.b);
}
void set_2_c() {
	executeSet(2, &z80.c);
}
void set_2_d() {
	executeSet(2, &z80.d);
}
void set_2_e() {
	executeSet(2, &z80.e);
}
void set_2_h() {
	executeSet(2, &z80.h);
}
void set_2_l() {
	executeSet(2, &z80.l);
}
void set_2_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeSet(2, &data);
	memWriteFunc(z80.hl, data);
}
void set_2_a() {
	executeSet(2, &z80.a);
}
void set_3_b() {
	executeSet(3, &z80.b);
}
void set_3_c() {
	executeSet(3, &z80.c);
}
void set_3_d() {
	executeSet(3, &z80.d);
}
void set_3_e() {
	executeSet(3, &z80.e);
}
void set_3_h() {
	executeSet(3, &z80.h);
}
void set_3_l() {
	executeSet(3, &z80.l);
}
void set_3_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeSet(3, &data);
	memWriteFunc(z80.hl, data);
}
void set_3_a() {
	executeSet(3, &z80.a);
}
void set_4_b() {
	executeSet(4, &z80.b);
}
void set_4_c() {
	executeSet(4, &z80.c);
}
void set_4_d() {
	executeSet(4, &z80.d);
}
void set_4_e() {
	executeSet(4, &z80.e);
}
void set_4_h() {
	executeSet(4, &z80.h);
}
void set_4_l() {
	executeSet(4, &z80.l);
}
void set_4_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeSet(4, &data);
	memWriteFunc(z80.hl, data);
}
void set_4_a() {
	executeSet(4, &z80.a);
}
void set_5_b() {
	executeSet(5, &z80.b);
}
void set_5_c() {
	executeSet(5, &z80.c);
}
void set_5_d() {
	executeSet(5, &z80.d);
}
void set_5_e() {
	executeSet(5, &z80.e);
}
void set_5_h() {
	executeSet(5, &z80.h);
}
void set_5_l() {
	executeSet(5, &z80.l);
}
void set_5_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeSet(5, &data);
	memWriteFunc(z80.hl, data);
}
void set_5_a() {
	executeSet(5, &z80.a);
}
void set_6_b() {
	executeSet(6, &z80.b);
}
void set_6_c() {
	executeSet(6, &z80.c);
}
void set_6_d() {
	executeSet(6, &z80.d);
}
void set_6_e() {
	executeSet(6, &z80.e);
}
void set_6_h() {
	executeSet(6, &z80.h);
}
void set_6_l() {
	executeSet(6, &z80.l);
}
void set_6_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeSet(6, &data);
	memWriteFunc(z80.hl, data);
}
void set_6_a() {
	executeSet(6, &z80.a);
}
void set_7_b() {
	executeSet(7, &z80.b);
}
void set_7_c() {
	executeSet(7, &z80.c);
}
void set_7_d() {
	executeSet(7, &z80.d);
}
void set_7_e() {
	executeSet(7, &z80.e);
}
void set_7_h() {
	executeSet(7, &z80.h);
}
void set_7_l() {
	executeSet(7, &z80.l);
}
void set_7_hli() {
	uint8_t data = memReadFunc(z80.hl);
	executeSet(7, &data);
	memWriteFunc(z80.hl, data);
}
void set_7_a() {
	executeSet(7, &z80.a);
}