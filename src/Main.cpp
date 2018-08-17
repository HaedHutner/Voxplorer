#include <iostream>

#include <game/Voxplorer.h>

int main() {
    Voxplorer voxplorer = Voxplorer();
    if ( voxplorer.init() ) voxplorer.run();
    return 1;
}