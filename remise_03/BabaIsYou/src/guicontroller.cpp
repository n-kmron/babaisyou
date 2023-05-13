#include "guicontroller.h"
#include "views/guiview.h"
#include <sstream>
#include <fstream>
#include <filesystem>
#include <limits>

using namespace std;

GuiController::GuiController(GuiView* view) : game_ { make_unique<Game>("level_1") }, view_ { std::move(view) } {
}

void GuiController::launch() {
    view_->show();
    registerAsObserver();
    start();
}

void GuiController::start() {
    view_->editLevelLabel(game_->level());
    game_->start();
}

void GuiController::registerAsObserver() {
    game_->registerObserver(view_);
}


void GuiController::manageEvents(QKeyEvent *keyEvent) {
        if (keyEvent->key() == Qt::Key_Up || keyEvent->key() == Qt::Key_Z)
        {
            game_->move(Direction::UP);
        }
        else if (keyEvent->key() == Qt::Key_Down || keyEvent->key() == Qt::Key_S)
        {
            game_->move(Direction::DOWN);
        }
        else if (keyEvent->key() == Qt::Key_Left || keyEvent->key() == Qt::Key_Q)
        {
            game_->move(Direction::LEFT);
        }
        else if (keyEvent->key() == Qt::Key_Right || keyEvent->key() == Qt::Key_D)
        {
            game_->move(Direction::RIGHT);
        }
        else if (keyEvent->key() == Qt::Key_R)
        {
            restart();
        }
        checkGameState();
}

void GuiController::checkGameState() {
    if(isLost()) {
        view_->displayKilled();
        restart();
    }
    if(isWon()) {
        if(game_->level() < 5) {
            view_->displayNextLevel(game_->level());
            nextLevel();
            start();
        } else {
            view_->displayFinalWon();
        }
    }
}

bool GuiController::isWon() {
    return game_->isWon();
}

bool GuiController::isLost() {
    return game_->isLost();
}

void GuiController::nextLevel() {
    stringstream ss;
    ss << "level_" << game_->level()+1;
    string filename = ss.str();
    game_ = make_unique<Game>(filename);
    registerAsObserver();
}

void GuiController::restart() {
    stringstream ss;
    ss << "level_" << game_->level();
    string filename = ss.str();
    game_ = make_unique<Game>(filename);
    registerAsObserver();
    start();
}

void GuiController::checkSave(string name) {
    if(name.length() == 0) {
        view_->savedFailed("No valid name entered");
        return;
    }
    stringstream ss;
    ss << "levels/saves/" << name << ".txt";
    string location = ss.str();
    ifstream infile(location);

    if(infile.good()) {
        if(view_->overwriteSave()) {
            saveGame(location);
        }
    } else {
        saveGame(location);
    }
}

void GuiController::saveGame(string name) {
    game_->saveGame(name);
    view_->savedSuccessful();
}

void GuiController::chooseLevel(string filename) {
    game_ = make_unique<Game>(filename);
    registerAsObserver();
    start();
}
