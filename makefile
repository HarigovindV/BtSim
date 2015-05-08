CXX=g++
TARGET = Simulator
CXXFLAGS=-I. -std=c++11
DEPS = Battery.h Main.h Resistor.h Cell.h Switch.h Utils.h
OBJ = Battery.o Main.o Resistor.o Cell.o Switch.o Utils.o
%.o: %.cpp %.CPP $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)
clean:$(OBJ) $(TARGET)
	rm -rf $(OBJ) $(TARGET)

