CC=gcc
CFLAGS=-I.
DEPS = Battery.h Main.h Resistor.h Cell.h Switch.h
OBJ = Battery.o Main.o Resistor.o Cell.o Switch.o Utils.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Simulator: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)