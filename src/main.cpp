#include "Dungeon/Dungeon.hpp"

int main(){
    auto d = Dungeon::getInstance(21, 41);
    d->generate();
    d->render();
    d->populate();
    d->render();
    return 0;
}