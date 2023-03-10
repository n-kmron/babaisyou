#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"

class Observable
{
    public:
        inline void registerObserver(const Observer & obs);

        inline void removeObserver(const Observer & obs);

        inline void notifyObserver();
};

#endif // OBSERVABLE_H
