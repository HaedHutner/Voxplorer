//
// Created by Miro on 18-Aug-18.
//

#include "VoxelGenerator.h"

VoxelGenerator::VoxelGenerator(int seed, int octaves, float gain, float lacunarity)
    : noiseGen(new FastNoise(seed))
{
    noiseGen->SetNoiseType(FastNoise::NoiseType::CubicFractal);
    noiseGen->SetFractalOctaves(octaves);
    noiseGen->SetFractalGain(gain);
    noiseGen->SetFractalLacunarity(lacunarity);
}

Voxel VoxelGenerator::getAt(glm::vec3 position) {
    double result = noiseGen->GetNoise(position.x, position.y, position.z);
    return {position, result};
}

VoxelGenerator::~VoxelGenerator() {
    delete noiseGen;
}
