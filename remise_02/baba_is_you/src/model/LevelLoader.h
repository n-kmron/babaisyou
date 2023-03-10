#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include "levelmechanics.h"

class LevelLoader
{
    private:
        int numLevel;

    public:
        /*!
         * \brief Constructeur de LevelLoader à partir du numero du niveau à créer.
         *
         *
         * \param numLevel le numero du niveau
         *
         * \throw std::invalid_argument si le paramètre n'est pas valide.
         */
       inline LevelLoader(const int & numLevel);

       /*!
        * \brief Permet de créer un LevelMechanics à partir d'un fichier .text.
        *
        */
       inline LevelMechanics createLevel();

};

#endif // LEVELLOADER_H
