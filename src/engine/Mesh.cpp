//
// Created by miroslav.vasilev on 21.8.2018 г..
//

#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices)
    : vertices(vertices), indices(indices) {

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    verticesSize = (GLuint) vertices.size() * sizeof(Vertex);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, &vertices[0], GL_STATIC_DRAW);

    indicesSize = (GLuint) indices.size() * sizeof(Vertex);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, &indices[0], GL_STATIC_DRAW);

    Vertex::fillVertexArrayObject();

    glBindVertexArray(0);
}

const std::vector<Vertex> &Mesh::getVertices() const {
    return vertices;
}

void Mesh::setVertices(const std::vector<Vertex> &vertices) {
    Mesh::vertices = vertices;
}

const std::vector<GLuint> &Mesh::getIndices() const {
    return indices;
}

void Mesh::setIndices(const std::vector<GLuint> &indices) {
    Mesh::indices = indices;
}

void Mesh::render(const ShaderProgram &program) {
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indicesSize, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}
