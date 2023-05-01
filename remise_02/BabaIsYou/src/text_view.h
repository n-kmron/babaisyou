#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include "view.h"
#include "model/gameobject.h"
#include "model/observer.h"


class TextView : public View, public Observer {

private:

    std::vector<std::vector<Element>> getPositionsMap(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements);

public:

    TextView();

    void displayTitle() override;

    void displayBoard(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements) override;

    void displayWon() override;

    void displayNextLevel(unsigned int actualLevel) override;

    void displayKilled() override;

    void displayError(std::string message) override;

    /**
     * @brief asks user if he wants to overwrite a save
     */
    bool overwriteSave();

    unsigned int displayUserSaves() override;

    std::string askWhichLevel() override;

    std::string askDir() override;

    bool askRestart() override;

    void askSave() override;

    void update(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements) override;

};

#endif // TEXT_VIEW_H
