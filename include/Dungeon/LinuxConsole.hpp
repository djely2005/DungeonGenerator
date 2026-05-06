#include "Console.hpp"
#include <termios.h>
#include <unistd.h>
#include <iostream>

class LinuxConsole : public Console {
public:
    void clear() override {
        std::cout << "\033[2J\033[1;1H"; // ANSI escape code: clear and move cursor to (1,1)
    }

    char getKeyDown() override {
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
};