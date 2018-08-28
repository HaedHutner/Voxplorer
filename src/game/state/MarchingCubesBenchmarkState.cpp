//
// Created by miroslav.vasilev on 27.8.2018 г..
//

#include "MarchingCubesBenchmarkState.h"

MarchingCubesBenchmarkState::MarchingCubesBenchmarkState()
        : GameState("generate-single-voxel-chunk-state"),
          program(ShaderProgram::fromFiles("res/shader/simple.vert", "res/shader/simple.frag")),
          camera(new Camera()),
          mesh(new Mesh()) {

    VoxelGenerator generator = VoxelGenerator(1337, 3, .8f, 2.0f);

    glm::ivec3 position = {0, 0, 0};
    glm::ivec3 size = {64, 64, 64};

    chunk = std::make_shared<VoxelChunk>(generator, position, size);

    int BENCHMARK_ITERATIONS = 8;

    double averageTime = 0.0;
    for ( int i = 0; i < BENCHMARK_ITERATIONS; i++ ) {
        double timeBefore = glfwGetTime();

        mesh = marchingCubes.generateMesh(*chunk);

        double timeAfter = glfwGetTime();

        if ( averageTime == 0.0 ) averageTime = timeAfter - timeBefore;
        else averageTime = ((timeAfter - timeBefore) + averageTime)/2;
    }

    printf("Average Time for Marching Cubes, %d Iterations: %.3fs", BENCHMARK_ITERATIONS, averageTime);

    program.link();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glCullFace(GL_FRONT);
}

void MarchingCubesBenchmarkState::processInputs(GLFWwindow *window) {
    input.setWindow(window);

    if (input.isKeyPressed(KEY_M)) {
        showMesh = !showMesh;
        showMesh ? glPolygonMode(GL_FRONT_AND_BACK, GL_FILL) : glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    // Process keyboard input
    camera->processKeyInput(input, glfwGetTime());

    // Process cursor movement input
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    camera->processMouseInput(x, y);
}

bool MarchingCubesBenchmarkState::update() {
    return false;
}

void MarchingCubesBenchmarkState::render(GLFWwindow *window) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 mvp = camera->getProjection() * camera->getView() * glm::mat4(1.0);
    program.setUniformMat4("MVP", mvp);

    program.use();

    mesh->render(Renderable::Mode::Triangles, program);
}
