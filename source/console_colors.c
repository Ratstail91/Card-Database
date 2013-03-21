#include "console_colors.h"

#if defined(_WIN32)

#include <windows.h>

void ccset(unsigned char color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#else //unknown platform

#pragma message("This module has not been implemented for this platform/compiler")

void ccset(unsigned char) {}; //dummy

#endif //platform
