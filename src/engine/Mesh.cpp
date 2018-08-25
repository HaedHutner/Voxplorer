//
// Created by miroslav.vasilev on 21.8.2018 г..
//

#include "Mesh.h"

Mesh::Mesh() {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    verticesSize = 0;
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, nullptr, GL_STATIC_DRAW);

    indicesSize = 0;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, nullptr, GL_STATIC_DRAW);

    Vertex::fillVertexArrayObject();

    glBindVertexArray(0);
}

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices) {

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    verticesSize = (GLuint) vertices.size() * sizeof(Vertex);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, &vertices[0], GL_STATIC_DRAW);

    indicesSize = (GLuint) indices.size() * sizeof(GLuint);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, &indices[0], GL_STATIC_DRAW);

    Vertex::fillVertexArrayObject();

    glBindVertexArray(0);
}

void Mesh::setVertices(const std::vector<Vertex> &vertices) {
    glBindVertexArray(vao);

    verticesSize = (GLuint) vertices.size() * sizeof(Vertex);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, &vertices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::setIndices(const std::vector<GLuint> &indices) {
    glBindVertexArray(vao);

    indicesSize = (GLuint) indices.size() * sizeof(GLuint);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, &indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::render(const Mode &mode, const ShaderProgram &program) {
    glBindVertexArray(vao);
    glDrawElements(mode, indicesSize, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}
