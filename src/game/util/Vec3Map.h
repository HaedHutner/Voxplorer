//
// Created by miroslav.vasilev on 29.8.2018 г..
//

#ifndef VOXPLORER_VEC3MAP_H
#define VOXPLORER_VEC3MAP_H

#include <functional>
#include <unordered_map>

#include <glm/glm.hpp>

struct Vec3Funcs
{
    size_t operator()(const glm::ivec3& k)const
    {
        return std::hash<int>()(k.x) ^ std::hash<int>()(k.y);
    }

    bool operator()(const glm::ivec3& a, const glm::ivec3& b)const
    {
        return a.x == b.x && a.y == b.y && a.z == b.z;
    }
};

template<class T>
using Vec3Map = std::unordered_map<glm::ivec3,T,Vec3Funcs,Vec3Funcs>;

#endif //VOXPLORER_VOXELCHUNKMAP_H
