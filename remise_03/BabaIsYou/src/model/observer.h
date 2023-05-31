#ifndef OBSERVER_H
#define OBSERVER_H

#include "gameobject.h"
#include <vector>

class Observer
{
    public:
        virtual void update(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements) = 0;
};

#endif // OBSERVER_H
