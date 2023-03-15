#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

typedef struct {
  char name[10]; // Opcode name
  char length; // How many bytes of memory the instruction uses,
  char cycles;  // Base number of cycles required for this instruction. It will always take this long to execute.
  int* execute; // Pointer to the function for this opcode. Returns the number of extra cycles the instruction took on top of the base cycle count, which is usually 0.
} Opcode;

#endif // INSTRUCTIONS_H

