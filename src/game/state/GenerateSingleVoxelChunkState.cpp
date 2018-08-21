//
// Created by Miro on 18-Aug-18.
//

#include "GenerateSingleVoxelChunkState.h"

GenerateSingleVoxelChunkState::GenerateSingleVoxelChunkState()
        : GameState("generate-single-voxel-chunk-state"), camera(std::unique_ptr<Camera>(new Camera())) {

    VoxelGenerator generator = VoxelGenerator(1337);

    glm::ivec3 position = {0, 0, 0};
    glm::ivec3 size = {8, 8, 8};

    chunk = std::make_shared<VoxelChunk>(generator, position, size);

    for ( auto &voxel : chunk->getVoxels() ) {
        printf("%f \n", voxel.getValue());
    }
}

void GenerateSingleVoxelChunkState::processInputs(GLFWwindow *window) {
    // Process keyboard input
    camera->process_key_input(window);

    // Process cursor movement input
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    camera->process_mouse_input(window, x, y);
}

bool GenerateSingleVoxelChunkState::update() {
    return false;
}

void GenerateSingleVoxelChunkState::render(GLFWwindow *window) {

}
