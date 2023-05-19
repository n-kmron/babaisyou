//#include "consolecontroller.h"
#include "views/menuview.h"
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
    MenuView view;
    view.show();

    return application.exec();
}

