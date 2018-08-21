#version 330

in vec3 position;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

void main() {
    gl_Position = model * view * projection * vec4(position, 0);
}