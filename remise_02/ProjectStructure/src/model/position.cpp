#include "position.h"
#include <string>
#include <iostream>

using namespace std;

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
        int row = row_;
        int col = col_;
        switch (dir)
        {
            case Direction::UP:
                row += 1;
                break;
            case Direction::RIGHT:
                col += 1;
                break;
            case Direction::DOWN:
                row -= 1;
                break;
            case Direction::LEFT:
                col -= 1;
                break;
        }
        return Position(row, col) ;
}

string Position::to_string() const {
    string result;
    result
    .append("[")
    .append(std::to_string(this->col()))
    .append(";")
    .append(std::to_string(this->row()))
    .append("]");

    return result;
}



//implémentation des opérateurs
std::ostream & operator<<(std::ostream & out, const Position & in) {
    return out << in.to_string();
}

bool Position::operator==(const Position & other) const {
    return (row_ == other.row_ && col_ == other.col_);
}
