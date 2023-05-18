#include "menuview.h"
#include "ui_menuview.h"

MenuView::MenuView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuView)
{
    ui->setupUi(this);
    connect(ui->btnStart, &QPushButton::clicked, this, &MenuView::startNewGame);
    connect(ui->btnLoad, &QPushButton::clicked, this, &MenuView::loadASave);
}

void MenuView::startNewGame(){

}
void MenuView::loadASave(){

}

MenuView::~MenuView()
{
    delete ui;
}
