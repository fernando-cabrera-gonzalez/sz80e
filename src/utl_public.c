/*
 * utl_public.c - Cross-Platform Input Utilities
 *
 * This file provides cross-platform keyboard input functions for the emulator.
 * It handles both Windows and POSIX systems, allowing non-blocking key checks
 * and input polling for interactive emulation.
 */

 #ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

#include "z80_public.h"

#define INPUT_POLL_COUNTDOWN 10000
int input_poll_countdown = INPUT_POLL_COUNTDOWN;

int key_pressed() {
#ifdef _WIN32
    return kbhit();
#else
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
#endif
}

int get_key() {
#ifdef _WIN32
    return getch();
#else
    return getchar();
#endif
}

int utl_check_keyboard() {
    if (--input_poll_countdown == 0) {
        input_poll_countdown = INPUT_POLL_COUNTDOWN;
        if (key_pressed()) {
            int key = get_key();
            #if DEBUG_LEVEL == DEBUG_LEVEL_USER
            if (key == 'd' || key == 'D') {
                z80_debug();
            }
            #endif
            
            return key;
        }
    }

    return -1;
}