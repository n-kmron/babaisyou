#include "controller.h"
#include <sstream>
#include <fstream>
#include <filesystem>
#include <limits>

using namespace std;


Controller::Controller() : game_ { make_unique<Game>("level_1") }, view_ { TextView() }  {
};

void Controller::launch() {
    view_.displayTitle();
    chooseLevel(view_.askWhichLevel());
    registerAsObserver();
    start();
    while(1) playShot();
}

void Controller::start() {
    game_->start();
}

void Controller::move(const string & dir) {
    if(dir == "Z") {
        game_->move(Direction::UP);
    }
    if(dir == "Q") {
        game_->move(Direction::LEFT);
    }
    if(dir == "S") {
        game_->move(Direction::DOWN);
    }
    if(dir == "D") {
        game_->move(Direction::RIGHT);
    }
}

void Controller::playShot(){
    if(isLost()) {
        view_.displayKilled();
        if(view_.askRestart()) {
            restart();
        } else {
            exit(0);
        }
    }

    if(!isWon()) {
        string input = view_.askDir();
        if(input == "R") {
            restart();
        } else {
            move(input);
        }
    }

    else {
        view_.displayWon();
        if(game_->level() < 5) {
            view_.displayNextLevel(game_->level());
            nextLevel();
            view_.askSave();
            start();
        } else {
            exit(0);
        }
    }
}

bool Controller::isWon() {
    return game_->isWon();
}

bool Controller::isLost() {
    return game_->isLost();
}

void Controller::saveGame(string name) {
    game_->saveGame(name);
}

void Controller::restart() {
    stringstream ss;
    ss << "level_" << game_->level();
    string filename = ss.str();
    game_ = make_unique<Game>(filename);
    registerAsObserver();
    start();
}

void Controller::nextLevel() {
    stringstream ss;
    ss << "level_" << game_->level()+1;
    string filename = ss.str();
    game_ = make_unique<Game>(filename);
    registerAsObserver();
}

void Controller::registerAsObserver() {
    game_->registerObserver(&view_);
}


pair<unsigned int, unsigned int> Controller::levelSize() {
    return game_->levelSize();
}

vector<GameObject> & Controller::elements() {
    return game_->elements();
}

void Controller::chooseLevel(string filename) {
    game_ = make_unique<Game>(filename);
    registerAsObserver();
}


void Controller::checkSave(string name) {
    stringstream ss;
    ss << "levels/saves/" << name << ".txt";
    string location = ss.str();
    ifstream infile(location);

    if(infile.good()) {
        if(view_.overwriteSave()) {
            saveGame(location);
        }
    } else {
        saveGame(location);
    }
}

