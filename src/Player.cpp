#include "Dungeon/Player.hpp"
#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"

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
        future_coord.y++;
        break;
    case Direction::Bottom:
        future_coord.y--;
        break;
    case Direction::Left:
        future_coord.x++;
        break;
    case Direction::Right:
        future_coord.x--;
        break;
    default:
        break;
    }

    Tile *tile = dungeon.getTile(future_coord);
    if (tile->type != TileType::Wall) 
    {
        this->moveTo(future_coord);
        this->useEffect(tile);
    }
}

bool Player::useEffect(Tile *tile)
{
    return tile->effectOnPlayer(this);
}