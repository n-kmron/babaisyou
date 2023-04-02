#ifndef GAME_H
#define GAME_H

#include "direction.h"

class Game
{
    private:
        //il faut mettre les attribut qui sont representé par les fleches

    public:

        Game() = default;

        /*!
         * \brief Constructor of Game from his number
         *
         *
         * \param numLevel the number of the level to build
        */
        Game(const unsigned int & numLevel);

        /*!
         * \brief Start the game
         *
         */
        void start();

        bool isWon();

        void saveGame();

        /*!
         * \brief Play a shot (move the character)
         *
         * \param dir the direction to move
         */
        void playShot(const Direction & dir);

        void restart();
};

#endif // GAME_H
