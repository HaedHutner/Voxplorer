//
// Created by Miro on 18-Aug-18.
//

#include "Voxel.h"

Voxel::Voxel() {

}

Voxel::Voxel(const glm::ivec3 position, double value)
    : position(position), value(value)
{

}

const glm::ivec3 &Voxel::getPosition() const {
    return position;
}

void Voxel::setPosition(const glm::ivec3 &position) {
    Voxel::position = position;
}

double Voxel::getValue() const {
    return value;
}

void Voxel::setValue(double value) {
    Voxel::value = value;
}

bool Voxel::isSolid() const {
    return value >= -0.10;
}
