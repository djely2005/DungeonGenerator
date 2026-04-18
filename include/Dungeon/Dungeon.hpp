#pragma once
#include <vector>
#include "Tile.hpp"
#include "Ui.hpp"
#include "Coord.hpp"

class Dungeon : public Ui
{
private:
    std::vector<Tile*> grid;
    size_t size;
    static Dungeon* instance;

private:
    Dungeon() = default;
    Dungeon(size_t);

public:
    Dungeon(const Dungeon &) = delete;
    Dungeon &operator=(const Dungeon &) = delete;

    Tile* getTile(Coord);
    void generate();
    void render(char) override;
    void findPath();
    static Dungeon* getInstance(size_t size = 5 * 5)
    {
        if (instance == nullptr)
            instance = new Dungeon(size);
        return instance;
    }
};