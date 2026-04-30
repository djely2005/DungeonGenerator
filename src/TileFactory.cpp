#include "Dungeon/TileFactory.hpp"
#include "Dungeon/Wall.hpp"
#include "Dungeon/Treasure.hpp"
#include "Dungeon/Trap.hpp"
#include "Dungeon/Path.hpp"
#include "Dungeon/Monster.hpp"
#include "Dungeon/Limit.hpp"
#include "Dungeon/End.hpp"

Tile* TileFactory::create(TileType tileType)
{
    Tile *result;
    switch (tileType)
    {
    case TileType::Wall:
        result = new DungeonRoad::Wall();
        break;
    case TileType::Treasure:
        result = new DungeonRoad::Treasure();
        break;
    case TileType::Trap:
        result = new DungeonRoad::Trap();
        break;
    case TileType::Path:
        result = new DungeonRoad::Path();
        break;
    case TileType::Monster:
        result = new DungeonRoad::Monster();
        break;
    case TileType::Limit:
        result = new DungeonRoad::Limit();
        break;
    case TileType::End:
        result = new DungeonRoad::End();
        break;

    default:
        result = new DungeonRoad::Path();
        break;
    }
    result->type = tileType;
    return result;
}