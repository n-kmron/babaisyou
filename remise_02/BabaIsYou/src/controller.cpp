#include "controller.h"
#include <sstream>

Controller::Controller(Observer * obs) : game_ { std::make_unique<Game>("level_1") }, obs_ { obs }  {
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
    std::stringstream ss;
    ss << "level_" << game_->level();
    std::string filename = ss.str();
    game_ = std::make_unique<Game>(filename);
    registerAsObserver();
    start();
}

void Controller::nextLevel() {
    std::stringstream ss;
    ss << "level_" << game_->level()+1;
    std::string filename = ss.str();
    game_ = std::make_unique<Game>(filename);
    registerAsObserver();
}

void Controller::registerAsObserver() {
    game_->registerObserver(obs_);
}


unsigned int Controller::level() {
    return game_->level();
}

std::pair<unsigned int, unsigned int> Controller::levelSize() {
    return game_->levelSize();
}

std::vector<GameObject> Controller::elements() {
    return game_->elements();
}

void Controller::chooseLevel(std::string filename) {
    game_ = std::make_unique<Game>(filename);
    registerAsObserver();
}


