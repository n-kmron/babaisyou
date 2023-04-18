#ifndef VIEW_H
#define VIEW_H

#include "model/direction.h"
#include <string>

class View {
public:

    virtual void launch() = 0;

    virtual void displayTitle() = 0;

    virtual void displayBoard() = 0;

    virtual void displayWon() = 0;

    virtual void displayNextLevel() = 0;

    virtual void displayKilled() = 0;

    virtual void displayError(std::string message) = 0;


    /**
     * @brief display all user's saves
     * @return the number of saves from the user
     */
    virtual unsigned int displayUserSaves() = 0;

    /**
     * @brief ask to the user which level he wants to load
     */
    virtual std::string askWhichLevel() = 0;

    /**
     * @brief ask to the user a direction to move
     */
    virtual Direction askDir() = 0;

    /**
     * @brief ask to the user if he wants to restart the game
     */
    virtual bool askRestart() = 0;

    /**
     * @brief ask to the user if he wants to save the game
     */
    virtual void askSave() = 0;
};

#endif // VIEW_H
