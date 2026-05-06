#include <memory>

class Console {
public:
    virtual ~Console() = default;
    virtual void clear() = 0;
    virtual char getKeyDown() = 0;

    // This is the global access point
    static Console& getInstance();
};