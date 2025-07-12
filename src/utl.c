#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

long utl_loadBinary(const char* fileName, uint8_t* dst) {
    FILE *f = fopen(fileName, "rb");
    long fileSize;

    if (f == NULL) {
        fprintf(stderr, "Error opening file %s from utl_loadBinary()\n", fileName);
        return 0;
    }

    fseek(f, 0, SEEK_END);
    fileSize = ftell(f);
    fseek(f, 0, SEEK_SET); 
    
    fread(dst, sizeof(uint8_t), fileSize, f);
    fclose(f);

    return fileSize;
}

long utl_saveBinary(const char* fileName, uint8_t* src) {
    FILE *f = fopen(fileName, "wb");

    if (f == NULL) {
        fprintf(stderr, "Error opening file %s from utl_saveBinary()\n", fileName);
        return 0;
    }

    size_t written = fwrite(src, sizeof(uint8_t), 0xFFFF, f);
    if (written != 0xFFFF) {
        perror("Error writing to file");
        fclose(f);
        return 0;
    }
    fclose(f);

    return 1;
}

// Función para comprobar si hay una tecla pulsada
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

// Función para leer la tecla pulsada
int get_key() {
#ifdef _WIN32
    return getch();
#else
    return getchar();
#endif
}

bool hasFileExtension(const char *fileName, const char *extension) {
    size_t fileLen = strlen(fileName);
    size_t extLen = strlen(extension);

    if (fileLen < extLen) return false;

    return strcmp(fileName + fileLen - extLen, extension) == 0;
}