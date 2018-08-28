//
// Created by Miro on 18-Aug-18.
//

#ifndef VOXPLORER_VOXELGENERATOR_H
#define VOXPLORER_VOXELGENERATOR_H


#include <FastNoise.h>
#include "Voxel.h"

class VoxelGenerator {

private:

    FastNoise* noiseGen;

public:

    explicit VoxelGenerator(int seed, int octaves = 3, float gain = 0.5f, float lacunarity = 2.5f);

    Voxel getAt(glm::vec3 position);

    virtual ~VoxelGenerator();

};


#endif //VOXPLORER_VOXELGENERATOR_H
