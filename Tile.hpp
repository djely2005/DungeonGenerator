#pragma once
#include "Ui.hpp"

class Tile: public Ui{
protected:
    virtual void render(char) = 0;
    virtual ~Tile() = default;
};