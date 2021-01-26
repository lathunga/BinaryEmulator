CFLAGS += -g

emulator: constants.o structs.o getInfo.o executeInstructions.o binaryEmulator.o
	gcc binaryEmulator.o getInfo.o executeInstructions.o structs.o constants.o -o emulator

constants.o: constants.c constants.h
	gcc -g -c constants.c

structs.o: structs.c structs.h
	gcc -g -c structs.c

getInfo.o: getInfo.c getInfo.h constants.h
	gcc -g -c getInfo.c

executeInstructions.o: executeInstructions.c executeInstructions.h
	gcc -g -c executeInstructions.c

binaryEmulator.o: binaryEmulator.c getInfo.h executeInstructions.h
	gcc -g -c binaryEmulator.c

clean:
	rm -f *.o emulator
