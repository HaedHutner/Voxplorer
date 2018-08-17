#include "Voxplorer.h"
#include <memory>

bool Voxplorer::init() {
    setState(std::make_shared<IdleGameState>());
    return Game::init();
}
