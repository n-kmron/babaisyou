#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include "../model/gameobject.h"
#include "../model/observer.h"


class TextView : public Observer {

private:

    std::vector<std::vector<Element>> getPositionsMap(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements);

public:

    TextView();

    void displayTitle();

    void displayBoard(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements);

    void displayWon();

    void displayNextLevel(unsigned int actualLevel);

    void displayKilled();

    void displayError(std::string message);

    /**
     * @brief asks user if he wants to overwrite a save
     */
    bool overwriteSave();

    unsigned int displayUserSaves();

    std::string askWhichLevel();

    std::string askDir();

    bool askRestart();

    void askSave();

    void update(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements);

};

#endif // TEXT_VIEW_H
