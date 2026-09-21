CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2 -Iapplications/inc
LDFLAGS ?= -pthread

SRC = applications/src/main.c applications/src/gateway.c applications/src/serial.c applications/src/protocol.c applications/src/logger.c applications/src/network.c
OBJ = $(SRC:applications/src/%.c=build/%.o)
TARGET = build/gateway

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build
	$(CC) $(OBJ) $(LDFLAGS) -o $@

build/%.o: applications/src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: all clean
