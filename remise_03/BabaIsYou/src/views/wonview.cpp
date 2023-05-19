#include "wonview.h"
#include "ui_wonview.h"

WonView::WonView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WonView)
{
    ui->setupUi(this);
    connect(ui->btnBackToTheMenu, &QPushButton::clicked, this, &WonView::displayMenu);
    connect(ui->btnExit, &QPushButton::clicked,&QCoreApplication::quit);
}

void WonView::displayMenu(){

}

WonView::~WonView()
{
    delete ui;
}
