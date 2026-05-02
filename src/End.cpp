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
        std::cout << "\n Congratulations... You've reached the end of the dungeon !\n" << std::endl;
    }
    return true;
}