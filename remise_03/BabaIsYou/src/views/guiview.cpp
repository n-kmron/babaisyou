#include "guiview.h"
#include "../guicontroller.h"
#include "QtWidgets/qboxlayout.h"
#include "ui_guiview.h"
#include "../util.cpp"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "QtGui/qpixmap.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <limits>
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
    ui->myGraphicsView->setAlignment(Qt::AlignCenter);
    ui->myGraphicsView->fitInView(ui->myGraphicsView->sceneRect(), Qt::KeepAspectRatio);
    ui->myGraphicsView->setContentsMargins(0, 0, 0, 0);
    connect(ui->actionExit, &QAction::triggered, &QCoreApplication::quit);
    connect(ui->actionLoadGame, &QAction::triggered, this, &GuiView::displayUserSaves);
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
    //display main menu and close this window
}
void GuiView::save() {
    bool ok;
    string text = QInputDialog::getText(nullptr, "Save your game", "Enter a name for your save :", QLineEdit::Normal, "", &ok).toStdString();
    controller_->checkSave(text);
}

void GuiView::savedSuccessful() {
    QMessageBox::information(nullptr, "Saved successfuly", "The game has been saved.");
}

void GuiView::savedFailed(std::string message) {
    stringstream ss;
    ss << "The game was not saved : " << message;
    QString errorMessage = QString::fromStdString(ss.str());
    QMessageBox::information(nullptr, "Save failed" , errorMessage);
}

bool GuiView::overwriteSave() {
    QMessageBox messageBox;
    messageBox.setWindowTitle("Save already exists");
    messageBox.setText("Do you want to overwrite your save ?");

    QPushButton *acceptButton = messageBox.addButton("Yes, I'm sure", QMessageBox::AcceptRole);
    QPushButton *declineButton = messageBox.addButton("No", QMessageBox::RejectRole);

    messageBox.setDefaultButton(declineButton);
    messageBox.exec();

    if (messageBox.clickedButton() == acceptButton) {
        return true;
    }
    return false;
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
    QRect viewContentRect = ui->myGraphicsView->contentsRect();
    scene_.setSceneRect(viewContentRect);
}

void GuiView::displayFinalWon() {
    //close this window
    //new view for the final win
}

void GuiView::displayNextLevel(unsigned int actualLevel) {
    QMessageBox messageBox;
    messageBox.setWindowTitle("Congratulations!");
    messageBox.setText("You won the level! You go to the next level");
    messageBox.setIcon(QMessageBox::Information);
    messageBox.exec();
    editLevelLabel(actualLevel+1);
}

void GuiView::displayKilled() {
    QMessageBox messageBox;
    messageBox.setWindowTitle("Game Over");
    messageBox.setText("You lost the game");
    messageBox.setIcon(QMessageBox::Critical);
    messageBox.exec();
}

unsigned int GuiView::displayUserSaves() {
    filesystem::path path_to_saves("levels/saves");
    unsigned int numberSaves { 0 };

    QDialog dialog;
    dialog.setWindowTitle("Save Selection");
    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    for (const auto& entry : filesystem::directory_iterator(path_to_saves))
    {
        if (entry.is_regular_file())
        {
            string filename { entry.path().filename().string() };
            // Remove the double quotes if they exist.
            if (filename.front() == '"' && filename.back() == '"') {
                filename = filename.substr(1, filename.size() - 2);
            }

            // Remove the file extension.
            size_t extension_pos = filename.rfind('.');
            if (extension_pos != std::string::npos) {
                filename = filename.substr(0, extension_pos);
            }

            if(filename.size() != 0) {
                QLabel *label = new QLabel(QString::fromStdString(filename));
                QPushButton *button = new QPushButton("Load");

                QObject::connect(button, &QPushButton::clicked, [this, &dialog, label]() {
                    load(label->text());
                    dialog.accept();
                });

                QHBoxLayout *itemLayout = new QHBoxLayout;
                itemLayout->addWidget(label);
                itemLayout->addWidget(button);
                layout->addLayout(itemLayout);

                numberSaves++;
            }
        }
    }
    dialog.exec();
    return numberSaves;
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
            save();
            return true;
        }
    }
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

void GuiView::editLevelLabel(unsigned int level) {
    QString levelString = QString::number(level);
    ui->lbLevelCounter->setText(levelString);
}

void GuiView::load(QString qName) {
    string name = qName.toStdString();
    stringstream ss;
    ss << "saves/" << name;
    string filename = ss.str();
    controller_->chooseLevel(filename);
}

void GuiView::setController(GuiController* controller) {
    this->controller_ = controller;
}

GuiView::~GuiView()
{
    delete ui;
}
