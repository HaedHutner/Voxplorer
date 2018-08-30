//
// Created by miroslav.vasilev on 27.8.2018 г..
//

#ifndef VOXPLORER_MARCHINGCUBESBENCHMARKSTATE_H
#define VOXPLORER_MARCHINGCUBESBENCHMARKSTATE_H


#include <memory>

#include <engine/Mesh.h>
#include <engine/GameState.h>
#include <engine/Camera.h>

#include <game/world/VoxelChunk.h>
#include <game/logic/MarchingCubes.h>

class MarchingCubesBenchmarkState : public GameState {

private:

    bool showMesh = false;

    Keyboard input;

    std::unique_ptr<Camera> camera;

    std::shared_ptr<VoxelChunk> chunk;

    std::unique_ptr<Mesh> mesh;

    ShaderProgram program;

    MarchingCubes marchingCubes;

public:

    explicit MarchingCubesBenchmarkState();

    bool update() override;

    void processInputs(GLFWwindow *window) override;

    void render(GLFWwindow *window) override;

};


#endif //VOXPLORER_MARCHINGCUBESBENCHMARKSTATE_H
