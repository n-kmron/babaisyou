#include "wonview.h"
#include "ui_wonview.h"

WonView::WonView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WonView)
{
    ui->setupUi(this);
    connect(ui->btnExit, &QPushButton::clicked,&QCoreApplication::quit);
}

WonView::~WonView()
{
    delete ui;
}
