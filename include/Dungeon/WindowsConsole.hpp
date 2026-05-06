#include "Console.hpp"
#include <conio.h>
#include <windows.h>

class WindowsConsole : public Console {
public:
    void clear() override {
        system("cls");
    }

    char getKeyDown() override {
        return _getch();
    }
};