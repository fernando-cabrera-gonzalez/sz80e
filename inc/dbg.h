
#ifndef DBG_H
#define DBG_H

#include <stdbool.h>
#include <stdint.h>

#define MAX_BREAK_POINT_LIST_LENGTH 16
#define NUM_COMMANDS 7

typedef struct {
    char *name;
    char *description;
    bool (*functionPtr)();
} Command;

extern bool dbg_requested;
extern uint16_t brList[16];
extern int8_t numSteps;

void dbg_readCommand();
bool dbg_listCommands();

bool dbg_listBreakPoints();
bool dbg_addBreakPoint();
bool dbg_hasBreakPoint(const uint16_t address);
bool dbg_removeBreakPoint();

bool dbg_showZ80State();
bool dbg_run();
bool dbg_ml();

bool dbg_exit();

#endif