CC       := -c++
CFLAGS   := -pedantic-errors -Wall -Wextra -Werror -Ofast
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
TARGET   := solvedoku
INCLUDE  := -Iinclude/
SRC      := $(wildcard src/*.cpp)
OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(BUILD)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) $(LDFLAGS) -o $(BUILD)/$(TARGET) $(OBJECTS)

.PHONY: all build clean run

all: build $(BUILD)/$(TARGET)

build:
	@mkdir -p $(OBJ_DIR)

clean:
	-@rm -rvf $(BUILD)/*

run: $(BUILD)/$(TARGET)
	@./$(BUILD)/$(TARGET)
