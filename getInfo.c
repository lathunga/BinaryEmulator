#include "getInfo.h"
#include <stdio.h>

#define is_bigendian() ( (*(char*)&i) == 0 )

uint64_t reverseInt (uint64_t i)
{
  unsigned char c1, c2, c3, c4;
  if (is_bigendian())
  {
    return i;
  }
  else
  {
    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;
    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
  }
}

void addToStruct(uint32_t instructionBinary, struct instruction* program, int j)
{
  int32_t newInstruction = reverseInt(instructionBinary);
  unsigned  mask;
  mask = ((1 << 10) - 1) << 22;
  uint32_t shifted = newInstruction & mask;
  shifted = shifted >> 22;
  if(shifted == addi)
  {
    setVariables(2, newInstruction, program, j);
    program[j].type = 1;
    program[j].name = malloc(4*sizeof(char));
    program[j].name = "ADDI";
  }
  else if(shifted == andi)
  {
    setVariables(2, newInstruction, program, j);
    program[j].type = 2;
    program[j].name = malloc(4*sizeof(char));
    program[j].name = "ANDI";
  }
  else if(shifted == eori)
  {
    setVariables(2, newInstruction, program, j);
    program[j].type = 3;
    program[j].name = malloc(4*sizeof(char));
    program[j].name = "EORI";
  }
  else if(shifted == orri)
  {
    setVariables(2, newInstruction, program, j);
    program[j].type = 4;
    program[j].name = malloc(4*sizeof(char));
    program[j].name = "ORRI";
  }
  else if(shifted == subi)
  {
    setVariables(2, newInstruction, program, j);
    program[j].type = 5;
    program[j].name = malloc(4*sizeof(char));
    program[j].name = "SUBI";
  }
  else if(shifted == subis)
  {
    setVariables(2, newInstruction, program, j);
    program[j].type = 6;
    program[j].name = malloc(5*sizeof(char));
    program[j].name = "SUBIS";
  }
  else
  {
    mask = ((1 << 11) - 1) << 21;
    uint32_t shifted = newInstruction & mask;
    shifted = shifted >> 21;
    if(shifted == add)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 7;
      program[j].name = malloc(3*sizeof(char));
      program[j].name = "ADD";
    }
    else if(shifted == and)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 8;
      program[j].name = malloc(3*sizeof(char));
      program[j].name = "AND";
    }
    else if(shifted == br)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 9;
      program[j].name = malloc(2*sizeof(char));
      program[j].name = "BR";
    }
    else if(shifted == eor)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 10;
      program[j].name = malloc(3*sizeof(char));
      program[j].name = "EOR";
    }
    else if(shifted == lsl)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 11;
      program[j].name = malloc(3*sizeof(char));
      program[j].name = "LSL";
    }
    else if(shifted == lsr)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 12;
      program[j].name = malloc(3*sizeof(char));
      program[j].name = "LSR";
    }
    else if(shifted == mul)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 13;
      program[j].name = malloc(3*sizeof(char));
      program[j].name = "MUL";
    }
    else if(shifted == orr)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 14;
      program[j].name = malloc(3*sizeof(char));
      program[j].name = "ORR";
    }
    else if(shifted == smulh)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 16;
      program[j].name = malloc(5*sizeof(char));
      program[j].name = "SMULH";
    }
    else if(shifted == sub)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 17;
      program[j].name = malloc(3*sizeof(char));
      program[j].name = "SUB";
    }
    else if(shifted == subs)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 18;
      program[j].name = malloc(4*sizeof(char));
      program[j].name = "SUBS";
    }
    else if(shifted == udiv)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 19;
      program[j].name = malloc(4*sizeof(char));
      program[j].name = "UDIV";
    }
    else if(shifted == umulh)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 20;
      program[j].name = malloc(5*sizeof(char));
      program[j].name = "UMULH";
    }
    else if(shifted == dump)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 21;
      program[j].name = malloc(4*sizeof(char));
      program[j].name = "DUMP";
    }
    else if(shifted == halt)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 22;
      program[j].name = malloc(4*sizeof(char));
      program[j].name = "HALT";
    }
    else if(shifted == prnl)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 23;
      program[j].name = malloc(4*sizeof(char));
      program[j].name = "PRNL";
    }
    else if(shifted == prnt)
    {
      setVariables(1, newInstruction, program, j);
      program[j].type = 24;
      program[j].name = malloc(4*sizeof(char));
      program[j].name = "PRNT";
    }
    else if(shifted == ldur)
    {
      setVariables(3, newInstruction, program, j);
      program[j].type = 25;
      program[j].name = malloc(4*sizeof(char));
      program[j].name = "LDUR";
    }
    else if(shifted == ldurb)
    {
      setVariables(3, newInstruction, program, j);
      program[j].type = 26;
      program[j].name = malloc(5*sizeof(char));
      program[j].name = "LDURB";
    }
    else if(shifted == ldurh)
    {
      setVariables(3, newInstruction, program, j);
      program[j].type = 27;
      program[j].name = malloc(5*sizeof(char));
      program[j].name = "LDURH";
    }
    else if(shifted == ldursw)
    {
      setVariables(3, newInstruction, program, j);
      program[j].type = 28;
      program[j].name = malloc(6*sizeof(char));
      program[j].name = "LDURSW";
    }
    else if(shifted == stur)
    {
      setVariables(3, newInstruction, program, j);
      program[j].type = 29;
      program[j].name = malloc(4*sizeof(char));
      program[j].name = "STUR";
    }
    else if(shifted == sturb)
    {
      setVariables(3, newInstruction, program, j);
      program[j].type = 30;
      program[j].name = malloc(5*sizeof(char));
      program[j].name = "STURB";
    }
    else if(shifted == sturh)
    {
      setVariables(3, newInstruction, program, j);
      program[j].type = 31;
      program[j].name = malloc(5*sizeof(char));
      program[j].name = "STURH";
    }
    else if(shifted == sturw)
    {
      setVariables(3, newInstruction, program, j);
      program[j].type = 32;
      program[j].name = malloc(5*sizeof(char));
      program[j].name = "STURSW";
    }
    else
    {
      mask = ((1 << 6) - 1) << 26;
      uint32_t shifted = newInstruction & mask;
      shifted = shifted >> 26;
      if(shifted == b)
      {
        setVariables(4, newInstruction, program, j);
        program[j].type = 33;
        program[j].name = malloc(1*sizeof(char));
        program[j].name = "B";
      }
      else if(shifted == bl)
      {
        setVariables(4, newInstruction, program, j);
        program[j].type = 34;
        program[j].name = malloc(2*sizeof(char));
        program[j].name = "BL";
      }
      else
      {
        mask = ((1 << 8) - 1) << 24;
        uint32_t shifted = newInstruction & mask;
        shifted = shifted >> 24;
        if(shifted == b_cond)
        {
          setVariables(5, newInstruction, program, j);
          program[j].type = 35;
          program[j].name = malloc(2*sizeof(char));
          program[j].name = "B.";
        }
        else if(shifted == cbnz)
        {
          setVariables(5, newInstruction, program, j);
          program[j].type = 36;
          program[j].name = malloc(4*sizeof(char));
          program[j].name = "CBNZ";
        }
        else if(shifted == cbz)
        {
          setVariables(5, newInstruction, program, j);
          program[j].type = 37;
          program[j].name = malloc(3*sizeof(char));
          program[j].name = "CBZ";
        }
      }
    }
  }
}

void setVariables(int format, uint32_t newInstruction, struct instruction* program, int j)
{
  unsigned mask;
  uint32_t shifted;
  if(format==1)
  {
    mask = ((1 << 5) - 1) << 16;
    shifted = newInstruction & mask;
    shifted = shifted >> 16;
    program[j].c1 = shifted;

    mask = ((1 << 6) - 1) << 10;
    shifted = newInstruction & mask;
    shifted = shifted >> 10;
    program[j].c2 = shifted;

    mask = ((1 << 5) - 1) << 5;
    shifted = newInstruction & mask;
    shifted = shifted >> 5;
    program[j].c3 = shifted;

    mask = ((1 << 5) - 1) << 0;
    shifted = newInstruction & mask;
    program[j].c4 = shifted;

    program[j].format = 1;
  }
  else if(format==2)
  {
    mask = ((1 << 12) - 1) << 10;
    shifted = newInstruction & mask;
    shifted = shifted >> 10;
    uint32_t temp = shifted >> 11;
    if(temp == 1)
    {
      int i = 31;
      while(i>11)
      {
        shifted ^= (1 << i);
        i--;
      }
    }
    program[j].c1 = (int32_t) shifted;

    program[j].c2 = 0;

    mask = ((1 << 5) - 1) << 5;
    shifted = newInstruction & mask;
    shifted = shifted >> 5;
    program[j].c3 = shifted;

    mask = ((1 << 5) - 1) << 0;
    shifted = newInstruction & mask;
    program[j].c4 = shifted;

    program[j].format = 2;
  }
  else if(format==3)
  {
    mask = ((1 << 9) - 1) << 12;
    shifted = newInstruction & mask;
    shifted = shifted >> 12;
    program[j].c1 = shifted;

    mask = ((1 << 2) - 1) << 10;
    shifted = newInstruction & mask;
    shifted = shifted >> 10;
    program[j].c2 = shifted;

    mask = ((1 << 5) - 1) << 5;
    shifted = newInstruction & mask;
    shifted = shifted >> 5;
    program[j].c3 = shifted;

    mask = ((1 << 5) - 1) << 0;
    shifted = newInstruction & mask;
    program[j].c4 = shifted;

    program[j].format = 3;
  }
  else if(format==4)
  {
    mask = ((1 << 26) - 1) << 0;
    shifted = newInstruction & mask;
    program[j].c1 = shifted;
    uint32_t temp = shifted;
    printf("d", temp);
    if(temp == 1)
    {
      int i = 31;
      while(i>11)
      {
        shifted ^= (1 << i);
        i--;
      }
    }
    program[j].c1 = (int32_t) shifted;

    program[j].c2 = 0;

    program[j].c3 = 0;

    program[j].c4 = 0;

    program[j].format = 4;
  }
  else if(format==5)
  {

    mask = ((1 << 19) - 1) << 5;
    shifted = newInstruction & mask;
    shifted = shifted >> 5;
    program[j].c1 = shifted;

    program[j].c2 = 0;

    program[j].c3 = 0;

    mask = ((1 << 5) - 1) << 0;
    shifted = newInstruction & mask;
    program[j].c4 = shifted;

    program[j].format = 5;
  }
}
