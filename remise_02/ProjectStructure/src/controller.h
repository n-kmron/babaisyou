#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/game.h"

class Controller {

private:

    Game game_;
public:

    Controller(Game & game);

    void start();

    /**
     * @brief ask the model to play a shot
     */
    void playShot(const Direction & dir);

    void saveGame();

    void restart();

};


#endif // CONTROLLER_H
