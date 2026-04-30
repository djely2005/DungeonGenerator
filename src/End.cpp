#include "Dungeon/End.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Coord.hpp"
#include "iostream"

char DungeonRoad::End::render(Coord *coord)
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