//
// Created by miroslav.vasilev on 28.8.2018 г..
//

#ifndef VOXPLORER_VOXELWORLDRENDERER_H
#define VOXPLORER_VOXELWORLDRENDERER_H

#include <memory>
#include <thread>

#include <engine/Renderer.h>
#include <engine/Mesh.h>

#include <game/world/VoxelWorld.h>
#include <game/logic/MarchingCubes.h>

class VoxelWorldRenderer : public Renderer {

    std::shared_ptr<VoxelWorld> world;

    Vec3Map<Mesh> chunkMeshes;

    MarchingCubes meshGenerator;

public:

    VoxelWorldRenderer(const std::shared_ptr<VoxelWorld> &world);

    void render(const Camera &camera, const ShaderProgram &program) override;

};


#endif //VOXPLORER_VOXELWORLDRENDERER_H
