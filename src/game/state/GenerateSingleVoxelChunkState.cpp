//
// Created by Miro on 18-Aug-18.
//

#include "GenerateSingleVoxelChunkState.h"

GenerateSingleVoxelChunkState::GenerateSingleVoxelChunkState()
        : GameState("generate-single-voxel-chunk-state"),
          program(ShaderProgram::fromFiles("res/shader/simple.vert", "res/shader/simple.frag")),
          camera(new Camera()) {

    VoxelGenerator generator = VoxelGenerator(1337);

    glm::ivec3 position = {0, 0, 0};
    glm::ivec3 size = {64, 64, 64};

    chunk = std::make_shared<VoxelChunk>(generator, position, size);

    double timeBefore = glfwGetTime();

    renderer = VoxelChunkRenderer(chunk);

    double timeAfter = glfwGetTime();

    printf("Elapsed Time for Marching Cubes: %.3fs", timeAfter - timeBefore);

    program.link();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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
    renderer.render(*camera, program);
}
