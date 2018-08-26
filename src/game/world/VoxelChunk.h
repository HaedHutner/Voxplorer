//
// Created by Miro on 18-Aug-18.
//

#ifndef VOXPLORER_VOXELCHUNK_H
#define VOXPLORER_VOXELCHUNK_H


#include <vector>
#include <functional>

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

    [[deprecated]]
    const std::vector<Voxel> &getVoxels() const;

    const void forEach(std::function<void(Voxel)> func) const;

    const Voxel getRelativeAt(glm::ivec3 &relPosition) const;

    const Voxel getAbsoluteAt(glm::ivec3 &absPosition) const;

    const Voxel getRelativeTo(const Voxel &voxel, const glm::ivec3 &offset) const;

    bool isWithin(glm::ivec3 &pos) const;

    bool isStrictlyWithin(glm::ivec3 &pos) const;

    void setRelativeAt(Voxel voxel);

    void setAbsoluteAt(Voxel voxel);

};


#endif //VOXPLORER_VOXELCHUNK_H
