//
// Created by Miro on 25-Aug-18.
//

#include <bitset>
#include <iostream>
#include "MarchingCubes.h"

MarchingCubes::MarchingCubes() {
}

std::unique_ptr<Mesh> MarchingCubes::generateMesh(const VoxelChunk &chunk) {
    std::unique_ptr<Mesh> mesh = std::unique_ptr<Mesh>(new Mesh());

    std::vector<Vertex> vertices = std::vector<Vertex>();
    std::vector<GLuint> indices = std::vector<GLuint>();

    GLuint i = 0;
    for (auto &voxel : chunk.getVoxels()) {

        GLuint type = 0;

        for (int j = 0; j < 8; j++) {

            glm::ivec3 offsetCorner = glm::ivec3(
                    voxel.getPosition().x + corners[j].x,
                    voxel.getPosition().y + corners[j].y,
                    voxel.getPosition().z + corners[j].z
            );

            if ( !chunk.isWithin(offsetCorner) ) continue;

            if ( chunk.getAbsoluteAt(offsetCorner).isSolid() ) {
                type |= corners[j].w;
            }
        }

        if ( type == 0xff || type == 0x0 ) continue;

        vertices.emplace_back(Vertex(voxel.getPosition(), (GLuint) std::round( std::abs(voxel.getValue() * 4) * 255) ));
        indices.emplace_back(i);

        i++;
    }

    mesh->setVertices(vertices);
    mesh->setIndices(indices);

    return mesh;
}
