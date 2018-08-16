#ifndef VOXPLORER_GAME_H
#define VOXPLORER_GAME_H

#include <memory>

#include "GameState.h"

class Game {

private:

    std::shared_ptr<GameState> state;

public:

    const std::shared_ptr<GameState> &getState() const;

    void update() {
        state->update();
    }

    void render() {
        state->render();
    }

};


#endif //VOXPLORER_GAME_H
