#pragma once
#include "Ui.hpp"
#include "Coord.hpp"
#include "Direction.hpp"
class Player : public Ui
{
private:
    Coord position;
    int health;
    int inventory;

public:
    Coord getPosition() const { return position; }
    int getHealth() const { return health; }
    int getInventory() const { return inventory; }

public:
    void move(Direction);
    void removeHealth(int);
    void addToInventory(int);
};