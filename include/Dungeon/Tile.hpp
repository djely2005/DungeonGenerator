#pragma once
#include "Ui.hpp"
#include "TileType.hpp"
class Player;

class Dungeon;

class Tile : public Ui
{
public:
    bool visited = false;
    TileType type;

public:
    virtual ~Tile() {};
    virtual bool effectOnPlayer(Player *) = 0;

protected:
    virtual char render(Coord *) = 0;
    friend class Dungeon;
};