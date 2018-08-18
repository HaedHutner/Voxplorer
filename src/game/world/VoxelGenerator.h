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

    VoxelGenerator(int seed);

    Voxel getAt(glm::vec3 position);

    virtual ~VoxelGenerator();

};


#endif //VOXPLORER_VOXELGENERATOR_H
