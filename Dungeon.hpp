#pragma once
#include <vector>
#include "Tile.hpp"
#include "Ui.hpp"

class Dungeon{
private:
    std::vector<std::vector<Tile*>> grid;
    static Dungeon* instance;
private:
    Dungeon(){}
public:
    void generate(int, int);
    void render();
    void findPath();
    static Dungeon* getInstance(){
        if(instance == nullptr)
            instance = new Dungeon();
        return instance;
    }
};