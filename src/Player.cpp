#include "Dungeon/Player.hpp"
#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
#include "iostream"

void Player::removeHealth(int hp)
{
    health -= hp;
}

void Player::addToInventory(int inv)
{
    inventory += inv;
}

void Player::removeFromInventory(int inv)
{
    inventory -= inv;
}

void Player::moveTo(Coord newPosition)
{
    position = newPosition;
}

void Player::move(Direction direction)
{
    Dungeon& dungeon = Dungeon::getInstance();
    Coord future_coord = position;
    switch (direction)
    {
    case Direction::Top:
        future_coord.y--;
        break;
    case Direction::Bottom:
        future_coord.y++;
        break;
    case Direction::Left:
        future_coord.x--;
        break;
    case Direction::Right:
        future_coord.x++;
        break;
    default:
        break;
    }

    Tile *tile = dungeon.getTile(future_coord);
    if (this->useEffect(tile)) 
    {
        this->moveTo(future_coord);
        
    }
}

bool Player::useEffect(Tile *tile)
{
    return tile->effectOnPlayer(this);
}

void Player::displayStatus() const {
    Dungeon& d = Dungeon::getInstance();
    std::vector<Coord> path = d.findPath(position, d.getEndCell());
    int rest = path.size() - 1;

    std::cout << "\nPosition               : (" << position.x << ", " << position.y << ")\n";
    std::cout << "Health Points          : " << health << "/100\n";
    std::cout << "Inventory              : " << inventory << " treasures\n";
    std::cout << "Distance to Exit       : " << rest << " steps\n";
}
