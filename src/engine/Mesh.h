//
// Created by miroslav.vasilev on 21.8.2018 г..
//

#ifndef VOXPLORER_MESH_H
#define VOXPLORER_MESH_H


#include <vector>

#include "Vertex.hpp"
#include "ShaderProgram.h"

class Mesh {

private:

    GLuint verticesSize, indicesSize;
    GLuint vao, vbo, ebo;

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

public:

    Mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices);

    const std::vector<Vertex> &getVertices() const;

    void setVertices(const std::vector<Vertex> &vertices);

    const std::vector<GLuint> &getIndices() const;

    void setIndices(const std::vector<GLuint> &indices);

    virtual void render(const ShaderProgram &program);

};


#endif //VOXPLORER_MESH_H
