#pragma once
#include "Ui.hpp"

class Tile : public Ui
{
public:
    virtual ~Tile() {};

protected:
    virtual char render() = 0;
};