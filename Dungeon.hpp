#pragma once
#include <vector>
#include "Tile.hpp"
#include "Ui.hpp"

class Dungeon
{
private:
    std::vector<std::vector<Tile *>> grid;
    static Dungeon *instance;

private:
    Dungeon() = default;
    Dungeon(int);

public:
    void generate(int, int);
    void render();
    void findPath();
    static Dungeon *getInstance(int size = 5)
    {
        if (instance == nullptr)
            instance = new Dungeon(size);
        return instance;
    }
};