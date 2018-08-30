//
// Created by miroslav.vasilev on 27.8.2018 г..
//

#ifndef VOXPLORER_VOXELWORLD_H
#define VOXPLORER_VOXELWORLD_H


#include <memory>
#include <unordered_map>

#include "VoxelField.h"
#include "VoxelChunk.h"
#include "VoxelChunkMap.hpp"

class VoxelWorld : public VoxelField {

    VoxelGenerator generator;

    glm::ivec3 origin;

    glm::ivec3 chunkSize;

    std::shared_ptr<VoxelChunkMap> chunks;

public:

    VoxelWorld(const VoxelGenerator &generator, const glm::ivec3 &origin, const glm::ivec3 &chunkSize);

    [[deprecated]]
    const void forEach(std::function<void(const Voxel &)> func) const override;

    const void forEach(std::function<void(const VoxelChunk &)> func) const;

    const Voxel getRelativeAt(const glm::ivec3 &relPosition) const override;

    const Voxel getAbsoluteAt(const glm::ivec3 &absPosition) const override;

    bool isWithin(const glm::ivec3 &pos) const override;

    void setRelativeAt(Voxel voxel) override;

    void setAbsoluteAt(Voxel voxel) override;

    const std::shared_ptr<VoxelChunkMap> &getChunks() const;

    void generateChunkAt(const glm::ivec3 &chunkPosition);

    glm::ivec3 getChunkPosition(const glm::vec3 &absPosition);

};


#endif //VOXPLORER_VOXELWORLD_H
