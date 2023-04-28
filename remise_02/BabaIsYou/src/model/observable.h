#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"
#include <vector>

/**
 * @brief Observable interface to implements the observable-observers design pattern
 */
class Observable
{
private:
    std::vector<Observer*> observers_;

public:
    virtual void registerObserver(Observer * obs) {
        observers_.push_back(obs);
    }

    virtual void removeObserver(Observer * obs) {
        for (auto it = observers_.begin(); it != observers_.end(); ++it) {
            if (*it == obs) {
                observers_.erase(it);
                break;
            }
        }
    }

    virtual void notifyObservers() {
        for (auto obs : observers_) {
            obs->update();
        }
    }
};

#endif // OBSERVABLE_H
