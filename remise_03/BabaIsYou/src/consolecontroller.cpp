#include "consolecontroller.h"
#include <sstream>
#include <fstream>
#include <filesystem>
#include <limits>

using namespace std;


ConsoleController::ConsoleController() : game_ { make_unique<Game>("level_1") }, view_ { TextView() }  {
};

void ConsoleController::launch() {
    view_.displayTitle();
    chooseLevel(view_.askWhichLevel());
    registerAsObserver();
    start();
    while(1) playShot();
}

void ConsoleController::start() {
    game_->start();
}

void ConsoleController::move(const string & dir) {
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

void ConsoleController::playShot(){
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

bool ConsoleController::isWon() {
    return game_->isWon();
}

bool ConsoleController::isLost() {
    return game_->isLost();
}

void ConsoleController::saveGame(string name) {
    game_->saveGame(name);
}

void ConsoleController::restart() {
    stringstream ss;
    ss << "level_" << game_->level();
    string filename = ss.str();
    game_ = make_unique<Game>(filename);
    registerAsObserver();
    start();
}

void ConsoleController::nextLevel() {
    stringstream ss;
    ss << "level_" << game_->level()+1;
    string filename = ss.str();
    game_ = make_unique<Game>(filename);
    registerAsObserver();
}

void ConsoleController::registerAsObserver() {
    game_->registerObserver(&view_);
}


pair<unsigned int, unsigned int> ConsoleController::levelSize() {
    return game_->levelSize();
}

vector<GameObject> & ConsoleController::elements() {
    return game_->elements();
}

void ConsoleController::chooseLevel(string filename) {
    game_ = make_unique<Game>(filename);
    registerAsObserver();
}


void ConsoleController::checkSave(string name) {
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

