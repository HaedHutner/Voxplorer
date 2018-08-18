//
// Created by Miro on 18-Aug-18.
//

#include "VoxelChunk.h"

VoxelChunk::VoxelChunk(VoxelGenerator &generator, glm::ivec3 &position, glm::ivec3 &size)
        : position(position), size(size), voxels(size.x * size.y * size.z) {

    for (int x = 0; x < size.x; x++) {
        for (int y = 0; y < size.y; y++) {
            for (int z = 0; z < size.z; z++) {
                int i = x + size.x * ( y + size.y * z );
                voxels[i] = generator.getAt({position.x + x, position.y + y, position.z + z});
            }
        }
    }

}

const glm::ivec3 &VoxelChunk::getPosition() const {
    return position;
}

const glm::ivec3 &VoxelChunk::getSize() const {
    return size;
}

const std::vector<Voxel> &VoxelChunk::getVoxels() const {
    return voxels;
}

const Voxel &VoxelChunk::getRelativeAt(glm::ivec3 &relPosition) {
    return voxels[relPosition.x + size.x * ( relPosition.y + size.y * relPosition.z )];
}

const Voxel &VoxelChunk::getAbsoluteAt(glm::ivec3 &absPosition) {
    glm::ivec3 relPosition = { absPosition.x - position.x, absPosition.y - position.y, absPosition.z };
    return getRelativeAt(relPosition);
}

bool VoxelChunk::isWithin(glm::ivec3 &pos) {
    bool fitX = pos.x >= position.x && pos.x <= position.x + size.x;
    bool fitY = pos.y >= position.y && pos.y <= position.y + size.y;
    bool fitZ = pos.z >= position.z && pos.z <= position.z + size.z;
    return fitX && fitY && fitZ;
}

void VoxelChunk::setRelativeAt(Voxel voxel) {
    // TODO
}

void VoxelChunk::setAbsoluteAt(Voxel voxel) {
    // TODO
}