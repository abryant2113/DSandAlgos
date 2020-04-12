EXE := main

CC:= g++

BIN_DIR := bin
SRC_DIR := src
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude

.PHONY: all clean

all: $(EXE) | $(BIN_DIR)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $(BIN_DIR)/$@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

clean:
	$(RM) $(OBJ)

run: $(EXE)
	$(BIN_DIR)/main