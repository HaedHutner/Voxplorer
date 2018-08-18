#ifndef VOXPLORER_GAMESTATE_H
#define VOXPLORER_GAMESTATE_H

#include <string>
#include <GLFW/glfw3.h>

/**
 * An updateable and renderable part of the game.
 */
class GameState {

private:

    std::string id;

public:

    explicit GameState(std::string id) : id(std::move(id)) {}

    /**
     * Process any inputs connected to this GLFWwindow
     * @param window
     */
    virtual void processInputs(GLFWwindow *window) = 0;

    /**
     * Update this game state
     * @return Whether or not the updating Game object should replace this game state with GameState#getNext().
     */
    virtual bool update() = 0;

    /**
     * Render the game state
     */
    virtual void render(GLFWwindow *window) = 0;

};


#endif //VOXPLORER_GAMESTATE_H
