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

#include <game/render/VoxelChunkRenderer.h>

class GenerateSingleVoxelChunkState : public GameState {

private:

    // input

    Keyboard input;

    // game objects

    std::shared_ptr<VoxelChunk> chunk;

    // rendering

    std::unique_ptr<VoxelChunkRenderer> renderer;

    std::shared_ptr<Camera> camera;

    ShaderProgram program;

public:

    explicit GenerateSingleVoxelChunkState();

    bool update() override;

    void processInputs(GLFWwindow *window) override;

    void render(GLFWwindow *window) override;

};


#endif //VOXPLORER_GENERATESINGLEVOXELCHUNKSTATE_H
