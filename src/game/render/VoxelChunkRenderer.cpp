//
// Created by miroslav.vasilev on 28.8.2018 г..
//

#include "VoxelChunkRenderer.h"

VoxelChunkRenderer::VoxelChunkRenderer(const std::shared_ptr<VoxelChunk> &chunk) : chunk(chunk) {
    MarchingCubes meshAlgorithm = MarchingCubes();
    chunkMesh = meshAlgorithm.generateMesh(*chunk.get());

    glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glCullFace(GL_FRONT);
}

void VoxelChunkRenderer::render(const Camera &camera, const ShaderProgram &program) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 mvp = camera.getProjection() * camera.getView() * glm::mat4(1.0);
    program.setUniformMat4("MVP", mvp);

    program.use();

    chunkMesh->render(Renderable::Mode::Triangles, program);
}
