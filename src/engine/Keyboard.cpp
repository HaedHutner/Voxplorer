//
// Created by Miro on 25-Aug-18.
//

#include "Keyboard.h"

Keyboard::Keyboard() {
}

Keyboard::Keyboard(GLFWwindow *window) : window(window) {}

bool Keyboard::isKeyPressed(const KeyMacro &keyMacro) const {
    return glfwGetKey(window, keyMacro) == GLFW_PRESS;
}

void Keyboard::setWindow(GLFWwindow *window) {
    Keyboard::window = window;
}
