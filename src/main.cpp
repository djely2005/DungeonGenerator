#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
#include "Dungeon/Player.hpp"

int main(){
    Dungeon& d = Dungeon::getInstance(21, 41);
    d.generate();
    d.populate();
    Player player;
    player.setPosition(d.getSpawnPoint());
    d.render(&player);
    return 0;
}