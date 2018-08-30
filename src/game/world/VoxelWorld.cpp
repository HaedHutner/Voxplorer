//
// Created by miroslav.vasilev on 27.8.2018 г..
//

#include "VoxelWorld.h"

VoxelWorld::VoxelWorld(
        const VoxelGenerator &generator,
        const glm::ivec3 &origin,
        const glm::ivec3 &chunkSize
) :
        generator(generator),
        origin(origin),
        chunkSize(chunkSize) {

    for ( int i = 0; i < 3; i++ ) {
        for ( int j = 0; j < 3; j++ ) {
            for ( int k = 0; k < 3; k++ ) {
                generateChunkAt({i, j, k});
            }
        }
    }

}

const void VoxelWorld::forEach(std::function<void(const Voxel &)> func) const {
    for ( auto &chunk : *chunks ) {
        chunk.second.forEach(func);
    }
}

const Voxel VoxelWorld::getRelativeAt(const glm::ivec3 &relPosition) const {
    return Voxel();
}

const Voxel VoxelWorld::getAbsoluteAt(const glm::ivec3 &absPosition) const {
    return Voxel();
}

bool VoxelWorld::isWithin(const glm::ivec3 &pos) const {
    return false;
}

void VoxelWorld::setRelativeAt(Voxel voxel) {

}

void VoxelWorld::setAbsoluteAt(Voxel voxel) {

}

const std::shared_ptr<VoxelChunkMap> &VoxelWorld::getChunks() const {
    return chunks;
}

glm::ivec3 VoxelWorld::getChunkPosition(const glm::vec3 &absPosition) {
    glm::ivec3 chunkPosition = {
            std::floor(absPosition.x / chunkSize.x),
            std::floor(absPosition.y / chunkSize.y),
            std::floor(absPosition.z / chunkSize.z)
    };

    return chunkPosition;
}

void VoxelWorld::generateChunkAt(const glm::ivec3 &chunkPosition) {

    std::shared_ptr<VoxelChunk> chunk = std::make_shared<VoxelChunk>(generator, chunkPosition * chunkSize, chunkSize);
    chunks->emplace(chunkPosition, chunk);

}

const void VoxelWorld::forEach(std::function<void(const VoxelChunk &)> func) const {
    for ( auto &chunk : *chunks ) {
        func(chunk.second);
    }
}
