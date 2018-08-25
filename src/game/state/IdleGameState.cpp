#include "IdleGameState.h"

IdleGameState::IdleGameState()
        : GameState("idle-game-state"),
          program(ShaderProgram::fromFiles("res/shader/simple.vert", "res/shader/simple.frag")),
          mesh(new Mesh()),
          camera(new Camera()) {

    mesh->setVertices({
                              {0.5, 0.5, 0.5, 1},
                              {1.0, 2.0, 1.0, 1},
                              {1.5, 1.5, 3.5, 1},
                              {4.5, 4.5, 4.5, 1}
                      });

    mesh->setIndices({
                             1, 2, 3,
                             3, 4, 1
                     });

    program.link();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void IdleGameState::processInputs(GLFWwindow *window) {
    input.setWindow(window);
    // Process keyboard input
    camera->processKeyInput(input, glfwGetTime());

    printf("Camera Location: %.2f, %.2f, %.2f\n", camera->getPosition().x, camera->getPosition().y,
           camera->getPosition().z);

    // Process cursor movement input
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    camera->processMouseInput(x, y);

    printf("Camera Pitch & Yaw: %.2f, %.2f\n", camera->getPitch(), camera->getYaw());
}

bool IdleGameState::update() {
    return true;
}

void IdleGameState::render(GLFWwindow *window) {
    glm::mat4 mvp = camera->getProjection() * camera->getView() * glm::mat4(1.0);
    program.setUniformMat4("MVP", mvp);

    program.use();

    mesh->render(Renderable::Mode::Triangles, program);
}
