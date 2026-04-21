#pragma once
#include "Coord.hpp"

class Ui
{
protected:
    virtual char render(Coord *) = 0;
};