#include "controller.h"

Controller::Controller(Game & game) : game_ { game } {
};

void Controller::start() {
    game_.start();
}

void Controller::playShot(const Direction & dir){
    game_.playShot(dir);
}

void Controller::saveGame() {
    game_.saveGame();
}

void Controller::restart() {
    game_.restart();
}
