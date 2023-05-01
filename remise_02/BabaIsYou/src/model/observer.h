#ifndef OBSERVER_H
#define OBSERVER_H

#include "gameobject.h"
#include <vector>

/**
 * @brief Observer interface to implements the observable-observers design pattern
 */
class Observer
{
    public:
        virtual void update(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements) = 0;
};

#endif // OBSERVER_H
