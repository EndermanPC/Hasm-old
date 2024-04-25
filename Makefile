SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INCLUDE_DIRS := include

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
TARGET := hasm
CC := g++
CFLAGS := -c -Wall $(addprefix -I,$(INCLUDE_DIRS))
LDFLAGS :=
RM := rm -f

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ_DIR)/*.o
	$(RM) $(OBJ_DIR)/*/*.o
	$(RM) $(BIN_DIR)/$(TARGET)

rebuild: clean all

run: all
	./$(BIN_DIR)/$(TARGET)
