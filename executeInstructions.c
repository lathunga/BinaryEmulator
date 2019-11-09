//uint8_t
//*((uint64_t)(mem+address))

#include <ctype.h>
#include "executeInstructions.h"

#define is_bigendian() ( (*(char*)&i) == 0 )

int doInstruction(struct machineState* machineState)
{
  switch (machineState->instruction.type)
  {
   case 1:  return doAddi(machineState);

   case 2:  return doAndi(machineState);

   case 3:  return doEori(machineState);

   case 4:  return doOrri(machineState);

   case 5:  return doSubi(machineState);

   case 6:  return doSubis(machineState);

   case 7:  return doAdd(machineState);

   case 8:  return doAnd(machineState);

   case 9:  return doBr(machineState);

   case 10: return doEor(machineState);

   case 11: return doLsl(machineState);

   case 12: return doLsr(machineState);

   case 13: return doMul(machineState);

   case 14: return doOrr(machineState);

   case 17: return doSub(machineState);

   case 18: return doSubs(machineState);

   case 19: return doUdiv(machineState);

   case 21: return doDump(machineState);

   case 22: return doHalt(machineState);

   case 23: return doPrnl(machineState);

   case 24: return doPrnt(machineState);

   case 25: return doLdur(machineState);

   case 29: return doStur(machineState);

   case 33: return doB(machineState);

   case 34: return doBl(machineState);

   case 35: return doB_cond(machineState);

   case 36: return doCbnz(machineState);

   case 37: return doCbz(machineState);

   default:
   return ++machineState->count;
 }
}

/*initial testing*/
int doAddi(struct machineState* machineState)
{
  machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] + machineState->instruction.c1;
  shiftStages(machineState);
  machineState->count++;
  machineState->instructionsExecuted++;
  return machineState->count;
}
/*initial testing*/
int doAndi(struct machineState* machineState)
{
  machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] & machineState->instruction.c1;
  shiftStages(machineState);
  machineState->count++;
  machineState->instructionsExecuted++;
  return machineState->count;
}
/*initial testing*/
int doEori(struct machineState* machineState)
{
  machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] ^ machineState->instruction.c1;
  shiftStages(machineState);
  machineState->count++;
  machineState->instructionsExecuted++;
  return machineState->count;
}
/*initial testing*/
int doOrri(struct machineState* machineState)
{
  machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] | machineState->instruction.c1;
  shiftStages(machineState);
  machineState->count++;
  machineState->instructionsExecuted++;
  return machineState->count;
}
/*initial testing*/
int doSubi(struct machineState* machineState)
{
  machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] - machineState->instruction.c1;
  shiftStages(machineState);
  machineState->count++;
  machineState->instructionsExecuted++;
  return machineState->count;
}
/*Not tested (problem with given emulator?)*/
int doSubis(struct machineState* machineState)
{
  machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] - machineState->instruction.c1;
  shiftStages(machineState);
  if(machineState->registers[machineState->instruction.c4]==0)
  {
    machineState->eq = 1;
  }
  if(machineState->registers[machineState->instruction.c4]>=0)
  {
    machineState->ge = 1;
    machineState->hs = 1;
    machineState->pl = 1;
  }
  if(machineState->registers[machineState->instruction.c4]>0)
  {
    machineState->gt = 1;
    machineState->hi = 1;
  }
  if(machineState->registers[machineState->instruction.c4]<=0)
  {
    machineState->le = 1;
  }
  if(machineState->registers[machineState->instruction.c4]<0)
  {
    machineState->lt = 1;
    machineState->mi = 1;
  }
  if(machineState->registers[machineState->instruction.c4]!=0)
  {
    machineState->ne = 1;
  }
  if(machineState->registers[machineState->instruction.c4]>0)
  {
    machineState->gt = 1;
  }
  if(machineState->registers[machineState->instruction.c4]>0)
  {
    machineState->gt = 1;
  }
  machineState->vc = 0;
  machineState->vs = 0;
  machineState->count++;
  machineState->instructionsExecuted++;
  return machineState->count;
}

int doAdd(struct machineState* machineState)
{
  machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] + machineState->registers[machineState->instruction.c1];
  shiftStages(machineState);
  machineState->count++;
  machineState->instructionsExecuted++;
  return machineState->count;
}

int doAnd(struct machineState* machineState)
{
  machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] & machineState->registers[machineState->instruction.c1];
  shiftStages(machineState);
  machineState->count++;
  machineState->instructionsExecuted++;
  return machineState->count;
}

int doBr(struct machineState* machineState)
{
  machineState->count = machineState->registers[30]+1;
  shiftStages(machineState);
  machineState->instructionsExecuted++;
  return machineState->count;
}

int doEor(struct machineState* machineState)
{
   machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] ^ machineState->registers[machineState->instruction.c1];
   shiftStages(machineState);
   machineState->count++;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doLsl(struct machineState* machineState)
{
   machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] << machineState->instruction.c2;
   shiftStages(machineState);
   machineState->count++;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doLsr(struct machineState* machineState)
{
   machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] >> machineState->instruction.c2;
   shiftStages(machineState);
   machineState->count++;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doMul(struct machineState* machineState)
{
   machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] * machineState->registers[machineState->instruction.c1];
   shiftStages(machineState);
   machineState->count++;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doOrr(struct machineState* machineState)
{
   machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] | machineState->registers[machineState->instruction.c1];
   shiftStages(machineState);
   machineState->count++;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doSub(struct machineState* machineState)
{
   machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] - machineState->registers[machineState->instruction.c1];
   shiftStages(machineState);
   machineState->count++;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doSubs(struct machineState* machineState)
{
   machineState->registers[machineState->instruction.c4] = machineState->registers[machineState->instruction.c3] - machineState->registers[machineState->instruction.c1];
   shiftStages(machineState);
   if(machineState->registers[machineState->instruction.c4]==0)
   {
     machineState->eq = 1;
   }
   if(machineState->registers[machineState->instruction.c4]>=0)
   {
     machineState->ge = 1;
     machineState->hs = 1;
     machineState->pl = 1;
   }
   if(machineState->registers[machineState->instruction.c4]>0)
   {
     machineState->gt = 1;
     machineState->hi = 1;
   }
   if(machineState->registers[machineState->instruction.c4]<=0)
   {
     machineState->le = 1;
   }
   if(machineState->registers[machineState->instruction.c4]<0)
   {
     machineState->lt = 1;
     machineState->mi = 1;
   }
   if(machineState->registers[machineState->instruction.c4]!=0)
   {
     machineState->ne = 1;
   }
   if(machineState->registers[machineState->instruction.c4]>0)
   {
     machineState->gt = 1;
   }
   if(machineState->registers[machineState->instruction.c4]>0)
   {
     machineState->gt = 1;
   }
   machineState->vc = 0;
   machineState->vs = 0;
   machineState->count++;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doUdiv(struct machineState* machineState)
{
  int64_t quotient = machineState->registers[machineState->instruction.c3] / machineState->registers[machineState->instruction.c1];
  shiftStages(machineState);
  if(quotient<0)
  {
    quotient *= -1;
  }
  machineState->registers[machineState->instruction.c4] = quotient;
  machineState->count++;
  machineState->instructionsExecuted++;
  return machineState->count;
}

int doDump(struct machineState* machineState)
{
   printf("%s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) %s%016llx (%lld) \n\n",
   "Registers\n      X0:  0x", machineState->registers[0], machineState->registers[0], "\n      X1:  0x", machineState->registers[1], machineState->registers[1], "\n      X2:  0x", machineState->registers[2], machineState->registers[2], "\n      X3:  0x", machineState->registers[3], machineState->registers[3], "\n      X4:  0x", machineState->registers[4], machineState->registers[4], "\n      X5:  0x", machineState->registers[5], machineState->registers[5], "\n      X6:  0x", machineState->registers[6], machineState->registers[6], "\n      X7:  0x", machineState->registers[7], machineState->registers[7], "\n      X8:  0x", machineState->registers[8], machineState->registers[8], "\n      X9:  0x", machineState->registers[9], machineState->registers[9], "\n      X10: 0x", machineState->registers[10], machineState->registers[10], "\n      X11: 0x", machineState->registers[11], machineState->registers[11], "\n      X12: 0x", machineState->registers[12], machineState->registers[12], "\n      X13: 0x", machineState->registers[13], machineState->registers[13], "\n      X14: 0x", machineState->registers[14], machineState->registers[14], "\n      X15: 0x", machineState->registers[15], machineState->registers[15], "\n(IP0) X16: 0x", machineState->registers[16], machineState->registers[16], "\n(IP1) X17: 0x", machineState->registers[17], machineState->registers[17], "\n      X18: 0x", machineState->registers[18], machineState->registers[18], "\n      X19: 0x", machineState->registers[19], machineState->registers[19], "\n      X20: 0x", machineState->registers[20], machineState->registers[20], "\n      X21: 0x", machineState->registers[21], machineState->registers[21], "\n      X22: 0x", machineState->registers[22], machineState->registers[22], "\n      X23: 0x", machineState->registers[23], machineState->registers[23], "\n      X24: 0x", machineState->registers[24], machineState->registers[24], "\n      X25: 0x", machineState->registers[25], machineState->registers[25], "\n      X26: 0x", machineState->registers[26], machineState->registers[26], "\n      X27: 0x", machineState->registers[27], machineState->registers[27], "\n(SP)  X28: 0x", machineState->registers[28], machineState->registers[28], "\n(FP)  29X: 0x", machineState->registers[29], machineState->registers[29], "\n(LR)  X30: 0x", machineState->registers[30], machineState->registers[30], "\n(XZR) X31: 0x", machineState->registers[31], machineState->registers[31]);

   int mainMemoryIndex;
   int8_t mainMemoryEightBit[4096] = {0};
   int currentBit;
   int eightBitIndex = 0;
   unsigned long long mask1 = ((1 << 8) - 1);
   unsigned long long mask2;
   int64_t shifted;
   if(!is_bigendian())
   {
     for(mainMemoryIndex=0; mainMemoryIndex<512; mainMemoryIndex++)
     {
       for(currentBit = 56; currentBit>=0; currentBit=currentBit-8)
       {
         shifted = machineState->mainMemory[mainMemoryIndex];
         mask2 = mask1 << currentBit;
         shifted = shifted & mask2;
         mainMemoryEightBit[eightBitIndex] = shifted >> currentBit;
         eightBitIndex++;
       }
     }

     int stackIndex;
     int8_t stackEightBit[512] = {0};
     eightBitIndex = 0;
     for(stackIndex=0; stackIndex<64; stackIndex++)
     {
       for(currentBit = 56; currentBit>=0; currentBit=currentBit-8)
       {
         shifted = machineState->stack[stackIndex];
         mask2 = mask1 << currentBit;
         shifted = shifted & mask2;
         stackEightBit[eightBitIndex] = shifted >> currentBit;
         eightBitIndex++;
       }
     }
     hexdump(stackEightBit, 512);
     printf("\n");
     hexdump(mainMemoryEightBit, 4096);
   }
   else
   {
     hexdump((int8_t*)machineState->stack, 512);
     printf("\n");
     hexdump((int8_t*)machineState->mainMemory, 4096);
   }

   int j;
   for(j=0; j<machineState->length; j++)
   {
     if(machineState->program[j].format==1)
     {
       if(machineState->program[j].type==11 || machineState->program[j].type==12)
       {
         printf("  %s %s%lld%s%lld, %s%lld\n", machineState->program[j].name, "X", machineState->program[j].c4, ", X", machineState->program[j].c3, " #", machineState->program[j].c2);
       }
       else if(machineState->program[j].type==21)
       {
         if(j==machineState->count)
         {
           printf("->  %s\n", machineState->program[j].name);
         }
         else
         {
           printf("  %s\n", machineState->program[j].name);
         }
       }
       else if(machineState->program[j].type==22)
       {
         if(j==machineState->count)
         {
           printf("->  %s\n", machineState->program[j].name);
         }
         else
         {
           printf("  %s\n", machineState->program[j].name);
         }
       }
       else if(machineState->program[j].type==9)
       {
         printf("  %s %s%lld", machineState->program[j].name, "X", machineState->program[j].c3);
       }
       else
       {
         printf("  %s %s%lld%s%lld, %s%lld\n", machineState->program[j].name, "X", machineState->program[j].c4, ", X", machineState->program[j].c3, "X", machineState->program[j].c1);
       }
     }
     else if(machineState->program[j].format==2)
     {
       printf("  %s %s%lld%s%lld, #%lld\n", machineState->program[j].name, "X", machineState->program[j].c4, ", X", machineState->program[j].c3, machineState->program[j].c1);
     }
     else if(machineState->program[j].format==3)
     {
       printf("  %s %s%lld%s%lld, #%lld\n", machineState->program[j].name, "X", machineState->program[j].c4, ", X", machineState->program[j].c3, machineState->program[j].c1);
     }
     else if(machineState->program[j].format==4)
     {
       if(machineState->program[j].type==34)
       {
         printf("  %s %lld\n", machineState->program[j].name, machineState->program[j].c4);
       }
       else
       {
         printf("  %s %s%lld%s%lld, #%lld\n", machineState->program[j].name, "X", machineState->program[j].c4, ", X", machineState->program[j].c3, machineState->program[j].c1);
       }
     }
     else if(machineState->program[j].format==5)
     {
       if(machineState->program[j].type==36 || machineState->program[j].type==37)
       {
         printf("  %s %s%lld, %lld\n", machineState->program[j].name, "X", machineState->program[j].c4, machineState->program[j].c1);
       }
       else
       {
         printf("  %s", machineState->program[j].name);
         switch(machineState->program[j].c4)
         {
           case 0:
             printf("EQ");
             break;
           case 1:
             printf("NE");
             break;
           case 2:
             printf("HS");
             break;
           case 3:
             printf("LO");
             break;
           case 4:
             printf("MI");
             break;
           case 5:
             printf("PL");
             break;
           case 6:
             printf("VS");
             break;
           case 7:
             printf("VC");
             break;
           case 8:
             printf("HI");
             break;
           case 9:
             printf("LS");
             break;
           case 10:
             printf("GE");
             break;
           case 11:
             printf("LT");
             break;
           case 12:
             printf("GT");
             break;
           case 13:
             printf("LE");
             break;
         }
         printf(" %lld\n", machineState->program[j].c1);
       }
     }
   }
   printf("\n%s %d\n         %s %d\n        %s %d\n", "Extra:\n Instructions executed:", machineState->instructionsExecuted, "Loads issued:", machineState->loads, "Stores issued:", machineState->stores);
   machineState->count++;
   machineState->instructionsExecuted++;
   shiftStages(machineState);
   return machineState->count;
}

int doHalt(struct machineState* machineState)
{
   doDump(machineState);
   shiftStages(machineState);
   return -1;
}

int doPrnl(struct machineState* machineState)
{
   printf("\n");
   shiftStages(machineState);
   machineState->count++;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doPrnt(struct machineState* machineState)
{
   printf("\n%c%lld%s%x%s%lld%c", 'X', machineState->instruction.c4, ": hex(", machineState->registers[machineState->instruction.c4], ")   decimal(", machineState->registers[machineState->instruction.c4], ')');
   machineState->count++;
   shiftStages(machineState);
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doLdur(struct machineState* machineState)
{
  shiftStages(machineState);
  if(machineState->instruction.c3 == 28)
  {
    if(machineState->registers[28]+machineState->instruction.c1<=machineState->registers[29])
    {
      machineState->registers[machineState->instruction.c4] = machineState->stack[(machineState->registers[28]/8) + (machineState->instruction.c1/8)];
    }
    else
    {
      fprintf(stderr, "%s", "Stack out of bounds.");
    }
  }
  else
  {
    machineState->registers[machineState->instruction.c4] = machineState->mainMemory[(machineState->instruction.c1 + machineState->registers[machineState->instruction.c3])/8];
  }
  machineState->count++;
  machineState->loads++;
  machineState->instructionsExecuted++;
  return machineState->count;
}

int doStur(struct machineState* machineState)
{
  shiftStages(machineState);
   if(machineState->instruction.c3 == 28)
   {
     if(machineState->registers[28]+machineState->instruction.c1<=machineState->registers[29])
     {
       machineState->stack[(machineState->registers[28]/8) + (machineState->instruction.c1/8)] = machineState->registers[machineState->instruction.c4];
     }
     else
     {
       fprintf(stderr, "%s", "Stack out of bounds.");
     }
   }
   else
   {
     machineState->mainMemory[(machineState->instruction.c1 + machineState->registers[machineState->instruction.c3])/8] = machineState->registers[machineState->instruction.c4];
   }
   machineState->count++;
   machineState->stores++;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doB(struct machineState* machineState)
{
  shiftStages(machineState);
   machineState->count = machineState->instruction.c1 + machineState->count;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doBl(struct machineState* machineState)
{
  shiftStages(machineState);
   machineState->registers[30] = machineState->count;
   machineState->count = machineState->instruction.c1 + machineState->count;
   machineState->instructionsExecuted++;
   return machineState->count;
}

int doB_cond(struct machineState* machineState)
{
  shiftStages(machineState);
  machineState->instructionsExecuted++;
   switch(machineState->instruction.c4)
   {
     case 0:
      return branchIf(machineState->eq, machineState);
     case 1:
      return branchIf(machineState->ne, machineState);
     case 2:
      return branchIf(machineState->hs, machineState);
     case 3:
      return branchIf(machineState->lo, machineState);
     case 4:
      return branchIf(machineState->mi, machineState);
     case 5:
      return branchIf(machineState->pl, machineState);
     case 6:
      return branchIf(machineState->vs, machineState);
     case 7:
      return branchIf(machineState->vc, machineState);
     case 8:
      return branchIf(machineState->hi, machineState);
     case 9:
      return branchIf(machineState->ls, machineState);
     case 10:
      return branchIf(machineState->ge, machineState);
     case 11:
      return branchIf(machineState->lt, machineState);
     case 12:
      return branchIf(machineState->gt, machineState);
     case 13:
      return branchIf(machineState->le, machineState);
     default:
      return machineState->count++;
   }
}

int doCbnz(struct machineState* machineState)
{
  shiftStages(machineState);
  if(machineState->registers[machineState->instruction.c4] != 0)
  {
    machineState->instructionsExecuted++;
    machineState->count = machineState->instruction.c1 + machineState->count;
    return machineState->count;
  }
  else
  {
    machineState->instructionsExecuted++;
    machineState->count++;
    return machineState->count;
  }
}

int doCbz(struct machineState* machineState)
{
  shiftStages(machineState);
  if(machineState->registers[machineState->instruction.c4] == 0)
  {
    machineState->instructionsExecuted++;
    machineState->count = machineState->instruction.c1 + machineState->count;
    return machineState->count;
  }
  else
  {
    machineState->instructionsExecuted++;
    machineState->count++;
    return machineState->count;
  }
}

int branchIf(int flag, struct machineState* machineState)
{
   if(flag==1)
   {
     machineState->count = machineState->instruction.c1 + machineState->count;
     return machineState->count;
   }
   machineState->count++;
   return machineState->count;
}

char printable_char(uint8_t c)
{
   return isprint(c) ? c : '.';
}

void hexdump(int8_t *start, size_t size)
{
   size_t i;

   for (i = 0; i < size - (size % 16); i += 16) {
     printf(
             "%08x "
             " %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx "
             " %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx "
             " |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",
             (int32_t) i,
             start[i +  0], start[i +  1], start[i +  2], start[i +  3],
             start[i +  4], start[i +  5], start[i +  6], start[i +  7],
             start[i +  8], start[i +  9], start[i + 10], start[i + 11],
             start[i + 12], start[i + 13], start[i + 14], start[i + 15],
             printable_char(start[i +  0]), printable_char(start[i +  1]),
             printable_char(start[i +  2]), printable_char(start[i +  3]),
             printable_char(start[i +  4]), printable_char(start[i +  5]),
             printable_char(start[i +  6]), printable_char(start[i +  7]),
             printable_char(start[i +  8]), printable_char(start[i +  9]),
             printable_char(start[i + 10]), printable_char(start[i + 11]),
             printable_char(start[i + 12]), printable_char(start[i + 13]),
             printable_char(start[i + 14]), printable_char(start[i + 15]));
   }
   printf("%08x\n", (int32_t) size);
}

int shiftStages(struct machineState* machineState)
{
  struct instruction empty = {0, 0, 0, 0, 0, 0, 0};
  struct instruction finished = {0, 0, 0, 0, 0, 0, 0};
  int stall = 0;
  if((machineState->count == machineState->length || machineState->count == -1) && machineState->stages[0].type==0 && machineState->stages[1].type==0 && machineState->stages[2].type==0 && machineState->stages[3].type==0 && machineState->stages[4].type==0)
  {
    return 0;
  }
  if(machineState->stages[4].type!=0)
  {
    finished = machineState->stages[4];
    machineState->stages[4] = empty;
  }
  if(machineState->stages[3].type!=0)
  {
    machineState->stages[4] = machineState->stages[3];
    machineState->stages[3] = empty;
  }
  if(machineState->stages[2].type!=0)
  {
    machineState->stages[3] = machineState->stages[2];
    machineState->stages[2] = empty;
  }
  if(machineState->stages[1].type!=0)
  {
    if(machineState->stages[4].type==25 || machineState->stages[4].format==1 || machineState->stages[4].format==2)
    {
      if( (machineState->stages[1].format==1 || machineState->stages[1].format==3) && (machineState->stages[1].c3==machineState->stages[4].c4 || machineState->stages[1].c1==machineState->stages[4].c4) )
      {
        stall = 1;
        machineState->dataHazards++;
      }
      else if( ( machineState->stages[1].format==2) && (machineState->stages[1].c3==machineState->stages[4].c4))
      {
        stall = 1;
        machineState->dataHazards++;
      }
      else if( (machineState->stages[1].format==5) && (machineState->stages[1].c4==machineState->stages[4].c4) )
      {
        stall = 1;
        machineState->dataHazards++;
      }
    }
    if(machineState->stages[3].type==25 || machineState->stages[3].format==1 || machineState->stages[3].format==2)
    {
      if( (machineState->stages[1].format==1 || machineState->stages[1].format==3) && (machineState->stages[1].c3==machineState->stages[3].c4 || machineState->stages[1].c1==machineState->stages[3].c4) )
      {
        stall = 1;
      }
      else if( ( machineState->stages[1].format==2) && (machineState->stages[1].c3==machineState->stages[3].c4))
      {
        stall = 1;
      }
      else if( (machineState->stages[1].format==5) && (machineState->stages[1].c4==machineState->stages[3].c4) )
      {
        stall = 1;
      }
    }
    if(machineState->stages[2].type==25 || machineState->stages[2].format==1 || machineState->stages[2].format==2)
    {
      if( (machineState->stages[1].format==1 || machineState->stages[1].format==3) && (machineState->stages[1].c3==machineState->stages[2].c4 || machineState->stages[1].c1==machineState->stages[2].c4) )
      {
        stall = 1;
      }
      else if( ( machineState->stages[1].format==2) && (machineState->stages[1].c3==machineState->stages[2].c4))
      {
        stall = 1;
      }
      else if( (machineState->stages[1].format==5) && (machineState->stages[1].c4==machineState->stages[2].c4) )
      {
        stall = 1;
      }
    }
    if(stall==0)
    {
      machineState->stages[2] = machineState->stages[1];
      machineState->stages[1] = empty;
    }
  }
  if(machineState->stages[0].format==5 || machineState->stages[1].format==5 || machineState->stages[2].format==5 || machineState->stages[3].format==5 || machineState->stages[4].format==5)
  {
    shiftStages(machineState);
  }
  if(machineState->stages[1].type==0)
  {
    if(machineState->stages[0].type!=0)
    {
      machineState->stages[1] = machineState->stages[0];
      machineState->stages[0] = empty;
    }
    else if(machineState->count!=machineState->length && machineState->count!=-1)
    {
      machineState->stages[1] = machineState->instruction;
      machineState->unpipelinedCycles++;
      return 1;
    }
  }
  if(machineState->count!=machineState->length && machineState->count!=-1 && machineState->stages[0].type==0)
  {
    machineState->stages[0] = machineState->instruction;
    machineState->unpipelinedCycles++;
    return 1;
  }
  else
  {
    machineState->unpipelinedCycles++;
    shiftStages(machineState);
  }
  return 0;
}
