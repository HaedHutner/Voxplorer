#ifndef VOXPLORER_VOXPLORER_H
#define VOXPLORER_VOXPLORER_H

#include <memory>

#include <engine/Game.h>

#include <game/state/GenerateSingleVoxelChunkState.h>

class Voxplorer : public Game {

public:

    Voxplorer();

    bool init();

};


#endif //VOXPLORER_VOXPLORER_H
