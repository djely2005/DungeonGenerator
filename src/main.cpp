#include "Dungeon/Dungeon.hpp"

int main(){
    auto d = Dungeon::getInstance(20, 20);
    d->generate();
    return 0;
}