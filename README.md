
# Simple Z80 Emulator (sz80e)

This project implements an emulator for the Zilog Z80 microprocessor, written in C. The goal is to provide an educational and functional base to understand the internal workings of this classic processor, as well as to serve as a starting point for developments related to embedded systems, retrocomputing, or emulation.

## Features

- Emulation of the documented [Z80 instruction set](https://clrhome.org/table/).
- Runs as a standalone program or linked as a static library.
- Modular and easy-to-understand structure.
- Includes tests and debugging utilities.
- Compatible with binaries and [.Z80](https://worldofspectrum.org/faq/reference/z80format.htm) / [.SNA](https://worldofspectrum.org/faq/reference/formats.htm) snapshots.
- Passes all ZEXDOC tests (see https://github.com/agn453/ZEXALL), which are included.
- Visual Studio Code tasks provided for building and debugging.

## Project Structure

- `src/`: Source code of the emulator.
- `inc/`: Header files.
- `bin/`: Binaries (ROM and test files).
- `makefile`: Alternative build script.
- `README.md`: This file.

## Requirements

- GCC for compiling.
- LD for linking.
- AR for building the static library (optional).
- Compatible operating system (Windows or Linux).
- Recommended: GNU make and Visual Studio Code with C/C++ extension by Microsoft.

## Standalone

Build the Z80 core + test as a standalone program:
- run VS Code task "Build z80 emulator" or
- run "make z80emu" or
- run:

```sh
gcc -g ./src/main.c ./src/dbg.c ./src/mem_test.c ./src/opcodes.c ./src/opcodes_bit.c ./src/opcodes_ext.c ./src/opcodes_ix.c ./src/opcodes_iy.c ./src/opcodes_main.c ./src/utl.c ./src/z80.c -I./inc -o ./z80emu
```

- You can run the emulator with the following commands.<br>If no argument is given, only the ROM will be loaded (use ./bin/zexdoc.com for running the ZEXDOC test suite):

```sh
z80emu.exe [binary / .z80 / .sna file]    (Windows)
z80emu     [binary / .z80 / .sna file]    (Linux)
```
## Static library + TEST

Build the Z80 core as a static library that can be linked from external programs (see TEST):
- run VS Code task "Build z80emu static library" or
- run "make libz80emu.a" or
- run:

```sh
gcc -c ./src/dbg.c ./src/opcodes.c ./src/opcodes_bit.c ./src/opcodes_ext.c ./src/opcodes_ix.c ./src/opcodes_iy.c ./src/opcodes_main.c ./src/utl.c ./src/z80.c -I./inc
ar rcs libz80emu.a dbg.o opcodes.o opcodes_bit.o opcodes_ext.o opcodes_ix.o opcodes_iy.o opcodes_main.o utl.o z80.o
```

Build the Z80 static library test:
- run VS Code task "Build z80emu library test executable" or
- run "make z80emu_test" or
- run:

```sh
gcc ./src/main.c ./src/mem_test.c -I./inc -L. -lz80emu -o ./z80emu_test 
```

- You can run the static library test with the following commands.<br>If no argument is given, only the ROM will be loaded (use ./bin/zexdoc.com for running the ZEXDOC test suite):

```sh
z80emu_test.exe [binary / .z80 / .sna file]    (Windows)
z80emu_test     [binary / .z80 / .sna file]    (Linux)
```
## How to add the Z80 core to your projects

If you want to use the Z80 core in your personal projects follow these steps:
1) Build the static library.

2) Add to your project both the library and the public header file 'z80_public.h' (for access to the main emulator features).

3) You will need to implement a memory model for the Z80 to work (see mem_test.h, mem_test.c and main.c for an example):
    - Provide a 64k memory buffer (16k ROM + 48k RAM).
    - Implement the methods of the memory interface, provided in the 'MEM INTERFACE' section of 'z80_public.h'.

4) From your project you will need to call the 2 functions in the 'Z80 INTERFACE' section of 'z80_public.h':
    - Call z80_init() at the beginning for initializing the z80 emulator providing:
        - A file to load in memory in one of these formats and that can be provided in the first argument of command line:
            - A binary that will be loaded at address 0x000 of the memory.
            - A .z80 or a .sna file with a snapshot that will be loaded at address 0x4000 or higher, keeping the ROM at address from 0x000 to 0x3FFF.
            - If no file is provided, only the ROM will be loaded at address 0x000.
        - A pointer to a Z80InitData struct (see 'z80_public.h') with:
            - A pointer to the memory buffer you defined.
            - Pointers to the read and write memory functions you implemented.
        - Optionally, you can provide:
            - Pointers for I/O read and write functions (see 'I/O INTERFACE' in 'z80_public.h')
            - Pointer to a render function that will be called every time an interrupt is triggered.
            - A start address, that will be used as the initial value for the PC.
    - Call the z80_update() function every time you want to update the emulator state. It will return the number of cycles elapsed.
      Optionally, if memory contention is present, you can add the additional number of contended cycles to the total, as in the example.

## Debugger

At any point during execution, you can press ESC to invoke the debugger. Once inside, the following commands are available:
```text
help             List avalilable commands.
br+ <address>    Add a breakpoint at the specified address.
br- <address>    Remove breakpoint at the specified address.
brl              List breakpoints.
z80              Show z80 state.
run [num_steps]  Run N z80 instructions (resume if no num_steps).
ml  <address>    List contents of memory at specified address.
```
## Author

Fernando Cabrera González
- LinkedIn: [Fernando Cabrera González](https://www.linkedin.com/in/fernando-cabrera-gonzález-3b256620)
- X: [@fcabrera_77](https://x.com/fcabrera_77)
- CommodoreSpain: [El Rincón de Fer](https://www.commodorespain.es/el-rincon-de-fer/)
- Series on the AmigaWave YouTube channel:
    - [How were games made on the Amiga?](https://youtube.com/playlist?list=PLJGQC1clVHNFnwfmWUz3W2uoJgx0Pj6u2&si=RM6vIbvmaD15IcuX)
    - [Basic Assembly Programming Course for the Amiga.](https://youtube.com/playlist?list=PLJGQC1clVHNH7jb3hanudeT_BnQs2Ilv0&si=VeIlJY8tVfef84P_)
