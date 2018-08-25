//
// Created by Miro on 25-Aug-18.
//

#ifndef VOXPLORER_RENDERABLE_H
#define VOXPLORER_RENDERABLE_H


#include "ShaderProgram.h"

class Renderable {

public:

    enum Mode {
        Triangles = GL_TRIANGLES,
        Points = GL_POINTS,
        Quads = GL_QUADS
    };

    virtual void render(const Mode &mode, const ShaderProgram &program) = 0;

};


#endif //VOXPLORER_RENDERABLE_H
