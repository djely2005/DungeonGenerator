#pragma once
#include "Ui.hpp"

class Player;

class Dungeon;

class Tile : public Ui
{
public:
    virtual ~Tile() {};
    virtual bool effectOnPlayer(Player *) = 0;

protected:
    virtual char render(Coord *) = 0;
    friend class Dungeon;
};