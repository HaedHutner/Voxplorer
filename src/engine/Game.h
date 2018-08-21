#ifndef VOXPLORER_GAME_H
#define VOXPLORER_GAME_H

#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "GameState.h"

class Game {

private:

    GLFWwindow *window;

    std::shared_ptr<GameState> state;

protected:

    int width = 800, height = 600;
    std::string name = "Default Name";

    glm::vec3 background = {0.5f, 0.2f, 0.5f};

public:

    GLFWwindow *getWindow() const;

    void setState(const std::shared_ptr<GameState> &state);

    const std::shared_ptr<GameState> &getState() const;

    virtual bool init() {
        if (!glfwInit()) {
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

        window = glfwCreateWindow(
                width,
                height,
                name.c_str(),
                nullptr,
                nullptr
        );

        if (!window) {
            glfwTerminate();
            return false;
        }

        glfwMakeContextCurrent(window);

        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

        glfwSwapInterval(1);

        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClearColor(background.x, background.y, background.z, 0.0f);

        return true;
    }

    virtual void run() {

        while (!glfwWindowShouldClose(window)) {
            double before = glfwGetTime();

            processInputs();
            update();
            render();

            double after = glfwGetTime();

            printf("Last frame took %dms\n", (int) ( ( after - before ) * 1000 ));
        }

        glfwTerminate();
    }

    virtual void processInputs() {
        state->processInputs(window);
    }

    virtual void update() {
        glfwPollEvents();
        state->update();
    }

    virtual void render() {
        glClear(GL_COLOR_BUFFER_BIT);
        state->render(window);
        glfwSwapBuffers(window);
    }
};


#endif //VOXPLORER_GAME_H
