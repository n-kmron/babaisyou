#ifndef GAME_H
#define GAME_H

#include "direction.h"
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
        LevelMechanics levelMechanics_;

    public:

        Game(const unsigned int numLevel);

        virtual ~Game() = default;

        /*!
         * \brief Start the game
         *
         */
        void start();

        bool isWon();

        bool isLost();

        void saveGame(std::string name);

        /*!
         * \brief Play a shot (move the character)
         *
         * \param dir the direction to move
         */
        void playShot(const Direction & dir);

        void restart();

        void nextLevel();

        unsigned int level();

        std::vector<GameObject> & elements();

        void registerObserver(Observer * obs) override;
        void removeObserver(Observer * obs) override;
        void notifyObservers() override;
};

#endif // GAME_H
