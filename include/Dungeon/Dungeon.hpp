#pragma once
#include <vector>
#include <random>
#include <span>
#include <memory>
#include "Ui.hpp"
#include "Coord.hpp"
#include "Direction.hpp"
#include "TileLocationType.hpp"
#include "TileType.hpp"

class Tile;
class Player;

class Dungeon
{
private:
    std::vector<std::vector<std::unique_ptr<Tile>>> grid; 
    size_t row;
    size_t column;
    size_t padding;
    float monsterSpawnChances = 0.1f;
    float treasureDeadendSpawnChances = 0.9f;
    float treasureTurnSpawnChances = 0.6f;
    float trapSpawnChances = 0.1f;
    long unsigned int seed = 10;
    std::mt19937 gen{seed};
    static std::unique_ptr<Dungeon> instance;

private:
    Dungeon() = default;
    Dungeon(size_t, size_t);

public:
    size_t getCol() const { return column; }
    size_t getRow() const { return row; }
    size_t getPadding() const { return padding; }

    void setPadding(size_t p) { padding = p; }

public:
    Dungeon(const Dungeon &) = delete;
    virtual ~Dungeon() {};
    Dungeon &operator=(const Dungeon &) = delete;

    Tile *getTile(const Coord &);
    Coord applyDirection(const Coord &, Direction &);
    bool checkRowBoundaries(int);
    bool checkColumnBoundaries(int);
    TileLocationType getTileLocationType(const Coord &);
    Coord getStartingCell();
    
    Coord getSpawnPoint();
    Coord getEndCell(); 

    void replaceCase(const Coord &, TileType tileType);
    void replaceCase(const std::vector<Coord> &, TileType tileType);
    void generate(Coord &);
    void generate();
    void saveAsTextFile();
    
    void render(Player* player = nullptr);
    
    std::vector<Coord> findPath(Coord start, Coord end); 
    std::vector<Coord> reconstructPath(const std::vector<std::vector<Coord>>& parent, Coord start, Coord end);
    void displayBFS(const std::vector<Coord>& path, Player* player = nullptr);
    
    void addLimits();
    void populate();
    static Dungeon &getInstance(size_t height = 5, size_t width = 5)
    {
        if (instance == nullptr)
            instance = std::unique_ptr<Dungeon>(new Dungeon(height, width));
        return *instance;
    }
};