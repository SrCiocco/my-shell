CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -g
BUILD_DIR = build

$(BUILD_DIR)/myshell: $(BUILD_DIR)/main.o
	$(CC) -o $@ $(BUILD_DIR)/main.o

$(BUILD_DIR)/main.o: src/main.c | $(BUILD_DIR)
	$(CC) -c $< $(CFLAGS) -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean
.PHONY: run

clean:
	rm -rfv build

run:
	./build/myshell
