#include "Voxplorer.h"
#include <memory>

bool Voxplorer::init() {
    setState(std::make_shared<GenerateSingleVoxelChunkState>());
    return Game::init();
}
