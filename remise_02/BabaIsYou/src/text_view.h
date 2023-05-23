#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

<<<<<<< HEAD
#include "controller.h"
#include "view.h"


class TextView : public View, Observer {

private:
    Controller controller_;

    /**
     * @brief check if the save is safe and allows it or not
     */
    void checkSave(std::string name);
=======
#include "view.h"
#include "model/gameobject.h"
#include "model/observer.h"


class TextView : public View, public Observer {

private:

    std::vector<std::vector<Element>> getPositionsMap(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements);
>>>>>>> 0c9ff050783cabd718539bda29204b3a736a0786

public:

    TextView();

<<<<<<< HEAD
    void launch() override;

    void displayTitle() override;

    void displayBoard() override;

    void displayWon() override;

    void displayNextLevel() override;
=======
    void displayTitle() override;

    void displayBoard(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements) override;

    void displayWon() override;

    void displayNextLevel(unsigned int actualLevel) override;
>>>>>>> 0c9ff050783cabd718539bda29204b3a736a0786

    void displayKilled() override;

    void displayError(std::string message) override;

<<<<<<< HEAD
=======
    /**
     * @brief asks user if he wants to overwrite a save
     */
    bool overwriteSave();

>>>>>>> 0c9ff050783cabd718539bda29204b3a736a0786
    unsigned int displayUserSaves() override;

    std::string askWhichLevel() override;

    std::string askDir() override;

    bool askRestart() override;

    void askSave() override;

<<<<<<< HEAD
    void update() override;
=======
    void update(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements) override;
>>>>>>> 0c9ff050783cabd718539bda29204b3a736a0786

};

#endif // TEXT_VIEW_H
