#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include "levelmechanics.h"

class LevelLoader
{
    private:
        int numLevel;
        std::vector<std::string> fileAllLines_;

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


       /**
        * @brief getter de fileAllLines_
        * @return
        */
       std::vector<std::string> & fileAllLines();

       /*!
        * \brief Permet de créer un LevelMechanics à partir d'un fichier .txt.
        *
        */
       LevelMechanics createLevel();

       /**
        * @brief Génère un vector de GameObject à portir du fichier correspondant au level
        * @return
        */
       std::vector<GameObject> generateElements();

       /**
        * @brief Génère une map avec comme clé le complément de règle et comme valeur le(s) sujet(s) de la règle
        * @return
        */
       std::map<Element, std::vector<Element>> generateRules();


};

#endif // LEVELLOADER_H
