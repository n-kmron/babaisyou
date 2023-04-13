#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/game.h"

class Controller {

private:
    std::unique_ptr<Game> game_;
    Observer * obs_;

public:

    Controller(Observer * obs);

    void start();

    /**
     * @brief ask the model to play a shot
     */
    void playShot(const Direction & dir);

    bool isWon();

    bool isLost();

    void saveGame(std::string name);

    void restart();

    void nextLevel();

    unsigned int level();

    std::vector<GameObject> elements();

    void registerAsObserver();

    void chooseLevel(std::string filename);

};


#endif // CONTROLLER_H
