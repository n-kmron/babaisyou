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
    void displayHelp();
    void save();
    void restart();

private:
    Ui::GuiView *ui;

    QGraphicsScene scene_;

    GuiController* controller_;

    std::map<Element, QPixmap> images_;

    /**
     * @brief display the image corresponding to the element as parameter at the position given
     */
    void displayImage(const Element & elem, int height, int width);

    /**
     * @brief generate all images a single-time and store them in a map as QPixmap
     */
    std::map<Element, QPixmap> generateImages();

    /**
     * @brief ask the controller to load a save
     */
    void load(QString qName);

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

    void displayFinalWon();

    void displayNextLevel(unsigned int actualLevel);

    void displayKilled();

    /**
     * @brief asks user if he wants to overwrite a save
     */
    bool overwriteSave();

    void savedSuccessful();

    void savedFailed(std::string message);

    void editLevelLabel(unsigned int level);

    unsigned int displayUserSaves();

    void update(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements) override;
};

#endif // GUIVIEW_H
