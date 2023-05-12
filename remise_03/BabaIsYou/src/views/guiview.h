#ifndef GUIVIEW_H
#define GUIVIEW_H

#include "../model/observer.h"
#include <QMainWindow>
#include <QtWidgets/qgraphicsscene.h>
#include <QString>

namespace Ui {
    class GuiView;
}

class GuiController;

class GuiView : public QMainWindow, public Observer
{
    Q_OBJECT

private slots:
    void displayMenu();
    void displayHelp();
    void save();
    void loadSave();
    void restart();

private:
    Ui::GuiView *ui;

    QGraphicsScene scene_;

    GuiController* controller_;

    std::map<Element, QPixmap> images_;

    /**
     * @brief transform the game state from a vector<GameObject> by a 2d array
     */
    std::vector<std::vector<Element>> getPositionsMap(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements);

    void displayImage(const Element & elem, int height, int width);

    std::map<Element, QPixmap> generateImages();

protected:

    /**
     * @brief manage key events on the window
     */
    bool eventFilter(QObject *obj, QEvent *event) override;

public:
    explicit GuiView(QWidget *parent = nullptr);

    ~GuiView();

    void setController(GuiController* controller);

    void displayBoard(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements);

    void displayWon();

    void displayKilled();

    /**
     * @brief asks user if he wants to overwrite a save
     */
    bool overwriteSave();

    unsigned int displayUserSaves();

    void update(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements) override;
};

#endif // GUIVIEW_H
