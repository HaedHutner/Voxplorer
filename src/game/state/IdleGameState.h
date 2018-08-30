//
// Created by Miro on 17-Aug-18.
//

#ifndef VOXPLORER_IDLEGAMESTATE_H
#define VOXPLORER_IDLEGAMESTATE_H

#include <memory>

#include <engine/Mesh.h>
#include <engine/GameState.h>
#include <engine/Camera.h>

class IdleGameState : public GameState{

private:

    Keyboard input;

    std::unique_ptr<Camera> camera;
    std::unique_ptr<Mesh> mesh;

    ShaderProgram program;

public:

    explicit IdleGameState();

    void processInputs(GLFWwindow *window) override;

    bool update() override;

    void render(GLFWwindow *window) override;

};


#endif //VOXPLORER_IDLEGAMESTATE_H
