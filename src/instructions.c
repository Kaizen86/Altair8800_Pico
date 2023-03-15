#include "instructions.h"
#include "instructions_impl.h"

Opcode instruction_set[256] = {
  { "NOP",        .length=1, .cycles=4,  &opcode_UNDEF },
  { "LXI B,d16",  .length=3, .cycles=10, &opcode_UNDEF },
  { "STAX B",     .length=1, .cycles=7,  &opcode_UNDEF },
  { "INX B",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "INR B",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "DCR B",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "MVI B,d8",   .length=2, .cycles=7,  &opcode_UNDEF },
  { "RLC",        .length=1, .cycles=4,  &opcode_UNDEF },
  { "*NOP",       .length=1, .cycles=4,  &opcode_UNDEF },
  { "DAD B",      .length=1, .cycles=10, &opcode_UNDEF },
  { "LDAX B",     .length=1, .cycles=7,  &opcode_UNDEF },
  { "DCX B",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "INR C",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "DCR C",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "MVI C,d8",   .length=2, .cycles=7,  &opcode_UNDEF },
  { "RRC",        .length=1, .cycles=4,  &opcode_UNDEF },
  { "*NOP",       .length=1, .cycles=4,  &opcode_UNDEF },
  { "LXI D,d16",  .length=3, .cycles=10, &opcode_UNDEF },
  { "STAX D",     .length=1, .cycles=7,  &opcode_UNDEF },
  { "INX D",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "INR D",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "DCR D",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "MVI D,d8",   .length=2, .cycles=7,  &opcode_UNDEF },
  { "RAL",        .length=1, .cycles=4,  &opcode_UNDEF },
  { "*NOP",       .length=1, .cycles=4,  &opcode_UNDEF },
  { "DAD D",      .length=1, .cycles=10, &opcode_UNDEF },
  { "LDAX D",     .length=1, .cycles=7,  &opcode_UNDEF },
  { "DCX D",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "INR E",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "DCR E",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "MVI E,d8",   .length=2, .cycles=7,  &opcode_UNDEF },
  { "RAR",        .length=1, .cycles=4,  &opcode_UNDEF },
  { "*NOP",       .length=1, .cycles=4,  &opcode_UNDEF },
  { "LXI H,d16",  .length=3, .cycles=10, &opcode_UNDEF },
  { "SHLD a16",   .length=3, .cycles=16, &opcode_UNDEF },
  { "INX H",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "INR H",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "DCR H",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "MVI H,d8",   .length=2, .cycles=7,  &opcode_UNDEF },
  { "DAA",        .length=1, .cycles=4,  &opcode_UNDEF },
  { "*NOP",       .length=1, .cycles=4,  &opcode_UNDEF },
  { "DAD H",      .length=1, .cycles=10, &opcode_UNDEF },
  { "LHLD a16",   .length=3, .cycles=16, &opcode_UNDEF },
  { "DCX H",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "INR L",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "DCR L",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "MVI L,d8",   .length=2, .cycles=7,  &opcode_UNDEF },
  { "CMA",        .length=1, .cycles=4,  &opcode_UNDEF },
  { "*NOP",       .length=1, .cycles=4,  &opcode_UNDEF },
  { "LXI SP,d16", .length=3, .cycles=10, &opcode_UNDEF },
  { "STA a16",    .length=3, .cycles=13, &opcode_UNDEF },
  { "INX SP",     .length=1, .cycles=5,  &opcode_UNDEF },
  { "INR M",      .length=1, .cycles=10, &opcode_UNDEF },
  { "DCR M",      .length=1, .cycles=10, &opcode_UNDEF },
  { "MVI M,d8",   .length=2, .cycles=10, &opcode_UNDEF },
  { "STC",        .length=1, .cycles=4,  &opcode_UNDEF },
  { "*NOP",       .length=1, .cycles=4,  &opcode_UNDEF },
  { "DAD SP",     .length=1, .cycles=10, &opcode_UNDEF },
  { "LDA a16",    .length=3, .cycles=13, &opcode_UNDEF },
  { "DCX SP",     .length=1, .cycles=5,  &opcode_UNDEF },
  { "INR A",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "DCR A",      .length=1, .cycles=5,  &opcode_UNDEF },
  { "MVI A,d8",   .length=2, .cycles=7,  &opcode_UNDEF },
  { "CMC",        .length=1, .cycles=4,  &opcode_UNDEF },
  { "MOV B,B",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV B,C",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV B,D",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV B,E",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV B,H",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV B,L",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV B,M",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV B,A",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV C,B",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV C,C",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV C,D",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV C,E",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV C,H",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV C,L",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV C,M",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV C,A",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV D,B",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV D,C",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV D,D",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV D,E",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV D,H",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV D,L",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV D,M",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV D,A",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV E,B",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV E,C",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV E,D",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV E,E",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV E,H",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV E,L",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV E,M",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV E,A",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV H,B",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV H,C",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV H,D",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV H,E",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV H,H",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV H,L",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV H,M",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV H,A",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV L,B",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV L,C",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV L,D",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV L,E",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV L,H",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV L,L",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV L,M",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV L,A",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV M,B",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV M,C",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV M,D",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV M,E",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV M,H",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV M,L",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "HLT",        .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV M,A",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV A,B",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV A,C",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV A,D",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV A,E",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV A,H",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV A,L",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "MOV A,M",    .length=1, .cycles=7,  &opcode_UNDEF },
  { "MOV A,A",    .length=1, .cycles=5,  &opcode_UNDEF },
  { "ADD B",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADD C",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADD D",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADD E",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADD H",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADD L",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADD M",      .length=1, .cycles=7,  &opcode_UNDEF },
  { "ADD A",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADC B",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADC C",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADC D",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADC E",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADC H",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADC L",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ADC M",      .length=1, .cycles=7,  &opcode_UNDEF },
  { "ADC A",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SUB B",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SUB C",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SUB D",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SUB E",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SUB H",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SUB L",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SUB M",      .length=1, .cycles=7,  &opcode_UNDEF },
  { "SUB A",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SBB B",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SBB C",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SBB D",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SBB E",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SBB H",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SBB L",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "SBB M",      .length=1, .cycles=7,  &opcode_UNDEF },
  { "SBB A",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ANA B",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ANA C",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ANA D",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ANA E",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ANA H",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ANA L",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ANA M",      .length=1, .cycles=7,  &opcode_UNDEF },
  { "ANA A",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "XRA B",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "XRA C",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "XRA D",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "XRA E",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "XRA H",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "XRA L",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "XRA M",      .length=1, .cycles=7,  &opcode_UNDEF },
  { "XRA A",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ORA B",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ORA C",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ORA D",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ORA E",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ORA H",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ORA L",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "ORA M",      .length=1, .cycles=7,  &opcode_UNDEF },
  { "ORA A",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "CMP B",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "CMP C",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "CMP D",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "CMP E",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "CMP H",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "CMP L",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "CMP M",      .length=1, .cycles=7,  &opcode_UNDEF },
  { "CMP A",      .length=1, .cycles=4,  &opcode_UNDEF },
  { "RNZ",        .length=1, .cycles=5,  &opcode_UNDEF },
  { "POP B",      .length=1, .cycles=10, &opcode_UNDEF },
  { "JNZ a16",    .length=3, .cycles=10, &opcode_UNDEF },
  { "JMP a16",    .length=3, .cycles=10, &opcode_UNDEF },
  { "CNZ a16",    .length=3, .cycles=11, &opcode_UNDEF },
  { "PUSH B",     .length=1, .cycles=11, &opcode_UNDEF },
  { "ADI d8",     .length=2, .cycles=7,  &opcode_UNDEF },
  { "RST 0",      .length=1, .cycles=11, &opcode_UNDEF },
  { "RZ",         .length=1, .cycles=5,  &opcode_UNDEF },
  { "RET",        .length=1, .cycles=10, &opcode_UNDEF },
  { "JZ a16",     .length=3, .cycles=10, &opcode_UNDEF },
  { "*JMP a16",   .length=3, .cycles=10, &opcode_UNDEF },
  { "CZ a16",     .length=3, .cycles=11, &opcode_UNDEF },
  { "CALL a16",   .length=3, .cycles=17, &opcode_UNDEF },
  { "ACI d8",     .length=2, .cycles=7,  &opcode_UNDEF },
  { "RST 1",      .length=1, .cycles=11, &opcode_UNDEF },
  { "RNC",        .length=1, .cycles=5,  &opcode_UNDEF },
  { "POP D",      .length=1, .cycles=10, &opcode_UNDEF },
  { "JNC a16",    .length=3, .cycles=10, &opcode_UNDEF },
  { "OUT d8",     .length=2, .cycles=10, &opcode_UNDEF },
  { "CNC a16",    .length=3, .cycles=11, &opcode_UNDEF },
  { "PUSH D",     .length=1, .cycles=11, &opcode_UNDEF },
  { "SUI d8",     .length=2, .cycles=7,  &opcode_UNDEF },
  { "RST 2",      .length=1, .cycles=11, &opcode_UNDEF },
  { "RC",         .length=1, .cycles=5,  &opcode_UNDEF },
  { "*RET",       .length=1, .cycles=10, &opcode_UNDEF },
  { "JC a16",     .length=3, .cycles=10, &opcode_UNDEF },
  { "IN d8",      .length=2, .cycles=10, &opcode_UNDEF },
  { "CC a16",     .length=3, .cycles=11, &opcode_UNDEF },
  { "*CALL a16",  .length=3, .cycles=17, &opcode_UNDEF },
  { "SBI d8",     .length=2, .cycles=7,  &opcode_UNDEF },
  { "RST 3",      .length=1, .cycles=11, &opcode_UNDEF },
  { "RPO",        .length=1, .cycles=5,  &opcode_UNDEF },
  { "POP H",      .length=1, .cycles=10, &opcode_UNDEF },
  { "JPO a16",    .length=3, .cycles=10, &opcode_UNDEF },
  { "XTHL",       .length=1, .cycles=18, &opcode_UNDEF },
  { "CPO a16",    .length=3, .cycles=11, &opcode_UNDEF },
  { "PUSH H",     .length=1, .cycles=11, &opcode_UNDEF },
  { "ANI d8",     .length=2, .cycles=7,  &opcode_UNDEF },
  { "RST 4",      .length=1, .cycles=11, &opcode_UNDEF },
  { "RPE",        .length=1, .cycles=5,  &opcode_UNDEF },
  { "PCHL",       .length=1, .cycles=5,  &opcode_UNDEF },
  { "JPE a16",    .length=3, .cycles=10, &opcode_UNDEF },
  { "XCHG",       .length=1, .cycles=5,  &opcode_UNDEF },
  { "CPE a16",    .length=3, .cycles=11, &opcode_UNDEF },
  { "*CALL a16",  .length=3, .cycles=17, &opcode_UNDEF },
  { "XRI d8",     .length=2, .cycles=7,  &opcode_UNDEF },
  { "RST 5",      .length=1, .cycles=11, &opcode_UNDEF },
  { "RP",         .length=1, .cycles=5,  &opcode_UNDEF },
  { "POP PSW",    .length=1, .cycles=10, &opcode_UNDEF },
  { "JP a16",     .length=3, .cycles=10, &opcode_UNDEF },
  { "DI",         .length=1, .cycles=4,  &opcode_UNDEF },
  { "CP a16",     .length=3, .cycles=11, &opcode_UNDEF },
  { "PUSH PSW",   .length=1, .cycles=11, &opcode_UNDEF },
  { "ORI d8",     .length=2, .cycles=7,  &opcode_UNDEF },
  { "RST 6",      .length=1, .cycles=11, &opcode_UNDEF },
  { "RM",         .length=1, .cycles=5,  &opcode_UNDEF },
  { "SPHL",       .length=1, .cycles=5,  &opcode_UNDEF },
  { "JM a16",     .length=3, .cycles=10, &opcode_UNDEF },
  { "EI",         .length=1, .cycles=4,  &opcode_UNDEF },
  { "CM a16",     .length=3, .cycles=11, &opcode_UNDEF },
  { "*CALL a16",  .length=3, .cycles=17, &opcode_UNDEF },
  { "CPI d8",     .length=2, .cycles=7,  &opcode_UNDEF },
  { "RST 7",      .length=1, .cycles=11, &opcode_UNDEF },
};