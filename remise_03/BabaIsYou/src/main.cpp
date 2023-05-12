#include "consolecontroller.h"
#include "guicontroller.h"
#include "QtWidgets/qapplication.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    //activate gui or console launcher
    //ConsoleController controller;
    GuiController controller;

    controller.launch();
    return application.exec();
}

