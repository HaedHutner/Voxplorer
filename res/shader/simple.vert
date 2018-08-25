#version 330

layout( location = 0 ) in vec3 position;
layout( location = 1 ) in uint material;

out vec4 vecColor;

uniform mat4 MVP;

void main() {
    if ( material != 0 ) {
        vecColor = vec4(1.0, 1.0, 1.0, 1.0);
        gl_Position = MVP * vec4(position, 1.0);
        gl_PointSize = 5.0;
    } else {
        gl_Position = vec4(0.0, 0.0, 0.0, 0.0);
    }
}