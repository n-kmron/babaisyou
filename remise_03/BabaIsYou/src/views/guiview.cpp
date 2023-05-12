#include "guiview.h"
#include "../guicontroller.h"
#include "ui_guiview.h"
#include "../util.cpp"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "QtGui/qpixmap.h"
#include <map>

using namespace std;

GuiView::GuiView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiView),
    scene_ (this),
    images_ { generateImages() }
{
    ui->setupUi(this);
    ui->myGraphicsView->setScene(&scene_);
    ui->myGraphicsView->installEventFilter(this);
    connect(ui->actionExit, &QAction::triggered, &QCoreApplication::quit);
    connect(ui->actionLoadGame, &QAction::triggered, this, &GuiView::loadSave);
    connect(ui->actionSaveGame, &QAction::triggered, this, &GuiView::save);
    connect(ui->actionRestart, &QAction::triggered, this, &GuiView::restart);
    connect(ui->actionBackToMenu, &QAction::triggered, this, &GuiView::displayMenu);
    connect(ui->actionDisplayHelp, &QAction::triggered, this, &GuiView::displayHelp);
    connect(ui->btnSave, &QPushButton::clicked, this, &GuiView::save);
    connect(ui->btnRestart, &QPushButton::clicked, this, &GuiView::restart);
}

void GuiView::displayMenu() {
    //display main menu and close this window
}

void GuiView::displayHelp() {
    //display help view
    //dans cette nouvelle vue, le html de reda
}

void GuiView::save() {
    //display save view
    //dans cette nouvelle vue, demander à l'utilisateur un nom pour sa sauvegarde et faire le check : si elle exite, demander si il veut écraser
    }
void GuiView::loadSave() {
    //display load view`
    //dans cette nouvelle vue, afficher toutes les sauvegardes et demander laquelle charger en cliquant dessus
}
void GuiView::restart() {
    controller_->restart();
}

void GuiView::displayBoard(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements) {
    vector<vector<Element>> positionsMap = getPositionsMap(sizes, elements);

    for(unsigned int height=0; height<sizes.first; ++height) {
        for(unsigned int width=0; width<sizes.second; ++width) {
            if(positionsMap.size() >= height && positionsMap.at(height).size() >= width) {
                displayImage(positionsMap.at(height).at(width), height, width);
            }
        }
    }
}

void GuiView::displayWon() {
    //juste une pop up pour dire vous avez gagné, si niveau<5 on continue, sinon on retourne au menu principal (ANGLAIS)
}

void GuiView::displayKilled() {
    //juste une pop up pour dire vous avez perdu, voulez-vous recommencer ce niveau ou quitter (ANGLAIS)
}

void GuiView::update(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements){
    scene_.clear();
    displayBoard(sizes, elements);
}

// PRIVATE FUNCTIONS ----------------

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

void GuiView::displayImage(const Element & elem, int height, int width) {
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem();
    QPixmap pixmap = images_[elem];
    item->setPixmap(pixmap);
    qreal x = width * pixmap.width();
    qreal y = height * pixmap.height();
    item->setPos(x, y);
    scene_.addItem(item);
}

bool GuiView::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        controller_->manageEvents(keyEvent);
        return true;
    }
    else if (event->type() == QEvent::ShortcutOverride)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_S && keyEvent->modifiers() == Qt::ShiftModifier)
        {
            //callSave controller
            return true;
        }
    }

        // Call the base class implementation to handle other events
        return QMainWindow::eventFilter(obj, event);
}

map<Element, QPixmap> GuiView::generateImages() {
    map<Element, QPixmap> elementImageMap;

    elementImageMap[Element::NULLELEMENT] = Util::displayAsImage(Element::NULLELEMENT);
    elementImageMap[Element::TEXT_BABA] = Util::displayAsImage(Element::TEXT_BABA);
    elementImageMap[Element::TEXT_WALL] = Util::displayAsImage(Element::TEXT_WALL);
    elementImageMap[Element::TEXT_ROCK] = Util::displayAsImage(Element::TEXT_ROCK);
    elementImageMap[Element::TEXT_LAVA] = Util::displayAsImage(Element::TEXT_LAVA);
    elementImageMap[Element::TEXT_GOOP] = Util::displayAsImage(Element::TEXT_GOOP);
    elementImageMap[Element::TEXT_FLAG] = Util::displayAsImage(Element::TEXT_FLAG);
    elementImageMap[Element::IS] = Util::displayAsImage(Element::IS);
    elementImageMap[Element::YOU] = Util::displayAsImage(Element::YOU);
    elementImageMap[Element::WIN] = Util::displayAsImage(Element::WIN);
    elementImageMap[Element::STOP] = Util::displayAsImage(Element::STOP);
    elementImageMap[Element::SINK] = Util::displayAsImage(Element::SINK);
    elementImageMap[Element::PUSH] = Util::displayAsImage(Element::PUSH);
    elementImageMap[Element::KILL] = Util::displayAsImage(Element::KILL);
    elementImageMap[Element::BABA] = Util::displayAsImage(Element::BABA);
    elementImageMap[Element::WALL] = Util::displayAsImage(Element::WALL);
    elementImageMap[Element::ROCK] = Util::displayAsImage(Element::ROCK);
    elementImageMap[Element::LAVA] = Util::displayAsImage(Element::LAVA);
    elementImageMap[Element::GRASS] = Util::displayAsImage(Element::GRASS);
    elementImageMap[Element::METAL] = Util::displayAsImage(Element::METAL);
    elementImageMap[Element::GOOP] = Util::displayAsImage(Element::GOOP);
    elementImageMap[Element::METAL] = Util::displayAsImage(Element::METAL);
    elementImageMap[Element::FLAG] = Util::displayAsImage(Element::FLAG);

    return elementImageMap;
}

void GuiView::setController(GuiController* controller) {
    this->controller_ = controller;
}

GuiView::~GuiView()
{
    delete ui;
}
