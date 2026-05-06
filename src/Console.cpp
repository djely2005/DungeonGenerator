#ifdef _WIN32
    #include "Dungeon/WindowsConsole.hpp"
#else
    #include "Dungeon/LinuxConsole.hpp"
#endif

Console& Console::getInstance() {
    static std::unique_ptr<Console> instance = nullptr;
    if (!instance) {
        #ifdef _WIN32
                instance = std::make_unique<WindowsConsole>();
        #else
                instance = std::make_unique<LinuxConsole>();
        #endif
    }
    return *instance;
}