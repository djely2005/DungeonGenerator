#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Direction.hpp"
#include "iostream"
#include "Dungeon/Console.hpp"

void gameLoop(Dungeon& d, Player& p) {
    Console& console = Console::getInstance();
    char input;

    while (p.isAlive() && !p.isGameFinished()) {
        system("cls"); 
        d.render(&p);
        p.displayStatus();

        std::cout << "\nTo move use (Z/Q/S/D) or 'M' to quit :\n" << std::endl;
        input = console.getKeyDown();
        switch (tolower(input)) {
            case 'z': p.move(Direction::Top); break;
            case 's': p.move(Direction::Bottom); break;
            case 'q': p.move(Direction::Left); break;
            case 'd': p.move(Direction::Right); break;
            case 'm': p.finishGame(); break;
            case 'p': {
                std::vector<Coord> path = d.findPath(p.getPosition(), d.getEndCell());
                system("cls");
                d.displayBFS(path, &p);
                p.displayStatus();
                std::cout << "\nPress any key to continue...\n" << std::endl;
                console.getKeyDown();;
                break;
            }
        }

    }

    if (!p.isAlive()) 
    {
        std::cout << "\nGAME OVER... You are dead in the dungeon.\n" << std::endl;
        std::cout << "\nPress any key to continue...\n" << std::endl;
        console.getKeyDown();
        p.finishGame();
    }
}

int main(){
    Dungeon& d = Dungeon::getInstance(21, 41);
    d.generate();
    d.populate();
    d.saveAsTextFile();
    Player player;
    player.setPosition(d.getSpawnPoint());
    gameLoop(d, player);
    return 0;
}