#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include "controller.h"
#include "view.h"


class TextView : public View, Observer {

private:
    Controller controller_;

    /**
     * @brief check if the save is safe and allows it or not
     */
    void checkSave(std::string name);

public:

    TextView();

    void launch() override;

    void displayTitle() override;

    void displayBoard() override;

    void displayWon() override;

    void displayNextLevel() override;

    void displayKilled() override;

    void displayError(std::string message) override;

    unsigned int displayUserSaves() override;

    std::string askWhichLevel() override;

    std::string askDir() override;

    bool askRestart() override;

    void askSave() override;

    void update() override;

};

#endif // TEXT_VIEW_H
