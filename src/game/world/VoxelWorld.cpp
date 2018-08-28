//
// Created by miroslav.vasilev on 27.8.2018 г..
//

#include "VoxelWorld.h"

VoxelWorld::VoxelWorld(const VoxelGenerator &generator, const glm::vec3 &origin, const glm::vec3 &chunkSize)
        : generator(generator), origin(origin), chunkSize(chunkSize) {

}

const void VoxelWorld::forEach(std::function<void(const Voxel &)> func) const {
    return;
}

const Voxel VoxelWorld::getRelativeAt(glm::ivec3 &relPosition) const {
    return Voxel();
}

const Voxel VoxelWorld::getAbsoluteAt(glm::ivec3 &absPosition) const {
    return Voxel();
}

bool VoxelWorld::isWithin(glm::ivec3 &pos) const {
    return false;
}

void VoxelWorld::setRelativeAt(Voxel voxel) {

}

void VoxelWorld::setAbsoluteAt(Voxel voxel) {

}
