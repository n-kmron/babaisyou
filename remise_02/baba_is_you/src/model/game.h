#ifndef GAME_H
#define GAME_H

#include "direction.h"

class Game
{
    private:
        //il faut mettre les attribut qui sont representé par les fleches

    public:

        /*!
        * \brief Constructeur par defaut de Game.
        *
        */
        inline Game();

        /*!
         * \brief Constructeur de Game à partir du numero du niveau.
         *
         *
         * \param numLevel le niveau
         *
         * \throw std::invalid_argument si le paramètre n'est pas valide.
         */
        inline Game(const int & numLevel);

        /*!
         * \brief Permet de lancer le jeu.
         *
         */
        inline void start();

        /*!
         * \brief Permet de vérifier si le niveau est gagné.
         *
         * \return true si le niveau est gagné et false si ce n'est pas le cas.
         */
        inline bool isWon();

        /*!
         * \brief Permet de sauver une partie en cours.
         *
         */
        inline void saveGame();

        /*!
         * \brief Permet de jouer un coup.
         *
         * \param dir la direction dans la quelle on veut deplacer le/les element(s)
         */
        inline void playShot(const Direction & dir);

        /*!
         * \brief Permet de recommencer le niveau.
         *
         */
        inline void restart();
};

#endif // GAME_H
