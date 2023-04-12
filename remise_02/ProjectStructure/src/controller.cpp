#include "controller.h"

Controller::Controller() : game_ { std::make_unique<Game>(1) } {
};

void Controller::start() {
    //game_->start();
}

void Controller::playShot(const Direction & dir){
    game_->playShot(dir);
}

bool Controller::isWon() {
    return game_->isWon();
}

bool Controller::isLost() {
    return game_->isLost();
}

void Controller::saveGame() {
    game_->saveGame();
}

void Controller::restart() {
    unsigned int numLevel = game_->level();
    game_ = std::make_unique<Game>(numLevel);
    game_->start();
}

void Controller::nextLevel(Observer * obs) {
    unsigned int numLevel = game_->level()+1;
    game_ = std::make_unique<Game>(numLevel);
    registerAsObserver(obs);
}

void Controller::registerAsObserver(Observer * obs) {
    game_->registerObserver(obs);
}


unsigned int Controller::level() {
    return game_->level();
}

std::vector<GameObject> Controller::elements() {
    return game_->elements();
}

