#ifndef GAME_H
#define GAME_H

#include "direction.h"

class Game
{
    private:
        //il faut mettre les attribut qui sont representé par les fleches

    public:
        inline Game();

        inline Game(const int & numLevel);

        inline void start();

        inline bool isWon();

        inline void saveGame();

        inline void playShot(const Direction & dir);

        inline void restart();
};

#endif // GAME_H
