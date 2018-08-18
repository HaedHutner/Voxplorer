#include "IdleGameState.h"

IdleGameState::IdleGameState() : GameState("IdleGameState") {}

void IdleGameState::processInputs(GLFWwindow *window) {

}

bool IdleGameState::update() {
    return true;
}

void IdleGameState::render(GLFWwindow *window) {

}
