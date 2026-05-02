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
            playing = false;
        } 
        else
        {
            std::cout << "\nTo move use (Z/Q/S/D) or 'M' to quit : " << std::endl;
            input = _getch(); 
            switch (tolower(input)) {
                case 'z': p.move(Direction::Top); break;
                case 's': p.move(Direction::Bottom); break;
                case 'q': p.move(Direction::Left); break;
                case 'd': p.move(Direction::Right); break;
                case 'm': playing = false; break;
                case 'p': {
                    std::vector<Coord> path = d.findPath(p.getPosition(), d.getEndCell());
                    system("cls");
                    d.displayBFS(path, &p);
                    p.displayStatus();
                    std::cout << "\nPress any key to continue..." << std::endl;
                    _getch();
                    break;
                }
            }
        }

    }

    if (!p.isAlive()) 
    {
        std::cout << "\nGAME OVER... You are dead in the dungeon.\n" << std::endl;
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