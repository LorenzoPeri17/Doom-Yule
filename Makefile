CC=gcc
CFLAGS= -O3 -I./src -Wall -Wextra
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
DEPS=$(wildcard src/*.h)
TARGET=doom-yule

.PHONY: all neat clean

all: $(TARGET) neat

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

neat:
	rm -f $(OBJ)

clean: neat
	rm -f $(TARGET)


