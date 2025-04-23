# Makefile для Country Management System

# Компилятор
CC = gcc
# Флаги компиляции
CFLAGS = -Iincludes -Wall -Wextra -std=c11
# Библиотеки
LIBS = -lsqlite3
# Имя исполняемого файла
TARGET = bin/country_manager

# Исходные файлы
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,build/%.o,$(SRC))

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CC) $^ -o $@ $(LIBS)
	@echo "=== Сборка завершена ==="
	@echo "Исполняемый файл: $(TARGET)"

# Компиляция объектных файлов
build/%.o: $(SRC_DIR)/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf build bin
	@echo "=== Очистка завершена ==="

# Пересборка
rebuild: clean all

# Запуск
run: $(TARGET)
	@echo "=== Запуск программы ==="
	./$(TARGET)

.PHONY: all clean rebuild run
