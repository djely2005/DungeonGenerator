#pragma once
#include <vector>
#include <random>
#include <span>
#include "Ui.hpp"
#include "Coord.hpp"

class Tile;

class Dungeon
{
private:
    std::vector<std::vector<Tile *>> grid;
    size_t height;
    size_t width;
    size_t padding;
    static Dungeon *instance;

private:
    Dungeon() = default;
    Dungeon(size_t, size_t);

public:
    size_t getHeight() const { return height; }
    size_t getWidth() const { return width; }
    size_t getPadding() const { return padding; }

    void setPadding(size_t p) { padding = p; }

public:
    Dungeon(const Dungeon &) = delete;
    Dungeon &operator=(const Dungeon &) = delete;

    Tile *getTile(Coord &);
    void generate();
    void render();
    void findPath();
    void addLimits();
    void addPadding();
    static Dungeon *getInstance(size_t height = 5, size_t width = 5)
    {
        if (instance == nullptr)
            instance = new Dungeon(height, width);
        return instance;
    }
};