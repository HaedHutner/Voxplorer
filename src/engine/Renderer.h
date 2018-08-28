//
// Created by miroslav.vasilev on 28.8.2018 г..
//

#ifndef VOXPLORER_RENDERER_H
#define VOXPLORER_RENDERER_H

#include <memory>

#include "ShaderProgram.h"
#include "Camera.h"

class Renderer {

public:

    virtual void render(const Camera &camera, const ShaderProgram &program) = 0;

};


#endif //VOXPLORER_RENDERER_H
