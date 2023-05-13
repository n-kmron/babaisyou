#include "guicontroller.h"
#include "views/guiview.h"
#include <sstream>

using namespace std;

GuiController::GuiController(GuiView* view) : game_ { make_unique<Game>("level_1") }, view_ { std::move(view) } {
}

void GuiController::launch() {
    view_->show();
    registerAsObserver();
    start();
}

void GuiController::start() {
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
        view_->displayWon();
        if(game_->level() < 5) {
            nextLevel();
            start();
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
