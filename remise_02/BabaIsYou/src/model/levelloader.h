#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include "gameobject.h"
#include <vector>

class LevelLoader
{
    private:
        std::string fileLevel_;
        std::vector<std::string> fileAllLines_;
        unsigned int numLevel_;

        /**
         * @brief fill the attribute 'fileAllLines_' with the content of the file (vector<string>)
         */
        void readAllLines();

    public:

        /*!
         * \brief construct a level from his filename
         */
       LevelLoader(const std::string & fileLevel);


       /*!
        * \brief translate string lines to GameObjects to implement the game
        *
        */
       std::vector<GameObject> createLevel();

       unsigned int numLevel();

};

#endif // LEVELLOADER_H
