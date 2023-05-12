#include "guicontroller.h"
#include "views/guiview.h"
#include "QtGui/qevent.h"

using namespace std;

GuiController::GuiController(GuiView* view) : game_ { make_unique<Game>("level_1") }, view_ { std::move(view) } {
}

void GuiController::launch() {
    view_->show();
    //chooseLevel(view_.askWhichLevel());
    registerAsObserver();
    start();
    //while(1) playShot();
}

void GuiController::start() {
    game_->start();
}

void GuiController::registerAsObserver() {
    game_->registerObserver(view_);
}


void manageEvents(QKeyEvent *keyEvent) {
    if (keyEvent->key() == Qt::Key_Up || keyEvent->key() == Qt::Key_Z)
    {
        cout << "UP" << endl;
    }
    else if (keyEvent->key() == Qt::Key_Down || keyEvent->key() == Qt::Key_S)
    {
        cout << "DOWN" << endl;
    }
    else if (keyEvent->key() == Qt::Key_Left || keyEvent->key() == Qt::Key_Q)
    {
        cout << "LEFT" << endl;
    }
    else if (keyEvent->key() == Qt::Key_Right || keyEvent->key() == Qt::Key_D)
    {
        cout << "RIGHT" << endl;
    }
    else if (keyEvent->key() == Qt::Key_R)
    {
        cout << "RESTART" << endl;
    }
    else if (keyEvent->key() == Qt::Key_S && keyEvent->modifiers() == Qt::ShiftModifier)
    {
        cout << "SAVE" << endl;
    }
}
