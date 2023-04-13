#ifndef POSITION_H
#define POSITION_H

#include "direction.h"
#include <stdexcept>

class Position {

    private:
        unsigned int row_;
        unsigned int col_;

    public:

        /*!
         * \brief Constructor of a Position from a row and a col
         */
        Position(const unsigned int & row, const unsigned int & col);


        // autres méthodes
        /**
         * @brief moves a position in a direction
         * @throw if a coordinate is negative
         */
        Position next(const Direction & dir);


        // getters
        unsigned int row() const;

        unsigned int col() const;

        bool operator==(const Position & other) const;

};


std::ostream & operator<<(std::ostream & out, const Position & in);


#endif // POSITION_H
