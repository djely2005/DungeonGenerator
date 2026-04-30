#include "Dungeon/End.hpp"
#include "iostream"

char DungeonRoad::End::render(Coord *)
{
    return 'E';
}


bool DungeonRoad::End::effectOnPlayer(Player* player){
    if(player->isAlive())
    {
        std::cout << "Congratulations! You've reached the end of the dungeon!" << std::endl;
    }
    return true;
}