CC := clang
CFLAGS := -Wall -Werror -Wextra -pedantic
LIBS := -lncurses -lm
TARGET := cat-run

SOURCE_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

$(shell mkdir -p $(BUILD_DIR))

sources := $(wildcard $(SOURCE_DIR)/*.c)
objects := $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(sources))

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(TARGET): $(objects)
	$(CC) $(CFLAGS) $(objects) $(LIBS) -o $(TARGET)

.PHONY: clean debug

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

debug: CFLAGS += -ggdb
debug: $(TARGET)

optimize: CFLAGS += -O3
optimize: $(TARGET)

