#include "guicontroller.h"

using namespace std;

GuiController::GuiController() : game_ { make_unique<Game>("level_1") }, view_ { GuiView() } {
}

void GuiController::launch() {
    view_.show();
    view_.displayTitle();
    //chooseLevel(view_.askWhichLevel());
    registerAsObserver();
    start();
    //while(1) playShot();
}

void GuiController::start() {
    game_->start();
}

void GuiController::registerAsObserver() {
    game_->registerObserver(&view_);
}
