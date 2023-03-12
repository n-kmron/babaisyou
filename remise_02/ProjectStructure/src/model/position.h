#ifndef POSITION_H
#define POSITION_H

#include "direction.h"
#include <stdexcept>

class Position {

    private:
        int row_;
        int col_;

    public:

        /*!
         * \brief Constructeur de Position à partir de sa ligne et sa colonne.
         *
         *
         * \param row la ligne de la position
         * \param col la colonne de la position
         *
         * \throw std::invalid_argument si un des paramètres est négatif.
         */
        Position(const int & row, const int & col);


        // autres méthodes
        /**
         * @brief Donne la nouvelle position à partir d'une direction donnée.
         *
         * @param dir la direction
         *
         * @return la position déplacée
         *
         * @throw si une des coordonnées est négative
         */
        Position next(const Direction & dir);


        // getters
        /*!
         * \brief Accesseur en lecture de la ligne d'une position.
         *
         * \return la ligne de la position
         */
        int row() const;

        /*!
         * \brief Accesseur en lecture de la colonne d'une position.
         *
         * \return la colonne de la position
         */
        int col() const;
};

#endif // POSITION_H
