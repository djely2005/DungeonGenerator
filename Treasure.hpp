#include "Tile.hpp"
#include "Ui.hpp"

class Treasure : public Ui, public Tile
{
private:
    int value; 
public:
    void render(char);
};