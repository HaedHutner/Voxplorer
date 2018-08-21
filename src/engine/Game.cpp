#include "Game.h"

const std::shared_ptr<GameState> &Game::getState() const {
    return state;
}

void Game::setState(const std::shared_ptr<GameState> &state) {
    Game::state = state;
}

GLFWwindow *Game::getWindow() const {
    return window;
}
