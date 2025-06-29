# Makefile for building your C++ project

# Compiler
CXX = clang++
CXXFLAGS = -std=gnu++14 -g -Wall -Wextra -fcolor-diagnostics -fansi-escape-codes

# Output executable
TARGET = helpers

# Source files
SRCS = helpers.cpp date.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files into final binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
