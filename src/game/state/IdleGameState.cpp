#include "IdleGameState.h"

IdleGameState::IdleGameState()
        : GameState("idle-game-state"),
          program(ShaderProgram::fromFiles("res/shader/simple.vert", "res/shader/simple.frag")) {

    IdleGameState::camera = std::unique_ptr<Camera>(new Camera());

    IdleGameState::mesh = std::unique_ptr<Mesh>(
            new Mesh(
                    {
                            Vertex({0.5, 0.5, 0.5}),
                            Vertex({1.0, 2.0, 1.0}),
                            Vertex({1.5, 1.5, 3.5})
                    },
                    {
                            1, 2, 3
                    }
            )
    );

    program.link();
}

void IdleGameState::processInputs(GLFWwindow *window) {
    // Process keyboard input
    camera->processKeyInput(window);

    printf("Camera Location: %.2f, %.2f, %.2f\n", camera->getPosition().x, camera->getPosition().y,
           camera->getPosition().z);

    // Process cursor movement input
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    camera->processMouseInput(window, x, y);

    printf("Camera Pitch & Yaw: %.2f, %.2f\n", camera->getPitch(), camera->getYaw());
}

bool IdleGameState::update() {
    return true;
}

void IdleGameState::render(GLFWwindow *window) {
    glm::mat4 mvp = camera->getProjection() * camera->getView() * glm::mat4(1.0);
    program.setUniformMat4("MVP", mvp);

    program.use();

    mesh->render(program);
}
