#pragma once
#include "Ui.hpp"
#include "Coord.hpp"
#include "Direction.hpp"

class Tile;

class Player : public Ui
{
private:
    Coord position;
    int health;
    int inventory;

public:
    Coord getPosition() const { return position; }
    int getHealth() const { return health; }
    void setHealth(int hp) { health = hp; }
    int getInventory() const { return inventory; }
    void setInventory(int inv) { inventory = inv; }

public:
    void removeHealth(int);
    void addToInventory(int);
    void removeFromInventory(int);
    void moveTo(Coord);
    void move(Direction);
    bool isAlive() const { return health > 0; };
    void displayStats() const;

private:
    bool useEffect(Tile *);

public:
    void setPosition(Coord c) { position = c; }
    char render(Coord *) override { return '@'; }
};