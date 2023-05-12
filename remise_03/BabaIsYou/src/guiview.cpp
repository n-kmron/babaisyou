#include "guiview.h"
#include "ui_guiview.h"
#include "util.cpp"
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>

using namespace std;

GuiView::GuiView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiView),
    scene_ (this)
{
    ui->setupUi(this);
    ui->myGraphicsView->setScene(&scene_);
}

GuiView::~GuiView()
{
    delete ui;
}

void GuiView::displayTitle() {

}

void GuiView::displayBoard(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements) {
    vector<vector<Element>> positionsMap = getPositionsMap(sizes, elements);

    for(unsigned int height=0; height<sizes.first; ++height) {
        for(unsigned int width=0; width<sizes.second; ++width) {
            if(positionsMap.size() >= height && positionsMap.at(height).size() >= width) {
                QString pathToSprite = QString::fromStdString(Util::displayAsImage(positionsMap.at(height).at(width)));
                displayImage(pathToSprite, height, width);
            }
        }
    }
}

void GuiView::displayWon() {

}

void GuiView::displayNextLevel(unsigned int actualLevel) {

}

void GuiView::displayKilled() {

}

void GuiView::displayError(std::string message) {

}

bool GuiView::overwriteSave() {

}

unsigned int GuiView::displayUserSaves() {

}

std::string GuiView::askWhichLevel() {

}

std::string GuiView::askDir() {

}

bool GuiView::askRestart() {

}

void GuiView::askSave() {

}

void GuiView::update(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements){
    displayBoard(sizes, elements);
}


vector<vector<Element>> GuiView::getPositionsMap(const pair<unsigned int, unsigned int> & sizes, const vector<GameObject> & elements) {
    vector<vector<Element>> positionsMap(sizes.first, vector<Element>(sizes.second));
    for(unsigned int i=0; i<elements.size(); ++i) {
        GameObject current = elements.at(i);
        unsigned int row = current.pos().row();
        unsigned int col = current.pos().col();
        Element elem = current.element();
        if(positionsMap.at(row).at(col) != Element::NULLELEMENT) {
            if(Util::getZIndexOfElement(elem) > Util::getZIndexOfElement(positionsMap.at(row).at(col))) {
                positionsMap.at(row).at(col) = elem;
            }
        } else {
            positionsMap.at(row).at(col) = elem;
        }
    }

    return positionsMap;
}

void GuiView::displayImage(const QString& path, int height, int width) {
    QPixmap originalPixmap(path);
    QPixmap pixmap = originalPixmap.scaled(QSize(40, 40), Qt::KeepAspectRatio);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem();
    item->setPixmap(pixmap);
    qreal x = width * pixmap.width();
    qreal y = height * pixmap.height();
    item->setPos(x, y);
    scene_.addItem(item);
}
