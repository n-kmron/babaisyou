#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/game.h"

class Controller {

private:

    std::unique_ptr<Game> game_;

public:

    Controller();

    void start();

    /**
     * @brief ask the model to play a shot
     */
    void playShot(const Direction & dir);

    bool isWon();

    bool isLost();

    void saveGame();

    void restart();

    void nextLevel(Observer * obs);

    unsigned int level();

    std::vector<GameObject> elements();

    void registerAsObserver(Observer * obs);

};


#endif // CONTROLLER_H
