#include "game.h"
#include <algorithm>
#include <iostream>

using namespace std;

Game::Game(const string fileName) : loader_ { LevelLoader(fileName) }, levelMechanics_ { LevelMechanics(loader_.createLevel(), loader_.numLevel()) } {
}


void Game::start() {
    notifyObservers(levelSize(), elements());
}

bool Game::isWon() {
    return levelMechanics_.isWon();
}

bool Game::isLost() {
    return !levelMechanics_.isThereIsYou();
}

void Game::saveGame(string name) {
    levelMechanics_.saveGame(name);
    notifyObservers(levelSize(), elements());
}

void Game::move(Direction dir) {
    levelMechanics_.move(dir);
    notifyObservers(levelSize(), elements());
}

void Game::restart() {
    notifyObservers(levelSize(), elements());
}

void Game::nextLevel() {
    notifyObservers(levelSize(), elements());
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

