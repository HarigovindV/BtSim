CC=g++
CXXFLAGS=-I. -std=c++11
DEPS = Battery.h Main.h Resistor.h Cell.h Switch.h Utils.h
OBJ = Battery.o Main.o Resistor.o Cell.o Switch.o Utils.o
%.o: %.cpp %.CPP $(DEPS)
        $(CC) -c -o $@ $< $(CXXFLAGS)
Simulator: $(OBJ)
        gcc -o $@ $^ $(CXXFLAGS)

