#include "Tile.hpp"
#include "Ui.hpp"

class Monster : public Ui, public Tile
{
private:
    int pv; 
public:
    void render(char);
};