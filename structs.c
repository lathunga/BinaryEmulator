#ifndef STRUCTS_C
#define STRUCTS_C
#include <inttypes.h>
#include "structs.h"

struct instruction
{
  int64_t c1;
  int64_t c2;
  int64_t c3;
  int64_t c4;

  int type;
  int format;

  char* name;
};

struct machineState
{
  int eq;
  int ge;
  int gt;
  int hi;
  int hs;
  int le;
  int lo;
  int ls;
  int lt;
  int mi;
  int ne;
  int pl;
  int vc;
  int vs;

  int64_t* registers;

  int64_t* mainMemory;

  int64_t* stack;

  int length;

  int count;

  struct instruction* program;
  struct instruction instruction;
  struct instruction* stages;

  uint32_t* buffer;

  int loads;

  int stores;

  int instructionsExecuted;

  int unpipelinedCycles;

  int dataHazards;

  int controlHazards;
};
#endif
