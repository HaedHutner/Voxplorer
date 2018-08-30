#include "Camera.h"

Camera::Camera(
        float fov,
        float cameraSpeed,
        float mouseSensitivity,
        int screenX, int screenY,
        glm::vec3 beginningCoords,
        glm::vec3 beginningDirection,
        glm::vec2 beginningRotation
) : camera_position(beginningCoords),
    camera_direction(beginningDirection),
    camera_target(beginningRotation, 0),
    field_of_view(fov),
    speed_modifyer(cameraSpeed),
    mouse_sensitivity(mouseSensitivity) {

    updateProjection(screenX, screenY);
}

const glm::mat4 Camera::getView() const {
    return glm::lookAt(camera_position, camera_position + camera_front, camera_up);
}

const glm::mat4 &Camera::getProjection() const {
    return projection;
}

const glm::vec3 &Camera::getPosition() const { return camera_position; }

void Camera::updateProjection(int screenX, int screenY) {

    projection = glm::perspective(glm::radians(field_of_view), (double) screenX / screenY, 0.1, 1000.0);
}

void Camera::resetCursor(float x, float y) {
    last_x = x;
    last_y = y;
}

void Camera::move(MoveDirection dir, float speed) {
    switch (dir) {
        case UP:
            camera_position += speed * camera_up;
            break;
        case DOWN:
            camera_position -= speed * camera_up;
            break;
        case FORWARD:
            camera_position += speed * camera_front;
            break;
        case BACK:
            camera_position -= speed * camera_front;
            break;
        case LEFT:
            camera_position -= glm::normalize(glm::cross(camera_front, camera_up)) * speed;
            break;
        case RIGHT:
            camera_position += glm::normalize(glm::cross(camera_front, camera_up)) * speed;
            break;
    }
}

void Camera::processKeyInput(const Keyboard &input, double time) {
    double currentFrame = time;
    delta_time = currentFrame - last_frame;
    last_frame = currentFrame;

    double speed = speed_modifyer * delta_time;

    if (input.isKeyPressed(KEY_LEFT_SHIFT)) speed *= 10.0f;

    if (input.isKeyPressed(KEY_W)) {
        move(FORWARD, speed);
    }

    if (input.isKeyPressed(KEY_S)) {
        move(BACK, speed);
    }

    if (input.isKeyPressed(KEY_A)) {
        move(LEFT, speed);
    }

    if (input.isKeyPressed(KEY_D)) {
        move(RIGHT, speed);
    }

    if (input.isKeyPressed(KEY_SPACE)) {
        move(UP, speed);
    }

    if (input.isKeyPressed(KEY_C)) {
        move(DOWN, speed);
    }
}

void Camera::processMouseInput(double x, double y) {
    if (first_mouse) {
        last_x = x;
        last_y = y;
        first_mouse = false;
    }

    double xOffset = x - last_x;
    double yOffset = last_y - y;

    xOffset *= mouse_sensitivity;
    yOffset *= mouse_sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    glm::vec3 front;
    front.x = (float) cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = (float) sin(glm::radians(pitch));
    front.z = (float) sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    camera_front = glm::normalize(front);

    last_x = x;
    last_y = y;
}

double Camera::getYaw() const {
    return yaw;
}

double Camera::getPitch() const {
    return pitch;
}
