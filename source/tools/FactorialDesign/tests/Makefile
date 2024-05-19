# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = ../FactorialDesign.cpp unittests.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXECUTABLE = UnitTests

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)
