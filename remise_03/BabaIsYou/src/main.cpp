//#include "consolecontroller.h"
#include "guicontroller.h"
#include "views/guiview.h"
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

    controller.launch();
    return application.exec();
}

