#include "Dungeon/Dungeon.hpp"

int main(){
    auto d = Dungeon::getInstance(5, 5);
    d->generate();
    return 0;
}