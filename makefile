CC 		= gcc
CFLAGS 	= -g -I.\inc -Wall -Werror
SOURCES = $(wildcard ./src/*.c)

z80emu: ./src/main.c $(SOURCES)
	$(CC) $^ $(CFLAGS) -o $@

libz80emu.a: $(SOURCES)
	$(CC) -c $(SOURCES) $(CFLAGS)
	ar rcs $@ *.o

z80emu_test: libz80emu.a
	$(CC) ./src/main.c -o $@ $(CFLAGS) -L. -lz80emu