#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
int main(){
    Dungeon& d = Dungeon::getInstance(21, 41);
    d.generate();
    d.render();
    d.populate();
    d.render();
    return 0;
}