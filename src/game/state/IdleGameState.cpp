#include "IdleGameState.h"

IdleGameState::IdleGameState()
        : GameState("idle-game-state"), program(ShaderProgram::fromFiles("res/shader/simple.vert", "res/shader/simple.frag")) {

    IdleGameState::mesh = std::unique_ptr<Mesh>(new Mesh(
            {
                    Vertex({0.5, 0.5, 0.5}),
                    Vertex({1.0, 2.0, 1.0}),
                    Vertex({1.5, 1.5, 3.5})
            },
            {
                    1, 2, 3
            }
    ));

    program.link();
}

void IdleGameState::processInputs(GLFWwindow *window) {

}

bool IdleGameState::update() {
    return true;
}

void IdleGameState::render(GLFWwindow *window) {
    program.use();
    mesh->render(program);
}
