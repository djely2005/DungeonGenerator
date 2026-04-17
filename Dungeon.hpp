#pragma once
#include <vector>
#include "Tile.hpp"
#include "Ui.hpp"

class Dungeon{
private:
    std::vector<std::vector<Tile*>> grid;
public:
    void generate(int, int);
    void render();
    void findPath();
};