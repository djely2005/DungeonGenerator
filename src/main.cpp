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

        std::cout << "\nDeplacement (Z/Q/S/D) ou 'M' pour quitter : ";
        input = _getch(); 
        switch (tolower(input)) {
            case 'z': p.move(Direction::Top); break;
            case 's': p.move(Direction::Bottom); break;
            case 'q': p.move(Direction::Left); break;
            case 'd': p.move(Direction::Right); break;
            case 'm': playing = false; break;
        }

    }

    if (!p.isAlive()) {
        std::cout << "\nGAME OVER... Vous etes mort dans le donjon.\n";
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