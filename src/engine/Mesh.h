//
// Created by miroslav.vasilev on 21.8.2018 г..
//

#ifndef VOXPLORER_MESH_H
#define VOXPLORER_MESH_H


#include <vector>

#include "Vertex.hpp"
#include "ShaderProgram.h"
#include "Renderable.h"

class Mesh : public Renderable {

private:

    GLuint verticesSize, indicesSize;
    GLuint vao, vbo, ebo;

public:

    Mesh();

    Mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices);

    void setVertices(const std::vector<Vertex> &vertices);

    void setIndices(const std::vector<GLuint> &indices);

    virtual void render(const Mode &mode, const ShaderProgram &program);

};


#endif //VOXPLORER_MESH_H
