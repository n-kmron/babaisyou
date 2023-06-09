#include "position.h"
#include <string>
#include <iostream>

using namespace std;

Position::Position(const unsigned int & row, const unsigned int & col) : row_ { row }, col_ { col }
{
    if(row < 0 || col < 0) {
        throw std::invalid_argument("row and col must be positive");
    }
}

unsigned int Position::row() const {
    return this->row_;
}

unsigned int Position::col() const {
    return this->col_;
}

Position Position::next(const Direction & dir) {
        unsigned int row = row_;
        unsigned int col = col_;
        switch (dir)
        {
            case Direction::UP:
                row -= 1;
                break;
            case Direction::RIGHT:
                col += 1;
                break;
            case Direction::DOWN:
                row += 1;
                break;
            case Direction::LEFT:
                col -= 1;
                break;
        }
        return Position(row, col) ;
}

bool Position::operator==(const Position & other) const {
    return (row_ == other.row_ && col_ == other.col_);
}
