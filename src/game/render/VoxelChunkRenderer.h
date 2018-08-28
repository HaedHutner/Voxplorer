//
// Created by miroslav.vasilev on 28.8.2018 г..
//

#ifndef VOXPLORER_VOXELCHUNKRENDERER_H
#define VOXPLORER_VOXELCHUNKRENDERER_H

#include <memory>

#include <engine/Mesh.h>
#include <engine/Renderer.h>

#include <game/logic/MarchingCubes.h>
#include <game/world/VoxelChunk.h>

class VoxelChunkRenderer : public Renderer {

    std::shared_ptr<VoxelChunk> chunk;

    std::unique_ptr<Mesh> chunkMesh;

public:

    explicit VoxelChunkRenderer(const std::shared_ptr<VoxelChunk> &chunk);

    void render(const Camera &camera, const ShaderProgram &program) override;

};


#endif //VOXPLORER_VOXELCHUNKRENDERER_H
