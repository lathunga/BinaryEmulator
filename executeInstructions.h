#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "constants.h"
#include "structs.c"

void hexdump(int8_t *start, size_t size);
char printable_char(uint8_t c);
int branchIf(int flag, struct machineState* machineState);

int doInstruction(struct machineState* machineState);


int doAddi(struct machineState* machineState);
int doAndi(struct machineState* machineState);
int doEori(struct machineState* machineState);
int doOrri(struct machineState* machineState);
int doSubi(struct machineState* machineState);
int doSubis(struct machineState* machineState);

int doAdd(struct machineState* machineState);
int doAnd(struct machineState* machineState);
int doBr(struct machineState* machineState);
int doEor(struct machineState* machineState);
int doLsl(struct machineState* machineState);
int doLsr(struct machineState* machineState);
int doMul(struct machineState* machineState);
int doOrr(struct machineState* machineState);
int doSub(struct machineState* machineState);
int doSubs(struct machineState* machineState);
int doUdiv(struct machineState* machineState);
int doDump(struct machineState* machineState);
void doHalt(struct machineState* machineState);
int doPrnl(struct machineState* machineState);
int doPrnt(struct machineState* machineState);

int doLdur(struct machineState* machineState);
int doStur(struct machineState* machineState);

int doB(struct machineState* machineState);
int doBl(struct machineState* machineState);

int doB_cond(struct machineState* machineState);
int doCbnz(struct machineState* machineState);
int doCbz(struct machineState* machineState);
