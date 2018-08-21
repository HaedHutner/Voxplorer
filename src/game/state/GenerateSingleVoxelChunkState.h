//
// Created by Miro on 18-Aug-18.
//

#ifndef VOXPLORER_GENERATESINGLEVOXELCHUNKSTATE_H
#define VOXPLORER_GENERATESINGLEVOXELCHUNKSTATE_H


#include <memory>
#include <functional>

#include <engine/GameState.h>
#include <game/world/VoxelChunk.h>
#include <engine/Camera.h>

class GenerateSingleVoxelChunkState : public GameState {

private:

    std::unique_ptr<Camera> camera;

    std::shared_ptr<VoxelChunk> chunk;

public:

    explicit GenerateSingleVoxelChunkState();

    bool update() override;

    void processInputs(GLFWwindow *window) override;

    void render(GLFWwindow *window) override;

};


#endif //VOXPLORER_GENERATESINGLEVOXELCHUNKSTATE_H
