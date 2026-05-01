#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
#include "Dungeon/Player.hpp"
#include "iostream"
// with Windows use <conio.h> for the function _getch() to read keyboard input
// withLinux/Mac use <termios.h> 
#include <conio.h>

void gameLoop(Dungeon& d, Player& p) {
    char input;
    bool playing = true;

    while (p.isAlive() && playing) {
        system("cls"); 
        d.render(&p);
        p.displayStatus();

        if (d.getTile(p.getPosition())->type == TileType::End)
        {
            d.getTile(p.getPosition())->effectOnPlayer(&p);
            std::cout << "\n You've reached the end of the dungeon! Congratulations!\n";
            playing = false;
        } 

        std::cout << "\nTo move use (Z/Q/S/D) or 'M' to quit : ";
        input = _getch(); 
        switch (tolower(input)) {
            case 'z': p.move(Direction::Top); break;
            case 's': p.move(Direction::Bottom); break;
            case 'q': p.move(Direction::Left); break;
            case 'd': p.move(Direction::Right); break;
            case 'm': playing = false; break;
        }

    }

    if (!p.isAlive()) 
    {
        std::cout << "\nGAME OVER... You are dead in the dungeon.\n";
        playing = false;
    }
}

int main(){
    Dungeon& d = Dungeon::getInstance(21, 41);
    d.generate();
    d.populate();
    Player player;
    player.setPosition(d.getSpawnPoint());
    gameLoop(d, player);
    return 0;
}