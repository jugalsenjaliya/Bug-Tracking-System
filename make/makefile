INC_DIR := ../inc
SRC_DIR := ../src
OBJ_DIR := ../obj
BIN_DIR := ../bin
CC := g++

EXE := $(BIN_DIR)/a.out
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CIFLAGS := -I $(INC_DIR)
CFLAGS := -Wall -c -g
LDFLAGS := -Llib
LDLIBS := -lm

all = $(EXE)

$(EXE) : $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CIFLAGS) $(CFLAGS) $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
