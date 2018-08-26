//
// Created by Miro on 18-Aug-18.
//

#include "GenerateSingleVoxelChunkState.h"

GenerateSingleVoxelChunkState::GenerateSingleVoxelChunkState()
        : GameState("generate-single-voxel-chunk-state"),
          program(ShaderProgram::fromFiles("res/shader/simple.vert", "res/shader/simple.frag")),
          camera(new Camera()),
          mesh(new Mesh()) {

    VoxelGenerator generator = VoxelGenerator(1337);

    glm::ivec3 position = {0, 0, 0};
    glm::ivec3 size = {64, 64, 64};

    chunk = std::make_shared<VoxelChunk>(generator, position, size);

    mesh = marchingCubes.generateMesh(*chunk);

    program.link();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glCullFace(GL_FRONT);
}

void GenerateSingleVoxelChunkState::processInputs(GLFWwindow *window) {
    input.setWindow(window);

    // Process keyboard input
    camera->processKeyInput(input, glfwGetTime());

    // Process cursor movement input
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    camera->processMouseInput(x, y);
}

bool GenerateSingleVoxelChunkState::update() {
    return false;
}

void GenerateSingleVoxelChunkState::render(GLFWwindow *window) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 mvp = camera->getProjection() * camera->getView() * glm::mat4(1.0);
    program.setUniformMat4("MVP", mvp);

    program.use();

    mesh->render(Renderable::Mode::Triangles, program);
}
