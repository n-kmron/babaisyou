#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "element.h"
#include "position.h"
#include <iostream>

class GameObject
{
    private:
        Element element_;
        Position pos_;

    public:

        /*!
         * \brief Constructor of GameObject from an element and a position
         */
        GameObject(const Element & element, const Position & pos);

        // getters
        Element element() const;

        Position pos() const;

        void setPosition(const Position & pos);
};



#endif // GAMEOBJECT_H
