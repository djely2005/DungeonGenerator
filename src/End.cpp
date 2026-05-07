#include "Dungeon/End.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Coord.hpp"
#include "iostream"
#include "Dungeon/Console.hpp"


char DungeonRoad::End::render(Coord *coord)
{
    return 'E';
}


void DungeonRoad::End::effectOnPlayer(Player* player, Coord& coord){
    Console& console = Console::getInstance();
    player->moveTo(coord);
    player->finishGame();
    std::cout << "\n Congratulations... You've reached the end of the dungeon !\n" << std::endl;
    std::cout << "\nPress any key to continue...\n" << std::endl;
    console.getKeyDown();
}