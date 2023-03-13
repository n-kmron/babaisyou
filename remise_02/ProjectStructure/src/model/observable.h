#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"

class Observable
{
    public:
        void registerObserver(const Observer & obs);

        void removeObserver(const Observer & obs);

        void notifyObserver();
};

#endif // OBSERVABLE_H
