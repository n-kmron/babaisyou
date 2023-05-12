#ifndef GAME_H
#define GAME_H

#include "direction.h"
#include "levelloader.h"
#include "levelmechanics.h"
#include "observable.h"
#include <vector>

class Game : public Observable
{
    private:
        LevelLoader loader_;
        LevelMechanics levelMechanics_;

    public:

        Game(const std::string filename);

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
        void move(const Direction & dir);

        void restart();

        void nextLevel();

        unsigned int level();

        /**
         * @brief the row is the first member of the pair and col is the second one
         */
        std::pair<unsigned int, unsigned int> levelSize();

        std::vector<GameObject> & elements();
};

#endif // GAME_H
