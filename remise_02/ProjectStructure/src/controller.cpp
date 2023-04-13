#include "controller.h"

Controller::Controller(Observer * obs) : game_ { std::make_unique<Game>(1) }, obs_ { obs }  {
};

void Controller::start() {
    game_->start();
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

void Controller::saveGame(std::string name) {
    game_->saveGame(name);
}

void Controller::restart() {
    unsigned int numLevel = game_->level();
    game_ = std::make_unique<Game>(numLevel);
    registerAsObserver();
}

void Controller::nextLevel() {
    unsigned int numLevel = game_->level()+1;
    game_ = std::make_unique<Game>(numLevel);
    registerAsObserver();
}

void Controller::registerAsObserver() {
    game_->registerObserver(obs_);
}


unsigned int Controller::level() {
    return game_->level();
}

std::vector<GameObject> Controller::elements() {
    return game_->elements();
}

