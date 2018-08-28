#version 330

layout( location = 0 ) in vec3 position;
layout( location = 1 ) in uint material;

out vec4 vecColor;

uniform mat4 MVP;

void main() {
    const uint empty = 0;
    if ( material != empty ) {
        vecColor = vec4(material / 255.0, material / 255.0, material / 255.0, 1.0);
        gl_Position = MVP * vec4(position, 1.0);
    } else {
        gl_Position = vec4(0.0, 0.0, 0.0, 0.0);
    }
}