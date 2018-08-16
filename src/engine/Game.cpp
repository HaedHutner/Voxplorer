#include "Game.h"

const std::shared_ptr<GameState> &Game::getState() const {
    return state;
}
