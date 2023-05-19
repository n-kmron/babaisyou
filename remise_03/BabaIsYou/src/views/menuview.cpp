#include "menuview.h"
#include "ui_menuview.h"
#include "../guicontroller.h"
#include "guiview.h"

MenuView::MenuView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuView)
{
    ui->setupUi(this);
    connect(ui->btnStart, &QPushButton::clicked, this, &MenuView::startNewGame);
    connect(ui->btnLoad, &QPushButton::clicked, this, &MenuView::loadASave);
}

void MenuView::startNewGame(){
    this->close();
    //use the forward declaration
    GuiView* view = new GuiView();
    GuiController* controller = new GuiController(view);
    view->setController(controller);

    controller->launch();
}

void MenuView::loadASave(){

}

MenuView::~MenuView()
{
    delete ui;
}
