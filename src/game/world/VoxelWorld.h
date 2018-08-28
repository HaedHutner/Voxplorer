//
// Created by miroslav.vasilev on 27.8.2018 г..
//

#ifndef VOXPLORER_VOXELWORLD_H
#define VOXPLORER_VOXELWORLD_H


#include <memory>
#include "VoxelField.h"
#include "VoxelChunk.h"

class VoxelWorld : public VoxelField {

    VoxelGenerator generator;

    glm::vec3 origin;

    glm::vec3 chunkSize;

    std::vector<std::shared_ptr<VoxelChunk>> chunks;

public:

    VoxelWorld(const VoxelGenerator &generator, const glm::vec3 &origin, const glm::vec3 &chunkSize);

    const void forEach(std::function<void(const Voxel &)> func) const override;

    const Voxel getRelativeAt(glm::ivec3 &relPosition) const override;

    const Voxel getAbsoluteAt(glm::ivec3 &absPosition) const override;

    bool isWithin(glm::ivec3 &pos) const override;

    void setRelativeAt(Voxel voxel) override;

    void setAbsoluteAt(Voxel voxel) override;

};


#endif //VOXPLORER_VOXELWORLD_H
