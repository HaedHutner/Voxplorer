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
#include "VoxelField.h"

class VoxelChunk : public VoxelField {

    // do not change
    static const int DISTANCE_BETWEEN_VOXELS = 1;

    glm::ivec3 position;
    glm::ivec3 size;

    std::vector<Voxel> voxels;

public:

    VoxelChunk(VoxelGenerator &generator, glm::ivec3 &position, glm::ivec3 &size);

    const glm::ivec3 &getPosition() const;

    const glm::ivec3 &getSize() const;

    const void forEach(std::function<void(const Voxel&)> func) const override;

    const Voxel getRelativeAt(glm::ivec3 &relPosition) const override;

    const Voxel getAbsoluteAt(glm::ivec3 &absPosition) const override;

    const Voxel getRelativeTo(const Voxel &voxel, const glm::ivec3 &offset) const;

    const int getIndexOf(const glm::ivec3 &relPosition) const;

    bool isWithin(glm::ivec3 &pos) const override;

    void setRelativeAt(Voxel voxel) override;

    void setAbsoluteAt(Voxel voxel) override;

};


#endif //VOXPLORER_VOXELCHUNK_H
