#ifndef VOXPLORER_CAMERA_H
#define VOXPLORER_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Keyboard.h"

class Camera {
private:
    double last_frame = 0;
    double delta_time = 0;

    double speed_modifyer = 2.5f;
    double mouse_sensitivity = 0.2f;

    glm::vec3 camera_position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 camera_target = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 camera_direction = glm::normalize(camera_position - camera_target);

    glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 camera_right = glm::normalize(glm::cross(camera_up, camera_direction));

    glm::mat4 projection;

    bool first_mouse = true;
    double yaw = -90.0;    // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
    double pitch = 0.0;
    double last_x;
    double last_y;
    double field_of_view = 90.0;
public:
    enum MoveDirection {
        UP,
        DOWN,
        FORWARD,
        BACK,
        LEFT,
        RIGHT
    };

    Camera(
            float fov = 90.0f,
            float cameraSpeed = 1.0f,
            float mouseSensitivity = 1.0f,
            int screenX = 800,
            int screenY = 600,
            glm::vec3 beginningCoords = {0, 0, 0},
            glm::vec3 beginningDirection = {0, 0, 0},
            glm::vec2 beginningRotation = {0, 0}
    );

    const glm::mat4 getView() const;

    const glm::mat4 &getProjection() const;

    const glm::vec3 &getPosition() const;

    void updateProjection(int screenX, int screenY);

    void resetCursor(float x, float y);

    void move(MoveDirection dir, float speed);

    void processKeyInput(const Keyboard &input, double time);

    void processMouseInput(double x, double y);

    double getYaw() const;

    double getPitch() const;
};

#endif