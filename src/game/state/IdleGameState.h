//
// Created by Miro on 17-Aug-18.
//

#ifndef VOXPLORER_IDLEGAMESTATE_H
#define VOXPLORER_IDLEGAMESTATE_H


#include <engine/GameState.h>
#include <GLFW/glfw3.h>

class IdleGameState : public GameState{
public:

    IdleGameState();

    void processInputs(const GLFWwindow &window) override;

    bool update() override;

    void render(const GLFWwindow &window) override;

};


#endif //VOXPLORER_IDLEGAMESTATE_H
