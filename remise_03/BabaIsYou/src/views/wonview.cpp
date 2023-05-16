#include "wonview.h"
#include "ui_wonview.h"

WonView::WonView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WonView)
{
    ui->setupUi(this);
}

WonView::~WonView()
{
    delete ui;
}
