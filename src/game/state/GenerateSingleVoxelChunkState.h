//
// Created by Miro on 18-Aug-18.
//

#ifndef VOXPLORER_GENERATESINGLEVOXELCHUNKSTATE_H
#define VOXPLORER_GENERATESINGLEVOXELCHUNKSTATE_H


#include <memory>

#include <engine/Mesh.h>
#include <engine/GameState.h>
#include <engine/Camera.h>

#include <game/world/VoxelChunk.h>
#include <game/logic/MarchingCubes.h>

class GenerateSingleVoxelChunkState : public GameState {

private:

    KeyStateProvider input;

    std::unique_ptr<Camera> camera;

    std::shared_ptr<VoxelChunk> chunk;

    std::unique_ptr<Mesh> mesh;

    ShaderProgram program;

    MarchingCubes marchingCubes;

public:

    explicit GenerateSingleVoxelChunkState();

    bool update() override;

    void processInputs(GLFWwindow *window) override;

    void render(GLFWwindow *window) override;

};


#endif //VOXPLORER_GENERATESINGLEVOXELCHUNKSTATE_H
