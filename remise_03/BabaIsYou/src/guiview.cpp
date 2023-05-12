#include "guiview.h"
#include "ui_guiview.h"
#include "util.cpp"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMessageBox>

using namespace std;

GuiView::GuiView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiView),
    scene_ (this)
{
    ui->setupUi(this);
    ui->myGraphicsView->setScene(&scene_);
    ui->myGraphicsView->installEventFilter(this);
    connect(ui->actionExit, &QAction::triggered, &QCoreApplication::quit);
    connect(ui->actionLoad_game, &QAction::triggered, this, &GuiView::loadASave);
    connect(ui->actionSave_game, &QAction::triggered, this, &GuiView::save);
    connect(ui->actionRestart, &QAction::triggered, this, &GuiView::restart);
    connect(ui->actionDisplay_help, &QAction::triggered, this, &GuiView::displayhelp);
    connect(ui->btnSave, &QPushButton::clicked, this, &GuiView::save);
    connect(ui->btnRestart, &QPushButton::clicked, this, &GuiView::restart);
}

GuiView::~GuiView()
{
    delete ui;
}

//Slots
void GuiView::save(){

}
void GuiView::displayhelp(){
    QString content=QObject::tr("<!DOCTYPE html>"
                                 "<html>"
                                 "<head>"
                                     "<meta charset=\"utf-8\">"
                                     "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
                                     "<title></title>"
                                 "</head>"
                                 "<body>"
                                     "<style>"
                                         "#basDroit{"
                                             "text-align:right;"
                                         "}"
                                     "</style>"
                                     "<div id=\"centre\">"
                                         "<p>Baba Is You est un jeu de type puzzle :</p>"
                                         "<br>"
                                         "<ul>"
                                             "<li>"
                                                 "Les règles sont directement sur le plateau;"
                                             "</li>"
                                             "<li>"
                                                 "Toute les objets sur la map peuvent potentielement être bougés;"
                                             "</li>"
                                             "<li>"
                                                 "Toute les objets sur la map peuvent potentielement être bougés;"
                                             "</li>"
                                         "</ul>"
                                         "<br>"
                                         "<p>"
                                             "Notez que n'importe quel objet peut incarner un autre objet(exemple:Rock Is Baba)."
                                         "</p>"
                                         "<br>"
                                         "<p>"
                                             "Veillez à sauvegarder votre avancement et n'oubliez pas que vous pouvez a n'importe quel moment restart le niveau dans le quel vous êtes."
                                         "</p>"
                                     "</div>"
                                     "<div id=\"basDroit\">"
                                         "<label><strong>Bon amusement!</strong></label>"
                                     "</div>"
                                 "</body>"
                                 "</html>");
    QMessageBox::information(this,"Help",content);
}
void GuiView::loadASave(){

}
void GuiView::restart(){

}
//Fin slots

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
    QPixmap pixmap = originalPixmap.scaled(QSize(30, 30), Qt::KeepAspectRatio);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem();
    item->setPixmap(pixmap);
    qreal x = width * pixmap.width();
    qreal y = height * pixmap.height();
    item->setPos(x, y);
    scene_.addItem(item);
}

bool GuiView::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Up || keyEvent->key() == Qt::Key_Z)
            {
                cout << "UP" << endl;
                return true; // Event handled
            }
            else if (keyEvent->key() == Qt::Key_Down || keyEvent->key() == Qt::Key_S)
            {
                cout << "DOWN" << endl;
                return true;
            }
            else if (keyEvent->key() == Qt::Key_Left || keyEvent->key() == Qt::Key_Q)
            {
                cout << "LEFT" << endl;
                return true;
            }
            else if (keyEvent->key() == Qt::Key_Right || keyEvent->key() == Qt::Key_D)
            {
                cout << "RIGHT" << endl;
                return true;
            }
            else if (keyEvent->key() == Qt::Key_R)
            {
                cout << "RESTART" << endl;
                return true;
            }
            else if (keyEvent->key() == Qt::Key_S && keyEvent->modifiers() == Qt::ShiftModifier)
            {
                cout << "SAVE" << endl;
                return true;
            }
        }
        else if (event->type() == QEvent::ShortcutOverride)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

            if (keyEvent->key() == Qt::Key_S && keyEvent->modifiers() == Qt::ShiftModifier)
            {
                cout << "SAVE" << endl;
                return true;
            }
        }

        // Call the base class implementation to handle other events
        return QMainWindow::eventFilter(obj, event);
}
