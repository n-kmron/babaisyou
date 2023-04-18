#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"

/**
 * @brief Observable interface to implements the observable-observers design pattern
 */
class Observable
{
    public:
        virtual void registerObserver(Observer * obs) = 0;

        virtual void removeObserver(Observer * obs) = 0;

        virtual void notifyObservers() = 0;
};

#endif // OBSERVABLE_H
