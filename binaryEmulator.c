#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "getInfo.h"
#include "executeInstructions.h"

int main(int argc, char *argv[])
{

  int64_t registers[32] = {0};
  registers[28] = 512;
  registers[29] = 512;

  int64_t stack[64] = {0};

  int64_t mainMemory[512] = {0};

  FILE* input = fopen(argv[1], "rb");
  fseek(input, 0L, SEEK_END);
  int length = ftell(input)/4;
  fseek(input, 0L, SEEK_SET);
  uint32_t buffer[length];
  fread(buffer, 4, length, input);
  fclose(input);

  struct instruction program[length];
  int j;
  for(j=0; j<length; j++)
  {
      addToStruct(buffer[j], program, j);
  }

  struct instruction stages[5] = {0};
  struct machineState* machineState = malloc(sizeof(struct machineState));
  machineState->stages = stages;
  machineState->registers = registers;
  machineState->mainMemory = mainMemory;
  machineState->stack = stack;
  machineState->length = length;
  machineState->program = program;
  machineState->buffer = buffer;
  machineState->count = 0;
  machineState->loads = 0;
  machineState->stores = 0;
  machineState->instructionsExecuted = 0;
  while(machineState->count<length && machineState->count!=-1)
  {
    machineState->instruction = machineState->program[machineState->count];
    machineState->count = doInstruction(machineState);
  }
  if(machineState->stages[0].type!=0)
  {
    machineState->unpipelinedCycles+=5;
  }
  printf("Statistics:");
  printf("  \n%s %d", "Number of cycles required on an unpipelined implementation: ", machineState->instructionsExecuted);
  printf("  \n%s %d", "Number of cycles required on a pipelined implementation without bypassing or branch prediction: ", machineState->instructionsExecuted);
}
