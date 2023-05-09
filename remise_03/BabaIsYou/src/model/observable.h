#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>
#include "observer.h"

/**
 * @brief Observable interface to implements the observable-observers design pattern
 */
class Observable
{
private:
    std::set<Observer *> observers_;

public:

    virtual void registerObserver(Observer * obs) {
        observers_.insert(obs);
    }

    virtual void removeObserver(Observer * obs) {
        observers_.erase(obs);
    }

    void notifyObservers(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements) const {
        for (auto obs : observers_) {
            obs->update(sizes, elements);
        }
    }
};

#endif // OBSERVABLE_H
