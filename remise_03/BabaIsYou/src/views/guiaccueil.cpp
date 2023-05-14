#include "guiaccueil.h"
#include "ui_guiaccueil.h"

GuiAccueil::GuiAccueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GuiAccueil)
{
    ui->setupUi(this);
    connect(ui->btnStart, &QPushButton::clicked, this, &GuiAccueil::startNewGame);
    connect(ui->btnLoad, &QPushButton::clicked, this, &GuiAccueil::loadASave);
}


void GuiAccueil::startNewGame(){

}
void GuiAccueil::loadASave(){

}


GuiAccueil::~GuiAccueil()
{
    delete ui;
}

