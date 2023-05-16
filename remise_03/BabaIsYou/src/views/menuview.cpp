#include "menuview.h"
#include "ui_menuview.h"

MenuView::MenuView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuView)
{
    ui->setupUi(this);
}

MenuView::~MenuView()
{
    delete ui;
}
