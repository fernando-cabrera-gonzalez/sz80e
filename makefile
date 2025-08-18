CC 		= gcc
CFLAGS 	= -g -I./inc -Wall -Werror
SOURCES = $(wildcard ./src/*.c)
OBJDIR = obj
OBJECTS = $(patsubst ./src/%.c,$(OBJDIR)/%.o,$(SOURCES))

z80emu: ./src/main.c $(SOURCES)
	$(CC) $^ $(CFLAGS) -o $@

$(OBJDIR)/%.o: ./src/%.c
	@mkdir -p $(OBJDIR)
	$(CC) -c $< $(CFLAGS) -o $@

libz80emu.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)

z80emu_test: libz80emu.a
	$(CC) ./src/main.c ./src/mem_test.c -o $@ $(CFLAGS) -L. -lz80emu