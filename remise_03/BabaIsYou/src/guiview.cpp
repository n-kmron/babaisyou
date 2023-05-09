#include "guiview.h"
#include "ui_guiview.h"

GuiView::GuiView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiView),
    scene_ (this)
{
    ui->setupUi(this);

    QRect viewContentsRect = ui->myGraphicsView->contentsRect() ;
    scene_.setSceneRect(viewContentsRect);
    ui->myGraphicsView->setScene(&scene_ );

    //add a rectangle
    scene_.addRect (20 ,20 ,100 ,100);
}

GuiView::~GuiView()
{
    delete ui;
}
