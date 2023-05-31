#include "menuview.h"
#include "ui_menuview.h"

MenuView::MenuView(QWidget *parent, GuiView *view, GuiController* controller) :
    QWidget(parent),
    ui(new Ui::MenuView),
    view_ (view),
    controller_ (controller)
{
    ui->setupUi(this);
    connect(ui->btnStart, &QPushButton::clicked, this, &MenuView::startNewGame);
    connect(ui->btnLoad, &QPushButton::clicked, this, &MenuView::loadASave);
}

void MenuView::startNewGame(){
    this->close();
    controller_->launch();
}

void MenuView::loadASave(){
    this->close();
    controller_->launch();
    view_->displayUserSaves();
}

MenuView::~MenuView()
{
    delete ui;
}
