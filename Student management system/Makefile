 # Makefile for Student/Library Management System

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Iinclude -std=c++17

# Source files
SRC = src/main.cpp src/LibraryManager.cpp src/Book.cpp

# Output executable
TARGET = app

# Default target
all: $(TARGET)

# Compile and link
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean compiled files
clean:
	rm -f $(TARGET) src/*.o

.PHONY: all clean