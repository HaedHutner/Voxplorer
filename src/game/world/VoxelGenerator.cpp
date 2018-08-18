//
// Created by Miro on 18-Aug-18.
//

#include "VoxelGenerator.h"

VoxelGenerator::VoxelGenerator(int seed)
    : noiseGen(new FastNoise(seed))
{
    noiseGen->SetNoiseType(FastNoise::NoiseType::PerlinFractal);
}

Voxel VoxelGenerator::getAt(glm::vec3 position) {
    double result = noiseGen->GetNoise(position.x, position.y, position.z);
    return {position, result};
}

VoxelGenerator::~VoxelGenerator() {
    delete noiseGen;
}
