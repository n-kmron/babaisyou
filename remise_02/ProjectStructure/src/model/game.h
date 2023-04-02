#ifndef GAME_H
#define GAME_H

#include "direction.h"
#include "level.h"
#include "levelloader.h"
#include "levelmechanics.h"
#include "observable.h"
#include "observer.h"
#include <vector>

class Game : public Observable
{
    private:
        std::vector<Observer*> observers_;
        LevelLoader loader_;
        Level level_;
        LevelMechanics levelMechanics_;

    public:

        Game();

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

        std::vector<GameObject> & elements();

        void registerObserver(Observer * obs) override;
        void removeObserver(Observer * obs) override;
        void notifyObserver() override;
};

#endif // GAME_H
