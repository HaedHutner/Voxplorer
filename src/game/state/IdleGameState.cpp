#include "IdleGameState.h"

IdleGameState::IdleGameState() : GameState("IdleGameState") {}

void IdleGameState::processInputs(const GLFWwindow &window) {

}

bool IdleGameState::update() {
    return true;
}

void IdleGameState::render(const GLFWwindow &window) {

}
