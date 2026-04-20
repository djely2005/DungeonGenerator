#pragma once
#include <vector>
#include <span>
#include "Ui.hpp"
#include "Coord.hpp"

class Tile;

class Dungeon : public Ui
{
private:
    std::vector<Tile*> grid;
    size_t height;
    size_t width;
    static Dungeon* instance;

private:
    Dungeon() = default;
    Dungeon(size_t, size_t);

public:
    Dungeon(const Dungeon &) = delete;
    Dungeon &operator=(const Dungeon &) = delete;

    Tile* getTile(Coord);
    void generate();
    char render() override;
    void findPath();
    std::span<Tile*> operator[](int);
    static Dungeon* getInstance(size_t height = 5, size_t width = 5)
    {
        if (instance == nullptr)
            instance = new Dungeon(height, width);
        return instance;
    }
};