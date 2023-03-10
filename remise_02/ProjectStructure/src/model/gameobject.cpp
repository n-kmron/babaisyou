#include "gameobject.h"

GameObject::GameObject(const Element & element, const Position & pos)
    :element_{element},pos_{pos}
{
    if (element_ != Element::TEXT_BABA && element_ != Element::TEXT_WALL && element_ != Element::TEXT_ROCK &&
        element_ != Element::TEXT_LAVA && element_ != Element::TEXT_GRASS && element_ != Element::TEXT_METAL &&
        element_ != Element::TEXT_GOOP && element_ != Element::TEXT_FLAG && element_ != Element::IS &&
        element_ != Element::YOU && element_ != Element::WIN && element_ != Element::STOP &&
        element_ != Element::SINK && element_ != Element::PUSH && element_ != Element::KILL &&
        element_ != Element::BABA && element_ != Element::WALL && element_ != Element::ROCK &&
        element_ != Element::LAVA && element_ != Element::GRASS && element_ != Element::METAL &&
        element_ != Element::GOOP && element_ != Element::FLAG) {
        throw std::invalid_argument("Element non valide");
    }
}

Element GameObject::element() const
{
    return element_;
}

Position GameObject::pos() const
{
    return pos_;
}
