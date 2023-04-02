#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include "gameobject.h"
#include <vector>

class LevelLoader
{
    private:
        unsigned int numLevel_;
        std::vector<std::string> fileAllLines_;

        /**
         * @brief fill the attribute 'fileAllLines_' with the content of the file (vector<string>)
         */
        void readAllLines();

    public:

        /*!
         * \brief Constructeur de LevelLoader à partir du numero du niveau à créer.
         *
         *
         * \param numLevel the number of the level to build
         */
       LevelLoader(const unsigned int & numLevel);


       /*!
        * \brief translate string lines to GameObjects to implement the game
        *
        */
       std::vector<GameObject> createLevel();

};

#endif // LEVELLOADER_H
