#include "Tile.hpp"
#include "Ui.hpp"

class Trap : public Ui, public Tile
{
private:
    int degats; 
public:
    void render(char);
};