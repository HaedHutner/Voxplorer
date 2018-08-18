//
// Created by Miro on 18-Aug-18.
//

#ifndef VOXPLORER_SCALARFIELD_H
#define VOXPLORER_SCALARFIELD_H


#include <vector>
#include <glm/glm.hpp>
#include "Voxel.h"
#include "VoxelGenerator.h"

class VoxelChunk {

private:

    glm::ivec3 position;
    glm::ivec3 size;

    std::vector<Voxel> voxels;

public:

    VoxelChunk(VoxelGenerator &generator, glm::ivec3 &position, glm::ivec3 &size);

    const glm::ivec3 &getPosition() const;

    const glm::ivec3 &getSize() const;

    const std::vector<Voxel> &getVoxels() const;

    const Voxel &getRelativeAt(glm::ivec3 &relPosition);

    const Voxel &getAbsoluteAt(glm::ivec3 &absPosition);

    void setRelativeAt(Voxel voxel);

    void setAbsoluteAt(Voxel voxel);

    bool isWithin(glm::ivec3 &pos);

};


#endif //VOXPLORER_SCALARFIELD_H