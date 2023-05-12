#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/game.h"
#include "textview.h"
#include <memory>


class ConsoleController {

private:
    std::unique_ptr<Game> game_;
    TextView view_;

public:

    ConsoleController();

    void launch();

    void start();

    void move(const std::string & dir);

    void playShot();

    bool isWon();

    bool isLost();

    void saveGame(std::string name);

    void checkSave(std::string name);

    void restart();

    void nextLevel();

    /**
     * @brief the row is the first member of the pair and col is the second one
     */
    std::pair<unsigned int, unsigned int> levelSize();

    std::vector<GameObject> & elements();

    void registerAsObserver();

    void chooseLevel(std::string filename);

};


#endif // CONTROLLER_H
