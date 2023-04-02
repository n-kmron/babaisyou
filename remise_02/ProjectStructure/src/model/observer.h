#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief Observer interface to implements the observable-observers design pattern
 */
class Observer
{
    public:
        virtual void update() = 0;
};

#endif // OBSERVER_H
