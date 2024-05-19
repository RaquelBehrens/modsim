CC = g++
CFLAGS = -Wall -std=c++14 -g -fdiagnostics-color=always
TARGET = a.out
TARGET_TEST = runTests.out

SRC_DIR = $(PWD)
TEST_DIR = $(SRC_DIR)/unitTests
OUTPUT_DIR = $(PWD)

TEST_SRCS_OBJS = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS_1 = $(patsubst $(SRC_DIR)/%.cpp, $(OUTPUT_DIR)/%.o, $(TEST_SRCS_OBJS))
TEST_OBJS_2 = $(patsubst $(TEST_DIR)/%.cpp, $(OUTPUT_DIR)/%.o, $(TEST_SRCS))

# Source files list
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/../../kernel/statistics/*.cpp)
# SRCS += $(wildcard $(SRC_DIR)/../../kernel/simulator/*.cpp)
SRCS += $(SRC_DIR)/../../kernel/simulator/ExperimentManagerDefaultImpl1.cpp
SRCS += $(wildcard $(SRC_DIR)/../*.cpp)

# Gere a lista de objetos automaticamente
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OUTPUT_DIR)/%.o, $(SRCS))

#  ------ Compilation rules ------
all: $(TARGET)

# Compile objects into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/$(TARGET) $(OBJS)

# Compile source file into object
$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

test: clean $(TARGET_TEST)
	./$(TARGET_TEST)

$(TARGET_TEST): $(TEST_OBJS_1) $(TEST_OBJS_2)
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/$(TARGET_TEST) $(TEST_OBJS_1) $(TEST_OBJS_2)

$(OUTPUT_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUTPUT_DIR)/*.o $(OUTPUT_DIR)/$(TARGET) $(OUTPUT_DIR)/$(TARGET_TEST) $(OBJS)

.PHONY: all clean
