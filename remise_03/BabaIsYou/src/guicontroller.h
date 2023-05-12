#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include "model/game.h"
#include "views/guiview.h"
#include <memory>


class GuiController {

private:
    std::unique_ptr<Game> game_;
    GuiView view_;

public:

    GuiController();

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

#endif // GUICONTROLLER_H
