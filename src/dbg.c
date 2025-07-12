#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dbg.h"
#include "z80.h"

Command commands[NUM_COMMANDS] = {
    {"help", "List avalilable commands.", &dbg_listCommands},
    {"br+", "Adds a breakpoint at the specified address.", &dbg_addBreakPoint},
    {"br-", "Removes breakpoint at the specified address.", &dbg_removeBreakPoint},
    {"brl", "List breakpoints.", &dbg_listBreakPoints},
    {"z80", "Show z80 state.", &dbg_showZ80State},
    {"run", "Run N z80 instructions (resume if no num_steps).", &dbg_run},
    {"ml", "Lists contents of memory at specified address.", &dbg_ml}
};

bool dbg_requested = false;
char input[256], command[8];
bool keepReading;

uint16_t brList[16] = {[0 ... 15] = 0};
uint8_t brListLength = 0;
int8_t numSteps = -1;

void dbg_readCommand() {
    dbg_showZ80State();

    keepReading = true;
    do {
        printf("> ");
        fgets(input, 256, stdin);   
        size_t length = strlen(input);
        if (length > 0 && input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }
        
        char *command = strtok(input, " ");
        bool commandFound = false;
        for (int i = 0; i < NUM_COMMANDS; i++) {
            if (!strcmp(commands[i].name, command)) {
                commands[i].functionPtr();
                commandFound = true;
                break;
            }
        }
        if (!commandFound) {
            printf("Command not valid.\n");
        }
    } while (keepReading);
}

bool dbg_listCommands() {
    for (int i = 0; i < NUM_COMMANDS; i++) {
        printf("\t%-15s  %s\n", commands[i].name, commands[i].description);
    }

    return 1;
}

bool dbg_listBreakPoints() {
    for (int i = 0; i < MAX_BREAK_POINT_LIST_LENGTH; i++) {
        if (brList[i]) {
            printf("\t%d: 0x%04x\n", i, brList[i]);
        }
    }

    return 1;
}

bool dbg_addBreakPoint() {
    uint16_t address;
    char *token = strtok(NULL, " ");
    if (token != NULL) {
        address = strtoul(token, NULL, 16);
        if (brListLength < MAX_BREAK_POINT_LIST_LENGTH) {
            for (int i = 0; i < MAX_BREAK_POINT_LIST_LENGTH; i++) {
                if (!brList[i]) {
                    brList[i] = address;
                    brListLength++;
                    printf("Added breakpoint for address 0x%04x at index %d\n", address, i);
                    return true;
                } else if (brList[i] == address) {
                    printf("Breakpoint for address 0x%04x already exists at index %d\n", address, i);
                    return true;
                }
            }
        } else {
            printf("Max number of breakpoints (%d) reached.\n", MAX_BREAK_POINT_LIST_LENGTH);
        }
    } else {
        printf("No address specified.\n");
    }

    return false;
}

bool dbg_hasBreakPoint(const uint16_t address) {
    for (int i = 0; i < MAX_BREAK_POINT_LIST_LENGTH; i++) {
        if (brList[i] != 0 && brList[i] == address) {
            return true;
        }
    }

    return false;
}

bool dbg_removeBreakPoint() {
    uint16_t address;
    char *token = strtok(NULL, " ");
    if (token != NULL) {
        address = strtoul(token, NULL, 16);
        for (int i = 0; i < MAX_BREAK_POINT_LIST_LENGTH; i++) {
            if (brList[i] == address) {
                brList[i] = 0;
                brListLength--;
                printf("Removed breakpoint for address 0x%04x at index %d\n", address, i);
                return true;
            }
        }
    } else {
        printf("No address specified.\n");
    }

    return false;
}

bool dbg_showZ80State() {
    z80_printState();
    Opcode* opcodePtr = z80_fetchAndDecode();
    z80_printOpcode(opcodePtr, z80.pc, 0);
    
    return 1;
}

bool dbg_run() {
    char *token = strtok(NULL, " ");
    if (token != NULL) {
        numSteps = strtoul(token, NULL, 10);
    } else {
        numSteps = -1;
    }
    keepReading = false;

    return 1;
}

bool dbg_ml() {
    uint16_t address;
    char *token = strtok(NULL, " ");
    if (token != NULL) {
        address = strtoul(token, NULL, 16);
        for (uint8_t i = 0; i < 4; i++) {
            printf("0x%04x:\t", address + (i * 16));
            for (uint8_t j = 0; j < 16; j++) {
                printf("0x%02x\t", memReadFunc(address + (i * 16) + j));
            }
            puts("");
        }
        return true;
    } else {
        printf("No address specified.\n");
    }

    return false;
}