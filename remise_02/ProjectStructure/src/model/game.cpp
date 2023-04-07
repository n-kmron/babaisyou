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
    return levelMechanics_.isWon();
}

bool Game::isLost() {
    return levelMechanics_.isKill();
}

void Game::saveGame() {
    notifyObserver();
}

void Game::playShot(const Direction & dir) {
    levelMechanics_.move(dir);
    notifyObserver();
}

void Game::restart() {
    notifyObserver();
}

void Game::nextLevel() {
    notifyObserver();
}

std::vector<GameObject> & Game::elements() {
    return levelMechanics_.elements();
}

unsigned int Game::level() {
    return level_.numLevel()+1;
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
