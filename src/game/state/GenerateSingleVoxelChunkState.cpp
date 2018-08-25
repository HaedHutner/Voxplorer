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
    glm::ivec3 size = {16, 16, 16};

    chunk = std::make_shared<VoxelChunk>(generator, position, size);

    std::vector<Vertex> vertices = std::vector<Vertex>();
    std::vector<GLuint> indices = std::vector<GLuint>();

    glm::ivec4 corners[8] = {
            {0, 0, 0, 1},
            {1, 0, 0, 2},
            {0, 0, 1, 4},
            {1, 0, 1, 8},
            {0, 1, 0, 16},
            {1, 1, 0, 32},
            {0, 1, 1, 64},
            {1, 1, 1, 128}
    };

/*

       g-------h
      /|      /|
     / |     / |
    e--|----f  |
    |  c----|--d
    | /     | /
    a-------b

    y
    |   z
    |  /
    | /
    |/_____ x

    n(x, y, z)

    a(0, 0, 0)
    b(1, 0, 0)
    c(0, 0, 1)
    d(1, 0, 1)
    e(0, 1, 0)
    f(1, 1, 0)
    g(0, 1, 1)
    h(1, 1, 1)
 */
    unsigned int i = 0;
    for (auto &voxel : chunk->getVoxels()) {

        int type = 0;

        for ( int j = 0; j < 8; j++ ) {
            if ( chunk->getRelativeTo(voxel, glm::vec3(corners[j].x, corners[j].y, corners[j].z) ).isSolid() ) {
                type |= corners[j].w;
            }
        }

        printf("%d\n", type);

        unsigned int material = voxel.isSolid() ? 1 : 0;
        vertices.emplace_back(Vertex(voxel.getPosition(), material));
        indices.emplace_back(i);
        i++;
    }

    mesh->setVertices(vertices);
    mesh->setIndices(indices);

    program.link();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_PROGRAM_POINT_SIZE);
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

    glm::mat4 mvp = camera->getProjection() * camera->getView() * glm::mat4(1.0);
    program.setUniformMat4("MVP", mvp);

    program.use();

    mesh->render(Renderable::Mode::Points, program);
}
