//
// Created by miroslav.vasilev on 21.8.2018 г..
//

#ifndef VOXPLORER_VERTEX_HPP
#define VOXPLORER_VERTEX_HPP


#include <glm/glm.hpp>
#include <glad/glad.h>

static const GLuint _VERTEX_POSITION_LOCATION = 0;

struct Vertex {

    glm::vec3 position;

    Vertex(const glm::vec3 &position) :position(position) {

    }

    static void bindAttributes(GLuint program) {
        glBindAttribLocation(program, _VERTEX_POSITION_LOCATION, "position");
    }

    static void fillVertexArrayObject() {
        glEnableVertexAttribArray(_VERTEX_POSITION_LOCATION);
        glVertexAttribPointer(_VERTEX_POSITION_LOCATION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) 0);
    }

};


#endif //VOXPLORER_VERTEX_HPP
