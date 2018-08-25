//
// Created by miroslav.vasilev on 21.8.2018 г..
//

#ifndef VOXPLORER_VERTEX_HPP
#define VOXPLORER_VERTEX_HPP

#include <glad/glad.h>

#include <glm/glm.hpp>

static const GLuint _VERTEX_POSITION_LOCATION = 0;
static const GLuint _VERTEX_MATERIAL_LOCATION = 1;

struct Vertex {

    glm::vec3 position;
    GLuint material;

    Vertex(GLfloat x, GLfloat y, GLfloat z, GLuint material) : position({x, y, z}), material(material) {

    }

    Vertex(const glm::vec3 &position, GLuint material) : position(position), material(material) {

    }

    static void bindAttributes(GLuint program) {
        glBindAttribLocation(program, _VERTEX_POSITION_LOCATION, "position");
        glBindAttribLocation(program, _VERTEX_MATERIAL_LOCATION, "material");
    }

    static void fillVertexArrayObject() {
        glEnableVertexAttribArray(_VERTEX_POSITION_LOCATION);
        glVertexAttribPointer(_VERTEX_POSITION_LOCATION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) 0);

        glEnableVertexAttribArray(_VERTEX_MATERIAL_LOCATION);
        glVertexAttribIPointer(_VERTEX_MATERIAL_LOCATION, 1, GL_UNSIGNED_INT, sizeof(Vertex), (void *) (3 * sizeof(GLfloat)));
    }

};


#endif //VOXPLORER_VERTEX_HPP
