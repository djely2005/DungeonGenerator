#include "Dungeon/Treasure.hpp"
#include "iostream"

char DungeonRoad::Treasure::render(Coord *)
{
    return 'X';
}


bool DungeonRoad::Treasure::effectOnPlayer(Player* player){
    player->addToInventory(10);
    std::cout << "You found a treasure! Your inventory is now worth " << player->getInventory() << " points." << std::endl;
    return true;
}