#include "game.h"
#include "levelloader.h"
#include <algorithm>
#include <iostream>

using namespace std;

Game::Game() : observers_ {}, loader_ { LevelLoader(1) }, level_ { Level(1) }, levelMechanics_ { LevelMechanics(loader_.createLevel()) } {
}


void Game::start() {
    notifyObserver();
}

bool Game::isWon() {
    notifyObserver();
    return false;
}

void Game::saveGame() {
    notifyObserver();
}

void Game::playShot(const Direction & dir) {
    notifyObserver();
}

void Game::restart() {
    notifyObserver();
}

std::vector<GameObject> & Game::elements() {
    return levelMechanics_.elements();
}


void Game::registerObserver(Observer * obs) {
    observers_.push_back(obs);
}
void Game::removeObserver(Observer * obs) {
    for (auto it = observers_.begin(); it != observers_.end(); ++it) {
        if (*it == obs) {
            observers_.erase(it);
            break;
        }
    }
}
void Game::notifyObserver() {
    for (auto obs : observers_) {
        obs->update();
    }
}
