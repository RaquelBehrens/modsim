# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = FactorialDesign.cpp main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXECUTABLE = FactorialDesign

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)
