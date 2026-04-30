#include "Dungeon/Trap.hpp"
#include "iostream"

char DungeonRoad::Trap::render(Coord *)
{
    return 'T';
}


bool DungeonRoad::Trap::effectOnPlayer(Player* player){
    if(player->isAlive())
    {
        player->removeHealth(10);
        std::cout << "You stepped on a trap! Your health is now " << player->getHealth() << "." << std::endl;
    }
    return true;
}