/*
 * opcodes_main.h - Main Opcode Table Interface
 *
 * Declares the main opcode table and function prototypes for standard instructions (0x00-0xFF).
 */

#ifndef OPCODES_MAIN_H
#define OPCODES_MAIN_H

#include "opcodes.h"

    /* ================================================================ */
    /*                 MAIN INSTRUCTIONS (0x00 - 0xFF)                  */
    /* ================================================================ */

extern Opcode opcodePtrs[256];

// 00 - 0F
void nop(); 
void ld_bc_nn(); 
void ld_bci_a(); 
void inc_bc(); 
void inc_b(); 
void dec_b(); 
void ld_b_n(); 
void rlca(); 
void ex_af_af2(); 
void add_hl_bc(); 
void ld_a_bci(); 
void dec_bc(); 
void inc_c(); 
void dec_c(); 
void ld_c_n(); 
void rrca(); 

// 10 -1F
bool djnz_d(); 
void ld_de_nn(); 
void ld_dei_a(); 
void inc_de(); 
void inc_d(); 
void dec_d(); 
void ld_d_n(); 
void rla(); 
void jr_d(); 
void add_hl_de(); 
void ld_a_dei(); 
void dec_de(); 
void inc_e(); 
void dec_e(); 
void ld_e_n(); 
void rra(); 

// 20 - 2F
bool jr_nz_d(); 
void ld_hl_nn(); 
void ld_nni_hl(); 
void inc_hl(); 
void inc_h(); 
void dec_h(); 
void ld_h_n(); 
void daa(); 
bool jr_z_d(); 
void add_hl_hl(); 
void ld_hl_nni(); 
void dec_hl(); 
void inc_l(); 
void dec_l(); 
void ld_l_n(); 
void cpl(); 

// 30 -3F
bool jr_nc_d(); 
void ld_sp_nn(); 
void ld_nni_a(); 
void inc_sp(); 
void inc_hli(); 
void dec_hli(); 
void ld_hli_n(); 
void scf(); 
bool jr_c_d(); 
void add_hl_sp(); 
void ld_a_nni(); 
void dec_sp(); 
void inc_a(); 
void dec_a(); 
void ld_a_n(); 
void ccf();

// 40 - 4F
void ld_b_b(); 
void ld_b_c(); 
void ld_b_d(); 
void ld_b_e(); 
void ld_b_h(); 
void ld_b_l(); 
void ld_b_hli(); 
void ld_b_a(); 
void ld_c_b(); 
void ld_c_c(); 
void ld_c_d(); 
void ld_c_e(); 
void ld_c_h(); 
void ld_c_l(); 
void ld_c_hli(); 
void ld_c_a(); 

// 50 -5F
void ld_d_b(); 
void ld_d_c(); 
void ld_d_d(); 
void ld_d_e(); 
void ld_d_h(); 
void ld_d_l(); 
void ld_d_hli(); 
void ld_d_a(); 
void ld_e_b(); 
void ld_e_c(); 
void ld_e_d(); 
void ld_e_e(); 
void ld_e_h(); 
void ld_e_l(); 
void ld_e_hli(); 
void ld_e_a(); 

// 60 - 6F
void ld_h_b(); 
void ld_h_c(); 
void ld_h_d(); 
void ld_h_e(); 
void ld_h_h(); 
void ld_h_l(); 
void ld_h_hli(); 
void ld_h_a(); 
void ld_l_b(); 
void ld_l_c(); 
void ld_l_d(); 
void ld_l_e(); 
void ld_l_h(); 
void ld_l_l(); 
void ld_l_hli(); 
void ld_l_a(); 

// 70 - 7F
void ld_hli_b(); 
void ld_hli_c(); 
void ld_hli_d(); 
void ld_hli_e(); 
void ld_hli_h(); 
void ld_hli_l(); 
void halt(); 
void ld_hli_a(); 
void ld_a_b(); 
void ld_a_c(); 
void ld_a_d(); 
void ld_a_e(); 
void ld_a_h(); 
void ld_a_l(); 
void ld_a_hli(); 
void ld_a_a(); 

// 80 - 8F
void add_a_b(); 
void add_a_c(); 
void add_a_d(); 
void add_a_e(); 
void add_a_h(); 
void add_a_l(); 
void add_a_hli(); 
void add_a_a(); 
void adc_a_b(); 
void adc_a_c(); 
void adc_a_d(); 
void adc_a_e(); 
void adc_a_h(); 
void adc_a_l(); 
void adc_a_hli(); 
void adc_a_a(); 

// 90 - 9F
void sub_b(); 
void sub_c(); 
void sub_d(); 
void sub_e(); 
void sub_h(); 
void sub_l(); 
void sub_hli(); 
void sub_a(); 
void sbc_a_b(); 
void sbc_a_c(); 
void sbc_a_d(); 
void sbc_a_e(); 
void sbc_a_h(); 
void sbc_a_l(); 
void sbc_a_hli(); 
void sbc_a_a(); 

// A0 - AF
void and_b(); 
void and_c(); 
void and_d(); 
void and_e(); 
void and_h(); 
void and_l(); 
void and_hli(); 
void and_a(); 
void xor_b(); 
void xor_c(); 
void xor_d(); 
void xor_e(); 
void xor_h(); 
void xor_l(); 
void xor_hli(); 
void xor_a(); 

// B0 - BF
void or_b(); 
void or_c(); 
void or_d(); 
void or_e(); 
void or_h(); 
void or_l(); 
void or_hli(); 
void or_a(); 
void cp_b(); 
void cp_c(); 
void cp_d(); 
void cp_e(); 
void cp_h(); 
void cp_l(); 
void cp_hli(); 
void cp_a(); 

// C0 - CF
bool ret_nz(); 
void pop_bc(); 
void jp_nz_nn(); 
void jp_nn(); 
bool call_nz_nn(); 
void push_bc(); 
void add_a_n(); 
void rst_00h(); 
bool ret_z(); 
void ret(); 
void jp_z_nn(); 
// CB -> prefix for BIT instructions
bool call_z_nn(); 
void call_nn(); 
void adc_a_n(); 
void rst_08h();

// D0 -DF
bool ret_nc(); 
void pop_de(); 
void jp_nc_nn(); 
void out_ni_a(); 
bool call_nc_nn(); 
void push_de(); 
void sub_n(); 
void rst_10h();
bool ret_c(); 
void exx(); 
void jp_c_nn(); 
void in_a_ni(); 
bool call_c_nn(); 
// DD - > prefix for IX instructions
void sbc_a_n(); 
void rst_18h();

// E0 - EF
bool ret_po(); 
void pop_hl(); 
void jp_po_nn(); 
void ex_spi_hl(); 
bool call_po_nn(); 
void push_hl(); 
void and_n(); 
void rst_20h();
bool ret_pe(); 
void jp_hli(); 
void jp_pe_nn(); 
void ex_de_hl(); 
bool call_pe_nn(); 
// ED -> prefix for EXT instructions
void xor_n(); 
void rst_28h();

// F0 -FF
bool ret_p(); 
void pop_af(); 
void jp_p_nn(); 
void di(); 
bool call_p_nn(); 
void push_af(); 
void or_n(); 
void rst_30h();
bool ret_m(); 
void ld_sp_hl(); 
void jp_m_nn(); 
void ei(); 
bool call_m_nn(); 
// FD -> prefix for IY instructions
void cp_n(); 
void rst_38h();

#endif