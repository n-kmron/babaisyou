#include "game.h"
#include <algorithm>
#include <iostream>

using namespace std;

Game::Game(const string fileName) : observers_ {}, loader_ { LevelLoader(fileName) }, levelMechanics_ { LevelMechanics(loader_.createLevel(), loader_.numLevel()) } {
}


void Game::start() {
    notifyObservers();
}

bool Game::isWon() {
    return levelMechanics_.isWon();
}

bool Game::isLost() {
    return levelMechanics_.isKill() || !levelMechanics_.isThereIsYou();
}

void Game::saveGame(string name) {
    levelMechanics_.saveGame(name);
    notifyObservers();
}

void Game::playShot(const Direction & dir) {
    levelMechanics_.move(dir);
    notifyObservers();
}

void Game::restart() {
    notifyObservers();
}

void Game::nextLevel() {
    notifyObservers();
}

std::vector<GameObject> & Game::elements() {
    return levelMechanics_.elements();
}

unsigned int Game::level() {
    return levelMechanics_.level();
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
void Game::notifyObservers() {
    for (auto obs : observers_) {
        obs->update();
    }
}
