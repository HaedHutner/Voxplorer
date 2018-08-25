//
// Created by Miro on 25-Aug-18.
//

#include "KeyStateProvider.h"

KeyStateProvider::KeyStateProvider() {
}

KeyStateProvider::KeyStateProvider(GLFWwindow *window) : window(window) {}

bool KeyStateProvider::isKeyPressed(const KeyMacro &keyMacro) const {
    return glfwGetKey(window, keyMacro) == GLFW_PRESS;
}

void KeyStateProvider::setWindow(GLFWwindow *window) {
    KeyStateProvider::window = window;
}
