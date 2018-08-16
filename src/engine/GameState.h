#ifndef VOXPLORER_GAMESTATE_H
#define VOXPLORER_GAMESTATE_H


virtual class GameState {

public:

    virtual void update() = 0;

    virtual void render() = 0;

};


#endif //VOXPLORER_GAMESTATE_H
