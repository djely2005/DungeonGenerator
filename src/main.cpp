#include "Dungeon/Dungeon.hpp"

int main(){
    auto d = Dungeon::getInstance(21, 41);
    d->generate();
    return 0;
}