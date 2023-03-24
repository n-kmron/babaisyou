#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include "levelmechanics.h"

class LevelLoader
{
    private:
        int numLevel_;
        std::vector<std::string> fileAllLines_;

        /**
         * @brief rempli l'attribut fileAllLines_ avec le contenu du fichier (sous forme de vector<string>)
         */
        void fileAllLines();

    public:
        /*!
         * \brief Constructeur de LevelLoader à partir du numero du niveau à créer.
         *
         *
         * \param numLevel le numero du niveau
         *
         * \throw std::invalid_argument si le paramètre n'est pas valide.
         */
       LevelLoader(const int & numLevel);


       /*!
        * \brief Permet de créer un LevelMechanics à partir d'un fichier .txt.
        *
        */
       std::vector<GameObject> createLevel();

};

#endif // LEVELLOADER_H
