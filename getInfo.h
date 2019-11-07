#include <inttypes.h>
#include <stdlib.h>
#include "structs.h"
#include "constants.h"
#include "structs.c"

uint64_t reverseInt (uint64_t i);

void addToStruct(uint32_t instructionBinary, struct instruction* instruction, int j);
void setVariables(int format, uint32_t newInstruction, struct instruction* program, int j);
