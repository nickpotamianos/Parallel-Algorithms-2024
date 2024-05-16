# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -fopenmp

# Source files
SRCS = linear_array_sort.cpp

# Output executable
TARGET = linear_array_sort

# Default target to compile the program
all: $(TARGET)

# Rule to link and create the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up the build
clean:
	rm -f $(TARGET)
	rm -f *.o

# Phony targets
.PHONY: all run clean
