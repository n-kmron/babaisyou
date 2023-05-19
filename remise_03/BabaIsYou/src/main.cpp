//#include "consolecontroller.h"
#include "views/menuview.h"
#include "views/guiview.h"
#include "guicontroller.h"
#include <memory>
#include <utility>
#include "QtWidgets/qapplication.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    //to activate console launcher uncomment this line below and put 'run in terminal'
    //ConsoleController controller;

    //use the forward declaration
    GuiView view;
    GuiController controller(&view);
    view.setController(&controller);

    MenuView menu(nullptr, &view, &controller);
    menu.show();

    return application.exec();
}

