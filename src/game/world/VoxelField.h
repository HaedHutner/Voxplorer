//
// Created by miroslav.vasilev on 27.8.2018 г..
//

#ifndef VOXPLORER_VOXELFIELD_H
#define VOXPLORER_VOXELFIELD_H


#include <functional>

#include "Voxel.h"

class VoxelField {

public:

    virtual const void forEach(std::function<void(const Voxel&)> func) const = 0;

    virtual const Voxel getRelativeAt(glm::ivec3 &relPosition) const = 0;

    virtual const Voxel getAbsoluteAt(glm::ivec3 &absPosition) const = 0;

    virtual bool isWithin(glm::ivec3 &pos) const = 0;

    virtual void setRelativeAt(Voxel voxel) = 0;

    virtual void setAbsoluteAt(Voxel voxel) = 0;

};


#endif //VOXPLORER_VOXELFIELD_H
