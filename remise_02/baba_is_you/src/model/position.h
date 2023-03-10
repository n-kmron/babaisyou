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
        inline Position(const int & row, const int & col);


        /**
         * @brief Position
         * @param other
         */
        Position(const Position& other) : row_(other.row_), col_(other.col_) {}

        // autres méthodes
        /**
         * @brief Donne la nouvelle position à partir d'une direction donnée.
         *
         * @param dir la direction
         *
         * @return la position déplacée
         */
        inline Position next(const Direction & dir);

        // getters
        /*!
         * \brief Accesseur en lecture de la ligne d'une position.
         *
         * \return la ligne de la position
         */
        inline int row() const;

        /*!
         * \brief Accesseur en lecture de la colonne d'une position.
         *
         * \return la colonne de la position
         */
        inline int col() const;
};

//implémentation du constructeur
Position::Position(const int & row, const int & col) : row_ { row }, col_ { col }
{
    if(row < 0 || col < 0) {
        throw std::invalid_argument("row and col must be positive");
    }
}

//implémentation des getters
int Position::row() const {
    return this->row_;
}

int Position::col() const {
    return this->col_;
}

//implémentation des méthodes
Position Position::next(const Direction & dir) {
        switch (dir)
        {
            case Direction::UP:
                row_ += 1;
                break;
            case Direction::RIGHT:
                col_ += 1;
                break;
            case Direction::DOWN:
                row_ -= 1;
                break;
            case Direction::LEFT:
                col_ -= 1;
                break;
        }
        return this;
}


#endif // POSITION_H
