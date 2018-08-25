#include "Voxplorer.h"

Voxplorer::Voxplorer() {
    Voxplorer::name = "Voxplorer";
    Voxplorer::background = {0.2f, 0.4f, 0.2f};
}

bool Voxplorer::init() {
    bool gameInit = Game::init();

    Voxplorer::state = std::make_shared<IdleGameState>();

    return gameInit;
}
