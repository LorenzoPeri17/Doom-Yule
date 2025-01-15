CC=gcc
CFLAGS= -O3 -I./src -Wall -Wextra
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
DEPS=$(wildcard src/*.h)
TARGET=bin/doom-yule
PREFIX?=/usr/local

.PHONY: all neat clean install

all: bin $(TARGET) neat

bin:
	mkdir -p bin

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

install:
	install -m 755 $(TARGET) $(PREFIX)/bin/

neat:
	rm -f $(OBJ)

clean: neat
	rm -f $(TARGET)
	rmdir bin 2>/dev/null || true


