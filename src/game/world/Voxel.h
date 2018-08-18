//
// Created by Miro on 18-Aug-18.
//

#ifndef VOXPLORER_VOXEL_H
#define VOXPLORER_VOXEL_H

#include <glm/glm.hpp>

class Voxel {

private:

    glm::ivec3 position;
    double value;

public:

    Voxel();

    Voxel(glm::ivec3 position, double solid);

    const glm::ivec3 &getPosition() const;

    void setPosition(const glm::ivec3 &position);

    double getValue() const;

    void setValue(double value);

};


#endif //VOXPLORER_VOXEL_H
