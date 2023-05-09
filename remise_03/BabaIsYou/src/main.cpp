#include "consolecontroller.h"
#include <iostream>
#include <QApplication>
#include "guiview.h"

using namespace std;


int main(int argc, char *argv[])
{
    //activate console launcher
    ConsoleController controller;
    controller.launch();

    //activate gui launcher
    /*QApplication application(argc, argv);
    GuiView window;
    window.show();
    return application.exec();*/
}

