CC = gcc
CFLAGS = -Iincludes -Wall -Wextra -std=c11
LIBS = -lsqlite3
TARGET = bin/country_manager

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,build/%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CC) $^ -o $@ $(LIBS)
	@echo "=== Build complete ==="
	@echo "Executable: $(TARGET)"

build/%.o: $(SRC_DIR)/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build bin

.PHONY: all clean
