#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/game.h"
#include <memory>


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
    void playShot(const std::string & input);

    bool isWon();

    bool isLost();

    void saveGame(std::string name);

    void restart();

    void nextLevel();

    unsigned int level();

    /**
     * @brief the row is the first member of the pair and col is the second one
     */
    std::pair<unsigned int, unsigned int> levelSize();

    std::vector<GameObject> & elements();

    void registerAsObserver();

    void chooseLevel(std::string filename);

};


#endif // CONTROLLER_H
