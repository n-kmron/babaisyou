#include "game.h"
#include <algorithm>
#include <iostream>

using namespace std;

Game::Game(const string fileName) : loader_ { LevelLoader(fileName) }, levelMechanics_ { LevelMechanics(loader_.createLevel(), loader_.numLevel()) } {
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

std::pair<unsigned int, unsigned int> Game::levelSize() {
    return levelMechanics_.levelSize();
}

